/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:42:03 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/11 17:39:09 by tchartie         ###   ########.fr       */
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

void	Server::compute() {
	Pathing("you");
}

void Server::Pathing(str node) {
	if (node == "out") {
		_path++;
		return;
	}

	std::map<str, std::vector<str> >::iterator it = _servers.find(node);

	if (it == _servers.end())
		return;

	const std::vector<str> &next = it->second;

	for (size_t i = 0; i < next.size(); ++i) {
		Pathing(next[i]);
	}
}

long long	Server::getPath() {
	return (this->_path);
}
