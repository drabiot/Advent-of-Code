/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/04 15:48:01 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paper.hpp"

int	main(void) {
	try {
		int	nbPaper = checkPaper("input.txt");

		PRINT GREEN "There is " YELLOW AND nbPaper AND GREEN " rolls of paper that can be accessed by a forklift" CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
