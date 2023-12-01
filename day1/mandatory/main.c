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

int main(void)
{
    int     fd;
    char    *line;
    int     ret;
    int     tmp_calc;

    fd = open("input.txt", O_RDONLY);
    line = get_next_line(fd);
    ret = 0;
    tmp_calc = 0;
    while (line)
    {
        tmp_calc = (search_first_digit(line) * 10) + search_last_digit(line);
        ret += tmp_calc;
        if (line)
            free(line);
        printf("%d\n", tmp_calc);
        line = get_next_line(fd);
    }
    printf("Result: %d", ret);
    close(fd);
}