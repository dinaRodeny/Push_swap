/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-leo <erde-leo@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:17:24 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/21 16:45:30 by erde-leo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack_node **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

static void	sort_three(t_stack_node **a, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if (index_disorder(*a) == 0)
		return ;
	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top > bot)
		ra(a, bench);
	else if (mid > top && mid > bot)
		rra(a, bench);
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

static int	find_min_pos(t_stack_node *stack)
{
	int				min_val;
	int				min_pos;
	int				pos;
	t_stack_node	*cur;

	min_val = stack->value;
	min_pos = 0;
	pos = 0;
	cur = stack;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static void	bring_min_to_top(t_stack_node **a, int size, t_bench *bench)
{
	int	min_pos;
	int	moves;

	min_pos = find_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, bench);
	}
	else
	{
		moves = size - min_pos;
		while (moves-- > 0)
			rra(a, bench);
	}
}

void	sort_up_to_five(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;

	if (!a || !*a)
		return ;
	if (index_disorder(*a) == 0)
		return ;
	size = get_stack_size(*a);
	if (size == 2)
		sort_two(a, bench);
	else if (size == 3)
		sort_three(a, bench);
	else
	{
		while (size > 3)
		{
			bring_min_to_top(a, size, bench);
			pb(b, a, bench);
			size--;
		}
		sort_three(a, bench);
		while (b && *b)
			pa(a, b, bench);
	}
}

void	algo_adaptive(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int			size;
	long long	disorder;
	long long	max_pairs;

	if (!a || !b || !*a)
		return ;
	size = get_stack_size(*a);
	if (size < 2)
		return ;
	if (index_disorder(*a) == 0)
		return ;
	if (size <= 5)
	{
		sort_up_to_five(a, b, bench);
		return ;
	}
	else
	{
		disorder = index_disorder(*a);
		max_pairs = ((long long)size * (size - 1)) / 2;
		if (disorder * 100 <= max_pairs * 20)
			selection_sort(a, b, bench);
		else if (disorder * 100 <= max_pairs * 60)
			chunk_sort(a, b, bench);
		else
			radix_sort(a, b, bench);
	}
	return ;
}
