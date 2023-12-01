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

/*
 * Take a string and find out what the first digit of it is
 */

int	search_first_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (s[i] - '0');
		i++;
	}
	return (0);
}

/*
 * Take a string and find out what the last digit of it is
 */

int	search_last_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (s[i] - '0');
		i--;
	}
	return (0);
}