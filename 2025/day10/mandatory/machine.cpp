/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:42:03 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/10 19:51:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.hpp"

Machines::Machines(str filename) : _totalPresses(0) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    str line;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        if (line.empty())
			continue;

        size_t	start = line.find('[');
        size_t	end = line.find(']');

        if (start == str::npos || end == str::npos)
			continue;
        str diagram = line.substr(start + 1, end - start - 1);

        Machine	m;
        m.target = parseLights(diagram);

        size_t	pos = end + 1;
        while ((start = line.find('(', pos)) != str::npos) {
            end = line.find(')', start);
            if (end == str::npos)
				break;
			
            str btn = line.substr(start + 1, end - start - 1);
            m.buttons.push_back(parseButton(btn));
            pos = end + 1;
        }

        this->_machines.push_back(m);
    }
}

Machines::~Machines() {}

int Machines::parseLights(const str &s) {
    int mask = 0;

    for (size_t i = 0; i < s.size(); ++i)
        if (s[i] == '#')
			mask |= (1 << i);

    return (mask);
}

int Machines::parseButton(const str &s) {
    int					mask = 0;
    std::stringstream	ss(s);
    str					num;

    while (std::getline(ss, num, ','))
        mask |= (1 << std::atoi(num.c_str()));

    return (mask);
}

int Machines::minPresses(int target, const std::vector<int> &buttons) {
    int	n = buttons.size();
    int	minPress = INT_MAX;

    for (int comb = 0; comb < (1 << n); ++comb) {
        int state = 0, presses = 0;
        for (int i = 0; i < n; ++i) {
            if (comb & (1 << i)) {
                state ^= buttons[i];
                ++presses;
            }
        }
        if (state == target && presses < minPress)
            minPress = presses;
    }
    return (minPress);
}

void Machines::compute() {
    for (size_t i = 0; i < _machines.size(); ++i)
        this->_totalPresses += minPresses(_machines[i].target, _machines[i].buttons);
}

int Machines::getTotalPresses() const {
    return (this->_totalPresses);
}
