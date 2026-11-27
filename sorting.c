/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:26:14 by user              #+#    #+#             */
/*   Updated: 2026/11/27 15:10:00 by user             ###   ########.fr       */
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

static void	assign_ranks(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*other;

	current = stack;
	while (current)
	{
		current->rank = 0;
		other = stack;
		while (other)
		{
			if (other->value < current->value)
				current->rank++;
			other = other->next;
		}
		current = current->next;
	}
}

static void	sort_three(t_stack_node **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->rank;
	second = (*a)->next->rank;
	third = (*a)->next->next->rank;
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third)
		rra(a, bench);
}

static void	move_rank_to_b(t_stack_node **a, t_stack_node **b, int size,
		int rank, t_bench *bench)
{
	t_stack_node	*current;
	int				position;

	current = *a;
	position = 0;
	while (current && current->rank != rank)
	{
		current = current->next;
		position++;
	}
	if (position <= size / 2)
		while (position-- > 0)
			ra(a, bench);
	else
		while (position++ < size)
			rra(a, bench);
	pb(b, a, bench);
}

static void	sort_small(t_stack_node **a, t_stack_node **b, int size,
		t_bench *bench)
{
	int	rank;

	if (size == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			sa(a, bench);
		return ;
	}
	rank = 0;
	while (size > 3)
	{
		move_rank_to_b(a, b, size, rank, bench);
		size--;
		rank++;
	}
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}

static void	push_chunks(t_stack_node **a, t_stack_node **b, int chunk_size,
		t_bench *bench)
{
	int	next_rank;

	next_rank = 0;
	while (*a)
	{
		if ((*a)->rank <= next_rank)
		{
			pb(b, a, bench);
			rb(b, bench);
			next_rank++;
		}
		else if ((*a)->rank <= next_rank + chunk_size)
		{
			pb(b, a, bench);
			next_rank++;
		}
		else
			ra(a, bench);
	}
}

static void	push_back_sorted(t_stack_node **a, t_stack_node **b, int size,
		t_bench *bench)
{
	t_stack_node	*current;
	int				rank;
	int				position;
	int				stack_size;
	int				i;

	rank = size - 1;
	while (*b)
	{
		current = *b;
		position = 0;
		while (current && current->rank != rank)
		{
			current = current->next;
			position++;
		}
		stack_size = get_stack_size(*b);
		if (position <= stack_size / 2)
		{
			i = 0;
			while (i++ < position)
				rb(b, bench);
		}
		else
		{
			i = position;
			while (i++ < stack_size)
				rrb(b, bench);
		}
		pa(a, b, bench);
		rank--;
	}
}

void	chunk_sort(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;
	int	chunk_size;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	size = get_stack_size(*a);
	assign_ranks(*a);
	if (size <= 5)
	{
		sort_small(a, b, size, bench);
		return ;
	}
	chunk_size = size / 15;
	if (chunk_size < 15)
		chunk_size = 15;
	push_chunks(a, b, chunk_size, bench);
	push_back_sorted(a, b, size, bench);
}

void	radix_sort(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;
	int	max_rank;
	int	bit_count;
	int	bit;
	int	i;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	size = get_stack_size(*a);
	assign_ranks(*a);
	max_rank = size - 1;
	bit_count = 0;
	while (max_rank > 0)
	{
		bit_count++;
		max_rank >>= 1;
	}
	bit = 0;
	while (bit < bit_count)
	{
		i = 0;
		while (i++ < size)
		{
			if (((*a)->rank >> bit) & 1)
				ra(a, bench);
			else
				pb(b, a, bench);
		}
		while (*b)
			pa(a, b, bench);
		bit++;
	}
}
