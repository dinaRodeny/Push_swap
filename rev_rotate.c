/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delroudi <delroudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:55:15 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/16 18:02:41 by delroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  rev_rotate(t_stack_node **stack)
{
	t_stack_node  *tail;
  	t_stack_node  *old_head;

  	if (!stack || !*stack || !(*stack)->next) //empty or with just 1 element, doesn´t work
		return (0);
  	old_head = *stack;
  	tail = *stack; //finding the last node once
  	while (tail->next != NULL)
    	tail = tail->next;
	tail->prev->next = NULL; //disconnect the last node from the penultimate
	tail->next = old_head; //put the last node to the head
	old_head->prev = tail;
	tail->prev = NULL;
	*stack = tail; //update the head
	  return (1);
}

void  rra(t_stack_node **a)
{
  if (rev_rotate (a))
    write (1, "rra\n", 4);
}

void  rrb(t_stack_node **b)
{
  if (rev_rotate (b))
    write (1, "rrb\n", 4);
}

void  rrr(t_stack_node **a, t_stack_node **b)
{
  if (rev_rotate (a) || rev_rotate (b))
    write (1, "rrr\n", 4);
}