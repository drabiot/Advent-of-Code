/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:08:32 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/10 17:36:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.hpp"

static inline long long llmin(long long a, long long b) { return a < b ? a : b; }
static inline long long llmax(long long a, long long b) { return a > b ? a : b; }

bsq::bsq(str filename) : _result(0) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("Can't open file");

	str line;
	while (getline(file, line)) {
		if (!line.empty() && line.back() == '\r')
			line.pop_back();
		if (!line.empty())
			_tileLines.push_back(line);
	}

	for (auto &s : _tileLines) {
		std::stringstream ss(s);
		str xStr, yStr;
		if (getline(ss, xStr, ',') && getline(ss, yStr, ',')) {
			long long x = std::atoll(xStr.c_str());
			long long y = std::atoll(yStr.c_str());
			_redTiles.push_back({x, y});
		}
	}

	if (_redTiles.empty())
		return;

	if (_redTiles.front() != _redTiles.back())
		_redTiles.push_back(_redTiles.front());

	long long ymin = _redTiles[0][1];
	long long ymax = _redTiles[0][1];
	for (auto &p : _redTiles) {
		ymin = llmin(ymin, p[1]);
		ymax = llmax(ymax, p[1]);
	}

	PRINT RED "Gen Inside Tiles (SEGMENTS / SCANLINE + EDGES)" CENDL;

	for (size_t i = 0; i + 1 < _redTiles.size(); ++i) {
		const Pos &a = _redTiles[i];
		const Pos &b = _redTiles[i+1];

		if (a[1] == b[1]) {
			long long y = a[1];
			long long x1 = llmin(a[0], b[0]);
			long long x2 = llmax(a[0], b[0]);
			_greenSegments[y].push_back({x1, x2});
		} else if (a[0] == b[0]) {
			long long x = a[0];
			long long sy = llmin(a[1], b[1]);
			long long ey = llmax(a[1], b[1]);
			for (long long yy = sy; yy <= ey; ++yy)
				_greenSegments[yy].push_back({x, x});
		}
	}

	for (long long y = ymin; y <= ymax; ++y) {
		std::vector<long long> xs;

		for (size_t i = 0; i + 1 < _redTiles.size(); ++i) {
			const Pos& a = _redTiles[i];
			const Pos& b = _redTiles[i+1];

			if (a[0] == b[0]) {
				long long sy = llmin(a[1], b[1]);
				long long ey = llmax(a[1], b[1]);

				if (y >= sy && y < ey)
					xs.push_back(a[0]);
			}
		}

		if (xs.empty())
			continue;

		std::sort(xs.begin(), xs.end());

		for (size_t k = 0; k + 1 < xs.size(); k += 2) {
			long long x1 = xs[k];
			long long x2 = xs[k+1];
			if (x1 > x2) std::swap(x1, x2);
			_greenSegments[y].push_back({x1, x2});
		}
	}
	mergeAllSegments();
}

bsq::~bsq() {}

void bsq::mergeSegmentsForLine(long long y) {
	auto it = _greenSegments.find(y);
	if (it == _greenSegments.end()) return;
	auto &vec = it->second;
	if (vec.empty()) return;

	std::sort(vec.begin(), vec.end(), [](const std::pair<long long,long long>& a, const std::pair<long long,long long>& b){
		if (a.first != b.first) return a.first < b.first;
		return a.second < b.second;
	});

	std::vector<std::pair<long long,long long>> merged;
	merged.reserve(vec.size());
	long long curL = vec[0].first;
	long long curR = vec[0].second;

	for (size_t i = 1; i < vec.size(); ++i) {
		long long l = vec[i].first;
		long long r = vec[i].second;
		if (l <= curR + 1) {
			if (r > curR) curR = r;
		} else {
			merged.push_back({curL, curR});
			curL = l; curR = r;
		}
	}
	merged.push_back({curL, curR});
	vec.swap(merged);
}

void bsq::mergeAllSegments() {
	for (auto &p : _greenSegments) {
		mergeSegmentsForLine(p.first);
	}
}

bool bsq::isGreen(long long x, long long y) const {
	auto it = _greenSegments.find(y);
	if (it == _greenSegments.end())
		return false;

	const auto &vec = it->second;
	long long lo = 0, hi = (long long)vec.size() - 1;
	while (lo <= hi) {
		long long mid = (lo + hi) >> 1;
		if (x < vec[mid].first) {
			hi = mid - 1;
		} else if (x > vec[mid].second) {
			lo = mid + 1;
		} else {
			return true;
		}
	}
	return false;
}

bool bsq::valid(const Pos& a, const Pos& b) const {
	long long x1 = std::min(a[0], b[0]);
	long long x2 = std::max(a[0], b[0]);
	long long y1 = std::min(a[1], b[1]);
	long long y2 = std::max(a[1], b[1]);

	for (long long y = y1; y <= y2; ++y) {
		auto it = _greenSegments.find(y);
		if (it == _greenSegments.end())
			return false;

		const auto &vec = it->second;

		long long lo = 0, hi = (long long)vec.size() - 1;
		bool covered = false;
		while (lo <= hi) {
			long long mid = (lo + hi) >> 1;
			if (x2 < vec[mid].first) {
				hi = mid - 1;
			} else if (x1 > vec[mid].second) {
				lo = mid + 1;
			} else {
				if (vec[mid].first <= x1 && vec[mid].second >= x2) covered = true;
				break;
			}
		}
		if (!covered) return false;
	}

	return true;
}

void bsq::compute() {
	PRINT RED "Compute" CENDL;

	for (size_t i = 0; i < _redTiles.size(); ++i) {
		for (size_t j = i+1; j < _redTiles.size(); ++j) {
			const Pos& a = _redTiles[i];
			const Pos& b = _redTiles[j];

			long long size = (std::llabs(a[0]-b[0])+1) * (std::llabs(a[1]-b[1])+1);
			if (size > _result && valid(a,b))
				_result = size;
		}
	}
}

long long bsq::getResult() const {
	return _result;
}



