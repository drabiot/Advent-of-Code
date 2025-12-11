/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/11 18:10:02 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

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
# include <unordered_map>
# include <unordered_set>


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

struct CacheKey {
	str node;
	bool hasDAC;
	bool hasFFT;

	CacheKey(str const& n, bool d, bool f) : node(n), hasDAC(d), hasFFT(f) {}

	bool operator==(const CacheKey& other) const {
		return node == other.node && hasDAC == other.hasDAC && hasFFT == other.hasFFT;
	}
};

struct CacheKeyHasher {
	std::size_t operator()(const CacheKey& key) const {
		return std::hash<str>()(key.node) ^ (key.hasDAC << 1) ^ (key.hasFFT << 2);
	}
};

class Server {
	public:
		Server(str filename);
		~Server(void);

		void		compute();
		long long	getPath();
	private:
		long long	Pathing(const str& node, bool hasDAC, bool hasFFT);

		std::unordered_map<str, std::vector<str>>				_servers;
		std::unordered_map<CacheKey, long long, CacheKeyHasher>	_cache;
		long long												_path;
};


#endif //SERVER_HPP