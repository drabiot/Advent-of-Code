/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/09 16:13:23 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.hpp"

int	main(void) {
	try {
		bsq data("input.txt");

		data.compute();
		PRINT GREEN "The biggest square is " YELLOW AND data.getResult() AND GREEN " long" CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
