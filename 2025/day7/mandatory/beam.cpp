/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beam.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/07 13:33:28 by tchartie         ###   ########.fr       */
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
        this->_tpBeam.push_back(line);
    }
    for (size_t i = 0; i < this->_tp[0].size(); ++i) {
        if (this->_tp[0][i] == 'S')
            this->_beam.push_back(i);
    }
}

beam::~beam() {}

void beam::checkBeam() {
    for (size_t i = 1; i + 1 < this->_tp.size(); ++i) {

        std::sort(this->_beam.begin(), this->_beam.end());
        this->_beam.erase(std::unique(this->_beam.begin(), this->_beam.end()), this->_beam.end());

        for (size_t b = 0; b < this->_beam.size(); ++b) {
            int col = this->_beam[b];

            this->_tpBeam[i][col] = '|';

            if (this->_tp[i+1][col] == '^') {
                this->_newBeam.push_back(col-1);
                this->_newBeam.push_back(col+1);
                this->_split++;
            } else {
                this->_newBeam.push_back(col);
            }
        }
        std::sort(this->_newBeam.begin(), this->_newBeam.end());
        this->_newBeam.erase(std::unique(this->_newBeam.begin(), this->_newBeam.end()), this->_newBeam.end());

        this->_beam = this->_newBeam;
        this->_newBeam.clear();
    }

    // debug drawing
    for (auto &row : this->_tpBeam)
        PRINT MAGENTA AND row CENDL;
}

long long beam::getSplit() {
    return (this->_split);
}

