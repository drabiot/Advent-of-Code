/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingredient.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/07 12:48:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingredient.hpp"

ingredient::ingredient(str filename) {
    this->_split = 0;
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
        else {
            _id.push_back(std::stoll(line));
        }

    }
}

ingredient::~ingredient() {}

void	ingredient::checkIngredient() {
    for (std::size_t i = 0; i < _id.size(); ++i) {
        long long   id = _id[i];
        bool        fresh = false;

        for (std::size_t j = 0; j < _range.size(); ++j) {
            long long a = _range[j].first;
            long long b = _range[j].second;

            if (id >= a && id <= b) {
                fresh = true;
                break;
            }
        }

        if (fresh)
            this->_freshIngredient++;
    }
}

long long	ingredient::getFreshIngredient() {
    return (this->_freshIngredient);
}
