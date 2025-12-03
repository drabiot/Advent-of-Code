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
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			//zero
			if (s[i] == 'z' && s[i + 1] == 'e' && s[i + 2] == 'r' && s[i + 3] == 'o')
				return (0);
			//one
			if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
				return (1);
			//two
			if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
				return (2);
			//three
			if (s[i] == 't' && s[i + 1] == 'h' && s[i + 2] == 'r' && s[i + 3] == 'e' && s[i + 4] == 'e')
				return (3);
			//four
			if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'u' && s[i + 3] == 'r')
				return (4);
			//five
			if (s[i] == 'f' && s[i + 1] == 'i' && s[i + 2] == 'v' && s[i + 3] == 'e')
				return (5);
			//six
			if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'x')
				return (6);
			//seven
			if (s[i] == 's' && s[i + 1] == 'e' && s[i + 2] == 'v' && s[i + 3] == 'e' && s[i + 4] == 'n')
				return (7);
			//eight
			if (s[i] == 'e' && s[i + 1] == 'i' && s[i + 2] == 'g' && s[i + 3] == 'h' && s[i + 4] == 't')
				return (8);
			//nine
			if (s[i] == 'n' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'e')
				return (9);
		}
		else if (s[i] >= '0' && s[i] <= '9')
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
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			//zero
			if (s[i - 3] == 'z' && s[i - 2] == 'e' && s[i - 1] == 'r' && s[i] == 'o')
				return (0);
			//one
			if (s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'e')
				return (1);
			//two
			if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o')
				return (2);
			//three
			if (s[i - 4] == 't' && s[i - 3] == 'h' && s[i - 2] == 'r' && s[i - 1] == 'e' && s[i] == 'e')
				return (3);
			//four
			if (s[i - 3] == 'f' && s[i - 2] == 'o' && s[i - 1] == 'u' && s[i] == 'r')
				return (4);
			//five
			if (s[i - 3] == 'f' && s[i - 2] == 'i' && s[i - 1] == 'v' && s[i] == 'e')
				return (5);
			//six
			if (s[i - 2] == 's' && s[i - 1] == 'i' && s[i] == 'x')
				return (6);
			//seven
			if (s[i - 4] == 's' && s[i - 3] == 'e' && s[i - 2] == 'v' && s[i - 1] == 'e' && s[i] == 'n')
				return (7);
			//eight
			if (s[i - 4] == 'e' && s[i - 3] == 'i' && s[i - 2] == 'g' && s[i - 1] == 'h' && s[i] == 't')
				return (8);
			//nine
			if (s[i - 3] == 'n' && s[i - 2] == 'i' && s[i - 1] == 'n' && s[i] == 'e')
				return (9);
		}
		else if (s[i] >= '0' && s[i] <= '9')
			return (s[i] - '0');
		i--;
	}
	return (0);
}
