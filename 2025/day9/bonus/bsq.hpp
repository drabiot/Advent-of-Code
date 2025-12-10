/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/10 17:35:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HPP
# define BSQ_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <cmath>
# include <stdexcept>
# include <stdlib.h>
# include <array>
# include <set>
# include <map>
# include <utility>

//COLOR
# define BASE_COLOR	"\033[0m"
# define GRAY 		"\033[0;90m"
# define RED 		"\033[0;91m"
# define GREEN 		"\033[0;92m"
# define YELLOW 	"\033[0;93m"
# define BLUE 		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN 		"\033[0;96m"
# define WHITE		"\033[0;97m"

# define AND	<<
# define PRINT	std::cout AND
# define ERROR	std::cerr AND
# define NLINE	PRINT std::endl
# define ENDL	AND std::endl
# define CENDL	AND BASE_COLOR ENDL
# define TAB	"\t"

typedef std::string str;

# define cref(type) const type &
# define ref(type) type &

using Pos = std::array<long long, 2>;
using Poly = std::vector<Pos>;


class bsq {
	public:
		explicit bsq(str filename);
		~bsq();

		void		compute();
		long long	getResult() const;

		bool		isGreen(long long x, long long y) const;
		bool		valid(const Pos& a, const Pos& b) const;

	private:
		std::vector<str> 													_tileLines;
		Poly																_redTiles;
		std::map<long long, std::vector<std::pair<long long,long long>>>	_greenSegments;
		long long	   													 	_result;

		void mergeSegmentsForLine(long long y);
		void mergeAllSegments();
};

#endif //BSQ_HPP