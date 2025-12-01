/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/04 00:25:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	is_asterisk(int c)
{
	if (c == '*')
		return (1);
	return (0);
}

static int	is_nb(char **map, int pos_x, int pos_y)
{
	int	i;
	int	j;
	int	count;
	int	tmp_count;
	int	nb;

	if (pos_y <= 0)
		j = pos_y;
	else
		j = pos_y - 1;
	count = 1;
	nb = 0;
	while (j <= pos_y + 1)
	{
		if (pos_x <= 0)
			i = pos_x;
		else
			i = pos_x - 1;
		while (i <= pos_x + 1)
		{
			tmp_count = 0;
			if (map[j][i] >= '0' && map[j][i] <= '9')
			{
				while (map[j][i] >= '0' && map[j][i] <= '9')
					i--;
				i++;
				while (map[j][i] >= '0' && map[j][i] <= '9')
				{
					tmp_count = (tmp_count * 10) + map[j][i] - '0';
					i++;
				}
				nb++;
			}
			if (tmp_count && nb <= 2)
			{
				printf("%d\n", tmp_count);
				count *= tmp_count;
			}
			if (nb > 2)
				return (0);
			i++;
		}
		j++;
	}
	if (nb != 2)
		return (0);
	else
		return (count);
}

int	travel_map(char **map)	
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (is_asterisk(map[j][i]))
				count += is_nb(map, i, j);
			i++;
		}
		j++;
	}
	return (count);
}
