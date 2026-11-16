/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delroudi <delroudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:57:42 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/16 18:04:36 by delroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  rotate(t_stack_node **stack)
{
  t_stack_node  *first;
  t_stack_node  *last;

  if (!stack || !*stack || !(*stack)->next) //empty or with just 1 element, doesn´t work
		return (0);
  first = *stack;
  last = *stack; //finding the last node of the list
  while (last->next != NULL)
      last = last->next;
  *stack = first->next; //second node becomes the head
  (*stack)->prev = NULL;
  last->next = first; //first becomes last
  first->prev = last;
  first->next = NULL;
  return (1);
}

void  ra(t_stack_node **a)
{
  if (rotate (a))
    write (1, "ra\n", 3);
}

void  rb(t_stack_node **b)
{
  if (rotate (b))
    write (1, "rb\n", 3);
}

void  rr(t_stack_node **a, t_stack_node **b)
{
  if (rotate (a) || rotate (b))
    write (1, "rr\n", 3);
}