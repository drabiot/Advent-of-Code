/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:57:26 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/10 20:07:22 by tchartie         ###   ########.fr       */
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
        if (line.empty()) continue;

        Machine m;

        // parse buttons
        size_t pos = line.find(']');
        if (pos == str::npos) continue;
        pos++;

        size_t start, end;
        while ((start = line.find('(', pos)) != str::npos) {
            end = line.find(')', start);
            if (end == str::npos) break;
            str btn = line.substr(start + 1, end - start - 1);
            m.buttons.push_back(parseButton(btn));
            pos = end + 1;
        }

        // parse target
        start = line.find('{');
        end = line.find('}');
        if (start != str::npos && end != str::npos && end > start) {
            str tgt = line.substr(start + 1, end - start - 1);
            m.target = parseTarget(tgt);
        }

        _machines.push_back(m);
    }
}

Machines::~Machines() {}

std::vector<int> Machines::parseTarget(const str &s) {
    std::vector<int> target;
    std::stringstream ss(s);
    str num;
    while (std::getline(ss, num, ',')) {
        target.push_back(std::atoi(num.c_str()));
    }
    return target;
}

std::vector<int> Machines::parseButton(const str &s) {
    std::vector<int> btn;
    std::stringstream ss(s);
    str num;
    while (std::getline(ss, num, ',')) {
        btn.push_back(std::atoi(num.c_str()));
    }
    return btn;
}

// DFS exact avec memoization
int dfsExact(const std::vector< std::vector<int> > &buttons,
             const std::vector<int> &remaining,
             std::map< std::vector<int>, int > &memo)
{
    if (memo.count(remaining))
        return memo[remaining];

    bool done = true;
    for (size_t i = 0; i < remaining.size(); ++i)
        if (remaining[i] > 0) { done = false; break; }

    if (done) return 0;

    int minPress = INT_MAX;

    for (size_t b = 0; b < buttons.size(); ++b) {
        // déterminer le max de presses utile pour ce bouton
        int max_press = 0;
        for (size_t i = 0; i < buttons[b].size(); ++i) {
            int idx = buttons[b][i];
            if (idx < (int)remaining.size())
                max_press = std::max(max_press, remaining[idx]);
        }
        if (max_press == 0) continue; // bouton inutile

        // essayer de presser ce bouton de 1 à max_press fois
        for (int k = 1; k <= max_press; ++k) {
            std::vector<int> next = remaining;
            for (size_t i = 0; i < buttons[b].size(); ++i) {
                int idx = buttons[b][i];
                if (idx < (int)next.size())
                    next[idx] -= k;
            }
            int press = dfsExact(buttons, next, memo);
            if (press != INT_MAX && press + k < minPress)
                minPress = press + k;
        }
    }

    memo[remaining] = minPress;
    return minPress;
}

void Machines::compute() {
    _totalPresses = 0;

    for (size_t m = 0; m < _machines.size(); ++m) {
		PRINT MAGENTA "start machine nb " RED AND m CENDL;

        const Machine &mach = _machines[m];
        std::map< std::vector<int>, int > memo;
        int presses = dfsExact(mach.buttons, mach.target, memo);

		PRINT GREEN "finish machine nb " YELLOW AND m AND " " MAGENTA AND presses CENDL;
        _totalPresses += presses;
    }
}

int Machines::getTotalPresses() const {
    return _totalPresses;
}



