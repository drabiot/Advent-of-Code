/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/20 16:24:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_red(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] < 'a' || str[i] > 'z')
		i++;
	if (str[i] == 'r' && str[i + 1] == 'e' && str[i + 2] == 'd')
	{
		i--;
		while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
			i--;
		while (str[i] < '0' || str[i] > '9')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			count = (10 * count) + (str[i] - '0');
			i++;
		}
	}
	return (count);
}

int	count_green(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] < 'a' || str[i] > 'z')
		i++;
	if (str[i] == 'g' && str[i + 1] == 'r' && str[i + 2] == 'e' && str[i + 3] == 'e' && str[i + 4] == 'n')
	{
		i--;
		while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
			i--;
		while (str[i] < '0' || str[i] > '9')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			count = (10 * count) + (str[i] - '0');
			i++;
		}
	}
	return (count);
}

int	count_blue(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] < 'a' || str[i] > 'z')
		i++;
	if (str[i] == 'b' && str[i + 1] == 'l' && str[i + 2] == 'u' && str[i + 3] == 'e')
	{
		i--;
		while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
			i--;
		while (str[i] < '0' || str[i] > '9')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			count = (10 * count) + (str[i] - '0');
			i++;
		}
	}
	return (count);
}

int	count_line(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] < '0' || str[i] > '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = (10 * count) + (str[i] - '0');
		i++;
	}
	return (count);
}