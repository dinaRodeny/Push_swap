/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:26:14 by user              #+#    #+#             */
/*   Updated: 2026/11/19 23:47:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	bubble_sort(t_stack_node **a)
{
	t_stack_node	*current;
	int				size;
	int				pass;
	int				comparisons;
	int				i;
	int				swapped;

	if (!a || !*a)
		return ;
	size = get_stack_size(*a);
	pass = 0;
	while (pass < size - 1)
	{
		comparisons = size - pass - 1;
		swapped = 0;
		i = 0;
		while (i < comparisons)
		{
			current = *a;
			if (current->value > current->next->value)
			{
				sa(a);
				swapped = 1;
			}
			ra(a);
			i++;
		}
		i = 0;
		while (i < comparisons)
		{
			rra(a);
			i++;
		}
		if (!swapped)
			break ;
		pass++;
	}
}

static void	assign_indexes(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*other;

	current = stack;
	while (current)
	{
		current->index = 0;
		other = stack;
		while (other)
		{
			if (other->value < current->value)
				current->index++;
			other = other->next;
		}
		current = current->next;
	}
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	int				size;
	int				max_index;
	int				bit_count;
	int				bit;
	int				i;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	size = get_stack_size(*a);
	if (size < 2)
		return ;
	assign_indexes(*a);
	max_index = 0;
	current = *a;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	bit_count = 0;
	while (max_index > 0)
	{
		bit_count++;
		max_index >>= 1;
	}
	bit = 0;
	while (bit < bit_count)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra(a);
			else
				pb(b, a);
			i++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}