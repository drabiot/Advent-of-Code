/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/01 12:56:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password.hpp"

int	main(void) {
	password data(99);

	try {
		data.readInput("input.txt");
		data.useInput();
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	PRINT GREEN "The Password is: " YELLOW AND data.getPassword() CENDL;

	return (0);
}
