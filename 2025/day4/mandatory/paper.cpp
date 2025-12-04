/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paper.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:17:21 by drabiot           #+#    #+#             */
/*   Updated: 2025/12/04 16:27:06 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paper.hpp"

int checkPaper(str filename) {
    std::ifstream file(filename);
    str line;

    if (!file.is_open())
        throw std::runtime_error("Can't open file");

    int total = 0;

    std::vector<str>    map;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        if (line.empty())
            continue;

        map.push_back(line);
    }

    for (int i = 0; i < static_cast<int>(map.size()); ++i) {
        for (int j = 0; j < static_cast<int>(map[i].length()); ++j) {
            int paperAround = 0;
            
            if (map[i][j] != '@') {
                if (map[i][j] == '.')
                    PRINT YELLOW "." BASE_COLOR;
                continue;
            }

            //check top
            if (i > 0)
                if (map[i - 1][j] == '@')
                    paperAround++;
            //check bottom
            if (i < static_cast<int>(map.size()) - 1)
                if (map[i + 1][j] == '@')
                    paperAround++;
            //check left
            if (j > 0)
                if (map[i][j - 1] == '@')
                    paperAround++;
            //check right
            if (j < static_cast<int>(map[i].length()) - 1)
                if (map[i][j + 1] == '@')
                    paperAround++;


            //check top left
            if (i > 0 && j > 0)
                if (map[i - 1][j - 1] == '@')
                    paperAround++;
            //check top right
            if (i > 0 && j < static_cast<int>(map[i].length()) - 1)
                if (map[i - 1][j + 1] == '@')
                    paperAround++;
            //check bottom left
            if (i < static_cast<int>(map.size()) - 1 && j > 0)
                if (map[i + 1][j - 1] == '@')
                    paperAround++;
            //check bottom right
            if (i < static_cast<int>(map.size()) - 1 && j < static_cast<int>(map[i].length()) - 1)
                if (map[i + 1][j + 1] == '@')
                    paperAround++;
            
            if (paperAround < 4)
                total++;

            //debug
            if (map[i][j] == '.')
                PRINT YELLOW "." BASE_COLOR;
            if (map[i][j] == '@' && paperAround < 4)
                PRINT RED "x" BASE_COLOR;
            else
                PRINT MAGENTA "@" BASE_COLOR;
        }
        NLINE;
    }

    return (total);
}

