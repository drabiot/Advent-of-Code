/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batteries.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/03 12:27:44 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "batteries.hpp"

static unsigned long long max12Digits(const std::vector<int> &digits, size_t count) {
    std::vector<int> result;
    size_t start = 0;

    while (result.size() < count) {
        int maxDigit = -1;
        size_t maxPos = start;
        for (size_t i = start; i <= digits.size() - (count - result.size()); ++i) {
            if (digits[i] > maxDigit) {
                maxDigit = digits[i];
                maxPos = i;
            }
        }
        result.push_back(maxDigit);
        start = maxPos + 1;
    }

    unsigned long long value = 0;
    for (int d : result)
        value = value * 10 + d;

    return value;
}

unsigned long long checkVoltage(str filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    unsigned long long total = 0;
    str line;
   
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();

        std::vector<int> digits;
        for (char c : line)
            if (isdigit(c)) digits.push_back(c - '0');

        if (digits.size() < 12) continue;

        total += max12Digits(digits, 12);
}

    return total;
}
