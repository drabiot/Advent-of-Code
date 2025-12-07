/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beam.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/07 13:43:26 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEAM_HPP
# define BEAM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <set>
# include <algorithm>

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

class	beam {
	public:
		beam(str filename);
		~beam(void);

		void		checkBeam(void);
		long long	getSplit(void);

	private:
		std::vector<str>	_tp;
		std::vector<int>	_beam;
		std::vector<int>	_newBeam;
		long long			_split;
};

#endif //BEAM_HPP