/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:49:21 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/10 19:51:10 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.hpp"

int main(void) {

    try {
        Machines machines("input.txt");

        machines.compute();
        PRINT GREEN "Minimum total presses: " YELLOW AND machines.getTotalPresses() CENDL;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}