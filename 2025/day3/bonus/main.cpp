/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/03 12:03:13 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "batteries.hpp"

int	main(void) {
	try {
		unsigned long long	joltage = checkVoltage("input.txt");

		PRINT GREEN "The return value is: " YELLOW AND joltage CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
