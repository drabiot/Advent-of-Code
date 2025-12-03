/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/04 06:18:07 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
	int		count;
	int		tmp_count;

    fd = open("input.txt", O_RDONLY);
    line = get_next_line(fd);
	count = 0;
    while (line)
    {
		tmp_count = create_nb(line);
		count += tmp_count;
		printf("%d\n", tmp_count);
        if (line)
            free(line);
        line = get_next_line(fd);
    }
    printf("Result: %d", count);
    close(fd);
}
