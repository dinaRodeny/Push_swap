/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-leo <erde-leo@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:10:14 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/21 15:15:20 by erde-leo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder_pct(t_stack_node *stack)
{
	int		size;
	double	inversions;
	double	total_pairs;

	size = get_stack_size(stack);
	if (size < 2)
		return (0.0);
	inversions = (double)index_disorder(stack);
	total_pairs = ((double)size * ((double)size - 1.0)) / 2.0;
	return ((inversions / total_pairs) * 100.0);
}

int index_disorder(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*other;
	int 			disorder;

	current = stack;
	disorder = 0;
	while (current)
	{
		other = current->next;
		while (other)
		{
			if (current->value > other->value)
				disorder++;
			other = other->next;
		}
		current = current->next;
	}
	return (disorder);
}
