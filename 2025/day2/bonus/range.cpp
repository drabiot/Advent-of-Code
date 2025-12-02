/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/02 23:59:55 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "range.hpp"

range::range(str filename) {
	this->_returnValue = 0;

	std::ifstream	file(filename);
	str				line;

	if (!file.is_open())
		throw std::runtime_error("Can't open file");

	std::getline(file, line);

	std::stringstream ss(line);
    std::string segment;

    while (std::getline(ss, segment, ',')) {
        std::stringstream	rangeStream(segment);
        long long			start, end;
        char				dash;
		
        rangeStream >> start >> dash >> end;
        this->_values.emplace_back(start, end);
    }
}

range::~range() {}


void range::checkRange() {
	for (size_t i = 0; i < _values.size(); ++i) {
		long long start = _values[i].first;
		long long end   = _values[i].second;

		for (long long n = start; n <= end; ++n) {
			std::string s = std::to_string(n);
			size_t len = s.size();

			bool isRepeated = false;
			for (size_t blockLen = 1; blockLen <= len / 2; ++blockLen) {
				if (len % blockLen != 0)
					continue;

				std::string block = s.substr(0, blockLen);
				bool valid = true;

				for (size_t pos = 0; pos < len; pos += blockLen) {
					if (s.substr(pos, blockLen) != block) {
						valid = false;
						break;
					}
				}

				if (valid) {
					isRepeated = true;
					break;
				}
			}

			if (isRepeated)
				this->_returnValue += n;
		}
	}
}




long long   range::getReturnValue(void) {
	return (this->_returnValue);
}
