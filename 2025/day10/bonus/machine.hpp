/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/10 20:05:05 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_HPP
# define MACHINE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <stdexcept>
# include <climits>
# include <cstdlib>
# include <map>


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

class Machines {
	private:
		struct Machine {
			std::vector<int> target;       // joltage target
			std::vector< std::vector<int> > buttons; // boutons: vecteurs d'incréments
		};

		std::vector<Machine> _machines;
		int _totalPresses;

		std::vector<int> parseTarget(const str &s);
		std::vector<int> parseButton(const str &s);
		void dfs(const std::vector< std::vector<int> > &buttons, const std::vector<int> &target, std::vector<int> &current, int idx, int pressesSoFar, int &minPress);

	public:
		Machines(str filename);
		~Machines();

		void compute();
		int getTotalPresses() const;
};

#endif //MACHINE_HPP