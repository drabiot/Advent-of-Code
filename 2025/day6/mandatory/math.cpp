/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/06 13:25:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"

#include "math.hpp"
#include <sstream>
#include <fstream>

problem::problem(str filename)
    : _solution(0)
{
    std::ifstream file(filename.c_str());
    str line;

    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    while (std::getline(file, line)) {

        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        if (line.empty())
            continue;

        std::stringstream ss(line);
        int n;
        std::vector<int> row;

        while (ss >> n)
            row.push_back(n);

        if (!row.empty()) {
            this->_problems.push_back(row);
        }
        else {
            this->_type.clear();
            for (std::size_t i = 0; i < line.size(); ++i) {
                if (line[i] == '+' || line[i] == '*')
                    _type.push_back(line[i]);
}
        }
    }
}

problem::~problem() {}

void problem::checkProblem() {

    if (_problems.empty())
        return;

    std::size_t cols = _problems[0].size();
    std::size_t rows = _problems.size();

    for (std::size_t i = 0; i < cols; ++i) {
        char op = (i < _type.size()) ? _type[i] : '+';
        bool isAdd = (op == '+');

        long long result = _problems[0][i];

        for (std::size_t j = 1; j < rows; ++j) {
            if (isAdd)
                result += _problems[j][i];
            else
                result *= _problems[j][i];
        }

        PRINT MAGENTA AND result CENDL;
        _solution += result;
    }
}

long long problem::getSolution() {
    return _solution;
}

