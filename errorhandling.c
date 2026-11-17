/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:21:56 by user              #+#    #+#             */
/*   Updated: 2026/11/17 23:27:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack_node **stack_a, t_stack_node  **stack_b)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
int	is_duplicate_number(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*other;

	current = stack;
	while (current)
	{
		other = current->next;
		while (other)
		{
			if (current->value == other->value)
				return (1);
			other = other->next;
		}
		current = current->next;
	}
	return (0);
}
