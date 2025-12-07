/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/07 13:38:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beam.hpp"

int	main(void) {
	try {
		beam data("input.txt");

		data.checkBeam();
		PRINT GREEN "There is a total of " YELLOW AND data.getSplit() AND GREEN " different timeline" CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
