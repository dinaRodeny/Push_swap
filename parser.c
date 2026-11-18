/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-leo <erde-leo@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 10:53:22 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/17 10:53:27 by erde-leo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  is_nbr(char *str)
{
  int  i;

  if (!str)
    return (0);

  i = 0;
  if (str[i] == '+' || str[i] == '-')
  {
    i++;
    if (str[i] == '\0')
      return (0);
  }
  while (str[i] != '\0')
  {
    if (str[i] < '0' || str[i] > '9' ) 
      return (0);
    else
      i++;
  }
  return (1);
}

static int	check_duplicate(t_stack_node *stack, int nbr)
{
  t_stack_node  *current;

  current = stack;
  while (current != NULL)
  {
    if (current->value == nbr)
      return (1);
    else
      current = current->next;
  }
  return (0);
}
