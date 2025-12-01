/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:04:17 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/07 13:36:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static size_t	count_word(char const *s, char sep)
{
	size_t	nb_word;

	nb_word = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			nb_word++;
		while (*s != sep && *s)
			s++;
	}
	return (nb_word);
}

static char	**fill_array(char const *s, char c, char **array)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			array[i] = ft_substr(s, 0, len);
			if (!array)
				free_array(array);
			i++;
			s += len;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = fill_array(s, c, array);
	return (array);
}
