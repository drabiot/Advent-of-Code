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

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int     red;
    int     green;
    int     blue;
    int     i;
    int     count;

    fd = open("input.txt", O_RDONLY);
    line = get_next_line(fd);
    count = 0;
    if (argc != 4)
        return (0);
    while (line)
    {
        i = 0;
        red = 0;
        green = 0;
        blue = 0;
        while (line[i])
        {
            if (red < count_red(&line[i]))
                red = count_red(&line[i]);
            if (green < count_green(&line[i]))
                green = count_green(&line[i]);
            if (blue < count_blue(&line[i]))
                blue = count_blue(&line[i]);
            i++;
        }
        printf("red : %d, green: %d, blue: %d\n", red, green, blue);
        if (red <= atoi(argv[1]) && green <= atoi(argv[2]) && blue <= atoi(argv[3]))
            {
                printf("good line: %d\n", count_line(line));
                count += count_line(line);
            }
        if (line)
            free(line);
        line = get_next_line(fd);
    }
    printf("Result: %d\n", count);
    close(fd);
}