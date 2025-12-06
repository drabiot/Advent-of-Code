/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/06 18:09:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"

problem::problem(str filename) : _solution(0) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    std::vector<str> lines;
    str line;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (!line.empty())
            lines.push_back(line);
    }

    if (lines.empty())
        return;

    str opLine = lines.back();
    lines.pop_back();

    size_t nCols = opLine.size();

    _cephNumbers.clear();
    _cephNumbers.resize(nCols);

    for (size_t c = 0; c < nCols; ++c) {
        std::vector<long long> numbers;
        long long current = 0;
        bool inNumber = false;

        for (size_t r = 0; r < lines.size(); ++r) {
            char ch = (c < lines[r].size()) ? lines[r][c] : ' ';
            if (isdigit(ch)) {
                current = current * 10 + (ch - '0');
                inNumber = true;
            } else {
                if (inNumber) {
                    numbers.push_back(current);
                    current = 0;
                    inNumber = false;
                }
            }
        }
        if (inNumber)
            numbers.push_back(current);

        _cephNumbers[c] = numbers;
    }

    _problems.clear();
    _type.clear();
    size_t idx = 0;

    while (idx < nCols) {
        if (_cephNumbers[idx].empty()) {
            ++idx;
            continue;
        }

        size_t start = idx;
        while (idx < nCols && !_cephNumbers[idx].empty())
            ++idx;
        size_t end = idx;

        std::vector<long long> problemVec;
        for (size_t c = start; c < end; ++c) {
            long long colValue = 0;
            const std::vector<long long> &col = _cephNumbers[c];
            for (size_t i = 0; i < col.size(); ++i)
                colValue = colValue * 10 + col[i];
            problemVec.push_back(colValue);
        }

        _problems.push_back(problemVec);

        for (size_t c = start; c < end; ++c) {
            if (opLine[c] == '+' || opLine[c] == '*') {
                _type.push_back(opLine[c]);
                break;
            }
        }
    }
}

problem::~problem() {}

void problem::checkProblem() {
    long long total = 0;

    for (size_t i = 0; i < _problems.size(); ++i) {
        long long result = _problems[i][0];
        char op = (i < _type.size()) ? _type[i] : '+';
        bool isAdd = (op == '+');

        for (size_t j = 1; j < _problems[i].size(); ++j) {
            if (isAdd)
                result += _problems[i][j];
            else
                result *= _problems[i][j];
        }

        total += result;
    }

    _solution = total;
}

long long problem::getSolution() {
    return (this->_solution);
}