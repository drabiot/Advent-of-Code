/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:49:21 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/11 17:26:55 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int main(void) {

    try {
        Server server("input.txt");

        server.compute();
        PRINT GREEN "Total of path: " YELLOW AND server.getPath() CENDL;
    } catch (const std::exception &e) {
        ERROR RED AND e.what() CENDL;
        return (1);
    }

    return (0);
}