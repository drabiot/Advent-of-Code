/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:01:56 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/01 13:01:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_HPP
# define PASSWORD_HPP

# include <string>
# include <iostream>
# include <fstream>
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

template <typename T>
class Node {
    public:
        T data;
		Node<T>* prev = nullptr;
        Node<T>* next = nullptr;
};

class password {
	public:
		password(int size);
		~password(void);

		void	append(int value);
		void	readInput(str filename);
		void	useInput(void);

		int		getPassword(void);

	private:
		Node<int>*			_dial;
		Node<int>*			_tail;
		Node<int>*			_current;
		std::vector<str>	_input;
		int					_password;
};

#endif //PASSWORD_HPP
