/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/07 13:14:25 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beam.hpp"

int	main(void) {
	try {
		beam data("input.txt");

		data.checkBeam();
		PRINT GREEN "The beam is splitted a total of " YELLOW AND data.getSplit() AND GREEN " times" CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
