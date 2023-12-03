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

#include "main.h"
#include <stdio.h>

int main()
{
  int	fd;
  char	*buffer;
  int	i;
  int	len;
  int	count;
  int tmpcount;

  buffer = (char *)malloc(sizeof(char) * (19882));
  fd = open("input.txt", O_RDONLY);
  read(fd, buffer, 100000);
  buffer[19881] = '\0';
  i = 0;
  len = 19881;
  count = 0;
  while (buffer[i])
  {
    if (buffer[i] >= '0' && buffer[i] <= '9')
    {
        if (search_symbol(buffer, i, len))
        {
            printf("POS: %c, len: %d\n", buffer[i], i);
		    tmpcount = 0;
            if (buffer[i] >= '0' && buffer[i] <= '9')
            {
                while (buffer[i] >= '0' && buffer[i] <= '9')
                    i--;
                i++;
                while (buffer[i] >= '0' && buffer[i] <= '9')
                {
                    tmpcount = tmpcount * 10 + (buffer[i] - '0');
                    i++;	
                }
            }
            count += tmpcount;
        }
    }
    i++;
  }
	printf("%d" , count);
}