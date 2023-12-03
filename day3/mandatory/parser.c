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

#include "main.h"

static int verif_symbol(char pos)
{
  if ((pos >= 33 && pos <= 45) || pos == 47 || (pos >= 61 && pos <= 64))
    return (1);
  return (0);
}

int search_symbol(char *buffer, int pos, int len)
{
  // behind
  if (!(pos <= 0))
  {
    if (verif_symbol(buffer[pos - 1]))
      return (1);
  }
  if (!(pos <= 10))
  {
    if (verif_symbol(buffer[pos - 140]))
      return (1);
  }
  if (!(pos <= 11))
  {
    if (verif_symbol(buffer[pos - 141]))
      return (1);
  }
  if (!(pos <= 12))
  {
    if (verif_symbol(buffer[pos - 142]))
      return (1);
  }
  // in front
  if (!(pos >= len))
  {
    if (verif_symbol(buffer[pos + 1]))
      return (1);
  }
  if (!(pos >= len - 12))
  {
    if (verif_symbol(buffer[pos + 140]))
      return (1);
  }
  if (!(pos >= len - 11))
  {
    if (verif_symbol(buffer[pos + 141]))
      return (1);
  }
  if (!(pos >= len - 10))
  {
    if (verif_symbol(buffer[pos + 142]))
      return (1);
  }
  return (0);
}