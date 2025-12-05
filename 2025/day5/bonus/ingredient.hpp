/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingredient.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/05 14:36:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INGREDIENT_HPP
# define INGREDIENT_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <vector>
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

class	ingredient {
	public:
		ingredient(str filename);
		~ingredient(void);

		void		checkIngredient(void);
		long long	getFreshIngredient(void);

	private:
		std::vector<std::pair<long long, long long>>	_range;
		long long										_freshIngredient;
};

#endif //INGREDIENT_HPP