/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/08 22:19:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_HPP
# define LIGHT_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <cmath>
# include <tuple>
# include <stdexcept>

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

using pt = std::tuple<long double, long double, long double>;

class light {
public:
    light(str filename);
    ~light();

    void		compute();
    long long	getResult() const;

private:
	std::vector<str>	_raw;
	std::vector<pt>		_pts;
	std::vector<int>	_rep;
    int					_n;
    long long			_result;

    pt			parseTuple(str s);
    long double	getDist(const pt &a, const pt &b);
    int			find(int i);
    bool		merge(int i, int j);
};

#endif //LIGHT_HPP