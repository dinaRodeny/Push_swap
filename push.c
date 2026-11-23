/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delroudi <delroudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:57:17 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/16 18:01:53 by delroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  push(t_stack_node **dst, t_stack_node **src)
{
  t_stack_node  *node_to_push; //variable temp to save first node in A

  if (!src || !*src)
      return (0);
  /*Take first node in src*/
	node_to_push = *src;
  *src = (*src)->next;
	if (*src) //If src is not empty
		(*src)->prev = NULL;
  /*if dest is empty*/
  if (!*dst)
  {
    *dst = node_to_push;
    node_to_push->next = NULL;
    node_to_push->prev = NULL;
  }
  else //if dst is not empty
  {
    node_to_push->next = *dst;
    (*dst)->prev = node_to_push;
    node_to_push->prev = NULL;
    *dst = node_to_push;
  }
  return (1);
}

void pa(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	if (push(a, b))
	{
		write(1,"pa\n",3);
		if (bench)
			bench->pa += 1;
	}
}

void pb(t_stack_node **b, t_stack_node **a, t_bench *bench)
{
	if (push(b, a))
	{
		write(1,"pb\n",3);
		if (bench)
			bench->pb += 1;
	}
}
