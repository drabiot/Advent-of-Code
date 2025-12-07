/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beam.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/07 13:51:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beam.hpp"

beam::beam(str filename) {
    std::ifstream file(filename.c_str());
    str line;

    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    while (std::getline(file, line)) {

        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        if (line.empty())
            continue;

        this->_tp.push_back(line);
    }
    for (size_t i = 0; i < this->_tp[0].size(); ++i) {
        if (this->_tp[0][i] == 'S')
            this->_beam.push_back(i);
    }
}

beam::~beam() {}

void beam::checkBeam() {
    int size = this->_tp.size();
    if (!size)
        return;

    int sizeLine = this->_tp[0].size();

    int srcRow = -1, srcCol = -1;
    for (int r = 0; r < size; r++) {
        size_t pos = this->_tp[r].find('S');
        if (pos != std::string::npos) {
            srcRow = r;
            srcCol = (int)pos;
            break;
        }
    }
    if (srcCol < 0)
        return;

    std::vector<long long> dp(sizeLine, 0);
    dp[srcCol] = 1;

    for (int r = srcRow; r + 1 < size; r++) {

        std::vector<long long> next(sizeLine, 0);

        for (int c = 0; c < sizeLine; c++) {
            if (dp[c] == 0) continue;

            char cell = this->_tp[r+1][c];

            if (cell == '^') {
                if (c - 1 >= 0)
                    next[c - 1] += dp[c];
                if (c + 1 < sizeLine)
                    next[c + 1] += dp[c];

                this->_split += dp[c];
            }
            else {
                next[c] += dp[c];
            }
        }

        dp.swap(next);
    }

    long long totalUnivers = 0;
    for (int c = 0; c < sizeLine; c++)
        totalUnivers += dp[c];

    this->_split = totalUnivers;
}



long long beam::getSplit() {
    return (this->_split);
}

