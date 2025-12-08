/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/08 22:10:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.hpp"

int	main(void) {
	try {
		light data("input.txt");

		data.compute();
		PRINT GREEN "Light: " YELLOW AND data.getResult() AND GREEN "" CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
