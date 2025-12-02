/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/02 20:16:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "range.hpp"

int	main(void) {
	try {
		range	data("input.txt");
		data.checkRange();

		PRINT GREEN "The return value is: " YELLOW AND data.getReturnValue() CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
