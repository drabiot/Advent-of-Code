/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:08:32 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/08 22:24:04 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.hpp"

using pt = std::tuple<long double, long double, long double>;

light::light(str filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw (std::runtime_error("Can't open file"));

    str line;
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;
        _raw.push_back(line);
    }

    _n = _raw.size();
    _rep.resize(_n);
    for (int i = 0; i < _n; ++i)
        _rep[i] = i;

    _pts.reserve(_n);
    for (auto &s : _raw)
        _pts.push_back(parseTuple(s));
}

light::~light() {}

pt light::parseTuple(str s) {
    int x, y, z;
    if (sscanf(s.c_str(), "%d,%d,%d", &x, &y, &z) != 3)
		throw (std::runtime_error("Invalid line: " + s));
	return (std::make_tuple((long double)x, (long double)y, (long double)z));
}

long double light::getDist(const pt &a, const pt &b) {
    long double dx = std::get<0>(a) - std::get<0>(b);
    long double dy = std::get<1>(a) - std::get<1>(b);
    long double dz = std::get<2>(a) - std::get<2>(b);
	
    return (sqrt(dx*dx + dy*dy + dz*dz));
}

int light::find(int i) {
    if (_rep[i] != i)
        _rep[i] = find(_rep[i]);
    return (_rep[i]);
}

bool light::merge(int i, int j) {
    int r1 = find(i);
    int r2 = find(j);
    if (r1 == r2)
		return (false);
    if (r1 < r2)
        _rep[r2] = r1;
    else
        _rep[r1] = r2;
    return (true);
}

void light::compute() {
    std::vector<std::tuple<long double,int,int>> distances;
    for (int i = 0; i < _n; ++i) {
        for (int j = i+1; j < _n; ++j) {
            distances.emplace_back(getDist(_pts[i], _pts[j]), i, j);
        }
    }

    std::sort(distances.begin(), distances.end());

    int components = _n;
    int last_i = -1, last_j = -1;

	for (size_t t = 0; t < distances.size(); ++t) {
		auto &tuple_ = distances[t];
		int i = std::get<1>(tuple_);
		int j = std::get<2>(tuple_);

		if (merge(i, j)) {
			last_i = i;
			last_j = j;
			components--;
			if (components == 1)
				break;
		}
	}

    long long x1 = static_cast<long long>(std::get<0>(_pts[last_i]));
    long long x2 = static_cast<long long>(std::get<0>(_pts[last_j]));
    _result = x1 * x2;
}


long long light::getResult() const {
    return (this->_result);
}
