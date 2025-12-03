/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/04 06:24:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_nb(char *line, int nb)
{
	int	i;
	int	count;

	i = 0;
	while (line[i] != '|')
		i++;
	while (line[i])
	{
		count = 0;
		while (line[i] >= '0' && line[i] <= '9')
		{
			count = (count * 10) + line[i] - '0';
			i++;
		}
		if (count == nb)
			return (1);
		i++;
	}
	return (0);
}

int	create_nb(char *line)
{
	int	i;
	int	count;
	int	win;

	i = 0;
	win = 0;
	while (line[i] != ':')
		i++;
	while (line[i] != '|')
	{
		count = 0;
		while (line[i] >= '0' && line[i] <= '9')
		{
			count = (count * 10) + line[i] - '0';
			i++;
		}
		if (count && search_nb(line, count))
		{
			if (win > 1)
				win *= 2;
			else
				win++;
		}
		i++;
	}
	return (win);
}
