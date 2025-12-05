/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingredient.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/05 14:46:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingredient.hpp"

ingredient::ingredient(str filename) {
    this->_freshIngredient = 0;
    bool    isIds = false;

    std::ifstream file(filename);
    str line;

    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        if (line.empty()) {
            isIds = true;
            continue;
        }

        if (!isIds) {
            std::size_t pos = line.find('-');

            long long a = std::stoll(line.substr(0, pos));
            long long b = std::stoll(line.substr(pos + 1));

            _range.push_back(std::make_pair(a, b));
        }
    }
}

ingredient::~ingredient() {}

void	ingredient::checkIngredient() {
    std::vector<std::pair<long long, long long> > merged = _range;

    std::sort(merged.begin(), merged.end());

    std::vector<std::pair<long long, long long> > compact;
    compact.push_back(merged[0]);

    for (std::size_t i = 1; i < merged.size(); ++i) {
        long long a = merged[i].first;
        long long b = merged[i].second;

        long long &lastB = compact.back().second;

        if (a <= lastB + 1) {
            if (b > lastB)
                lastB = b;
        }
        else
            compact.push_back(std::make_pair(a, b));
    }

    long long total = 0;
    for (std::size_t i = 0; i < compact.size(); ++i)
        total += (compact[i].second - compact[i].first + 1);

    this->_freshIngredient = total;
}

long long	ingredient::getFreshIngredient() {
    return (this->_freshIngredient);
}
