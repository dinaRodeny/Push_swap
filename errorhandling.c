/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:21:56 by user              #+#    #+#             */
/*   Updated: 2026/11/19 22:35:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack_node **stack_a, t_stack_node  **stack_b)
{
	if (stack_a != NULL)
		free_stack_nodes(stack_a);
	if (stack_b != NULL)
		free_stack_nodes(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	parse_number(const char *str, int *number)
{
	long	value;
	long	limit;
	int		digit;
	int		sign;

	value = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	limit = INT_MAX;
	if (sign == -1)
		limit = (long)INT_MAX + 1;
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		digit = *str - '0';
		if (value > (limit - digit) / 10)
			return (0);
		value = value * 10 + digit;
		str++;
	}
	*number = (int)(value * sign);
	return (1);
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
