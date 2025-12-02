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
	try {
		
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	PRINT GREEN "The return value is: " YELLOW AND "?" CENDL;

	return (0);
}
