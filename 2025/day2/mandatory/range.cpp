/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/02 23:18:24 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "range.hpp"

long long	stringHalf(long long num, bool type);

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


void    range::checkRange() {
	for (size_t i = 0; i < _values.size(); ++i) {
		long long	firstRange  = stringHalf(_values[i].first, false);
		long long	secondRange = stringHalf(_values[i].second, true);
		
		std::vector<long long>	generated;
		for (long long j = firstRange; j <= secondRange; ++j) {
            generated.push_back(j);
        }

        for (long long n : generated) {
            std::string s = std::to_string(n);
            s += s;

            long long v = std::stoll(s);
            if (v >= _values[i].first && v <= _values[i].second)
				this->_returnValue += v;
        }

	}
}

long long   range::getReturnValue(void) {
	return (this->_returnValue);
}

long long	stringHalf(long long num, bool type) {
	std::string s = std::to_string(num);
	size_t halfLen = s.size() / 2;
	
	if (halfLen == 0)
		return (0);
	
	if (s.size() % 2 != 0 && type)
		return (std::stoll(s.substr(0, halfLen + 1)));
	return (std::stoll(s.substr(0, halfLen)));
}