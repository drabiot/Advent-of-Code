/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:56:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/05 14:05:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingredient.hpp"

int	main(void) {
	try {
		ingredient data("input.txt");

		data.checkIngredient();
		PRINT GREEN "There is " YELLOW AND data.getFreshIngredient() AND GREEN " available fresh ingredient" CENDL;
	} catch (const std::exception &e) {
		ERROR RED "Error: " AND e.what() CENDL;
	}

	return (0);
}
