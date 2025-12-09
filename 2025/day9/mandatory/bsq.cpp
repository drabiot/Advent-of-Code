/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:08:32 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/09 17:02:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.hpp"

bsq::bsq(str filename) : _result(0) {
	std::ifstream file(filename);
	
	if (!file.is_open())
		throw (std::runtime_error("Can't open file"));

	str	line;
	
	while (getline(file, line)) {
		std::stringstream ss(line);
		str firstStr, secondStr;

		
		if (!line.empty() && line.back() == '\r')
			line.pop_back();

		if (line.empty())
			continue;
		
		this->_tile.push_back(line);
	}
}

bsq::~bsq() {}

void bsq::compute() {
	for (int i = 0; i < static_cast<int>(this->_tile.size()); ++i) {
		for (int j = i + 1; j < static_cast<int>(this->_tile.size()); ++j) {
			std::stringstream ss1(this->_tile[i]);
			std::stringstream ss2(this->_tile[j]);
			str firstStr, secondStr, firstStrTest, secondStrTest;

			if (std::getline(ss1, firstStr, ',') && std::getline(ss1, secondStr, ',') && std::getline(ss2, firstStrTest, ',') && std::getline(ss2, secondStrTest, ',')) {
				long long width1  = std::atoll(firstStr.c_str());
				long long height1 = std::atoll(secondStr.c_str());
				long long width2  = std::atoll(firstStrTest.c_str());
				long long height2 = std::atoll(secondStrTest.c_str());

				long long	size = (std::abs(width1 - width2) + 1) * (std::abs(height1 - height2) + 1);
				if (size > this->_result)
					this->_result = size;
			}
		}
	}
}

long long bsq::getResult() {
    return (this->_result);
}
