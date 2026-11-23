/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delroudi <delroudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:45:45 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/16 17:20:07 by delroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	*stack = second;
	return (1);
}

void sa(t_stack_node **a, t_bench *bench)
{
	if (swap(a))
	{
		write(1,"sa\n",3);
		if (bench)
			bench->sa += 1;
	}
}

void sb(t_stack_node **b, t_bench *bench)
{
	if (swap(b))
	{
		write(1,"sb\n",3);
		if (bench)
			bench->sb += 1;
	}
}

void ss(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	did_a;
	int	did_b;

	did_a = swap(a);
	did_b = swap(b);
	if (did_a || did_b)
	{
		write(1,"ss\n",3);
		if (bench)
			bench->ss += 1;
	}
}
