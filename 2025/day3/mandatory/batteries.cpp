/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batteries.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/03 10:01:43 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "batteries.hpp"

int checkVoltage(str filename) {
    std::ifstream file(filename);
    str line;

    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    long long total = 0;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        if (line.empty())
            continue;

        std::vector<int> digits;
        for (char c : line) {
            if (std::isdigit(static_cast<unsigned char>(c)))
                digits.push_back(c - '0');
        }

        if (digits.size() < 2)
            continue;

        int best = 0;

        for (size_t i = 0; i < digits.size(); ++i) {
            for (size_t j = i + 1; j < digits.size(); ++j) {
                int value = digits[i] * 10 + digits[j];
                if (value > best)
                    best = value;
            }
        }

        total += best;
    }

    return static_cast<int>(total);
}

