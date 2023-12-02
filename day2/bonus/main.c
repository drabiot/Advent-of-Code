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

    fd = open("input.txt", O_RDONLY);
    line = get_next_line(fd);
    count = 0;
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
            else if (green < count_green(&line[i]))
                green = count_green(&line[i]);
            else if (blue < count_blue(&line[i]))
                blue = count_blue(&line[i]);
            i++;
        }
        printf("%s", line);
        printf("red : %d, green: %d, blue: %d\n", red, green, blue);
        count += red * blue * green;
        if (line)
            free(line);
        line = get_next_line(fd);
    }
    printf("Result: %d\n", count);
    close(fd);
}

/*int main()
{
    char *line = "Game 6: 3 red, 2 blue; 6 green, 13 blue; 11 blue, 1 red; 4 green, 3 red, 5 blue";
    int i = 0;
    int green = 0;
    while (line[i])
    {
        if (green < count_green(&line[i]))
            green = count_green(&line[i]);
        i++;
    }
    printf ("%d", green);
}*/