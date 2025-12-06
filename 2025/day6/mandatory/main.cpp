/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/06 12:23:38 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"

int	main(void) {
	try {
		problem data("input.txt");

		data.checkProblem();
		PRINT GREEN "The grand total found by adding together all of the answers is " YELLOW AND data.getSolution() CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
