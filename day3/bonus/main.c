/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/04 00:26:15 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
	char	*map_line;
	char	**map;
	
	map_line = NULL;
    fd = open("input.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
		map_line = ft_strjoin(map_line, line);
        if (line)
            free(line);
        line = get_next_line(fd);
    }
	map = ft_split(map_line, '\n');
	printf("Result: %d", travel_map(map));
    close(fd);
}
