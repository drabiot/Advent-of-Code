/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:08:04 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/11 18:09:19 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

Server::Server(str filename) : _path(0) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Can't open file");

	str	line;

	while (std::getline(file, line)) {

		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);

		if (line.empty())
			continue;

		str::size_type pos = line.find(':');
		if (pos == str::npos)
			continue;

		str	key = line.substr(0, pos);
		str	values = line.substr(pos + 1);

		while (!values.empty() && values[0] == ' ')
			values.erase(0, 1);

		std::vector<str>	vec;
		std::stringstream	ss(values);
		str					item;

		while (ss >> item)
			vec.push_back(item);

		this->_servers[key] = vec;
	}
}


Server::~Server() {}

long long Server::Pathing(const str& node, bool hasDAC, bool hasFFT) {
	CacheKey	key(node, hasDAC, hasFFT);
	auto		it = _cache.find(key);

	if (it != _cache.end())
		return (it->second);

	if (node == "dac")
		hasDAC = true;
	if (node == "fft")
		hasFFT = true;
	if (node == "out")
		return (hasDAC && hasFFT) ? 1 : 0;

	long long	count = 0;
	auto		it2 = _servers.find(node);
	
	if (it2 != _servers.end()) {
		for (auto& next : it2->second) {
			count += Pathing(next, hasDAC, hasFFT);
		}
	}

	this->_cache[key] = count;
	return (count);
}

void Server::compute() {
	this->_path = Pathing("svr", false, false);
}

long long	Server::getPath() {
	return (this->_path);
}
