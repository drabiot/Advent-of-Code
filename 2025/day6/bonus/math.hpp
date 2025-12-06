/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/06 17:59:54 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_HPP
# define MATH_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>

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
class problem {

public:

    problem(str filename);
    ~problem();

    void        checkProblem();
    long long   getSolution();

private:

    // --- stockage des colonnes de chiffres
    std::vector<std::vector<long long>> _problems;      // chaque colonne -> vecteur de chiffres
    std::vector<std::vector<long long>> _cephNumbers; // colonne -> vecteur de nombres
    std::vector<char> _type;                        // opérateurs par colonne
    long long _solution;

    // helper (optionnel)
    long long columnToNumber(const std::vector<int> &col) const;
};

#endif //MATH_HPP