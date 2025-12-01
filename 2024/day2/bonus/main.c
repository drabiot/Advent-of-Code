/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/20 16:24:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int     fd;
    char    *line;
    int     red;
    int     green;
    int     blue;
    int     i;
    int     count;
    int     tmp_count;

    fd = open("input.txt", O_RDONLY);
    line = get_next_line(fd);
    count = 0;
    while (line)
    {
        i = 0;
        red = 0;
        green = 0;
        blue = 0;
        tmp_count = 0;
        while (line[i])
        {
            if (red < count_red(&line[i - 3]))
                red = count_red(&line[i - 3]);
            else if (green < count_green(&line[i - 3]))
                green = count_green(&line[i - 3]);
            else if (blue < count_blue(&line[i - 3]))
                blue = count_blue(&line[i - 3]);
            i++;
        }
        tmp_count = red * blue * green;
        printf("red : %d, green: %d, blue: %d,\tpower: %d\n", red, green, blue, tmp_count);
        count += tmp_count;
        if (line)
            free(line);
        line = get_next_line(fd);
    }
    printf("Result: %d\n", count);
    close(fd);
}