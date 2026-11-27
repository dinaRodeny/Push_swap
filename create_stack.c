/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 21:12:04 by user              #+#    #+#             */
/*   Updated: 2026/11/21 16:09:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		ft_printf("Node %d: %d (index %d)\n", i, stack->value,
			stack->index);
		stack = stack->next;
		i++;
	}
}

static void	free_values(char **values)
{
	int	i;

	i = 0;
	while (values && values[i])
		free(values[i++]);
	free(values);
}

t_stack_node	*create_node(int value)
{
	t_stack_node	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->rank = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static int	append_values(t_stack_node **stack, char **values)
{
	int	j;
	int	value;

	j = 0;
	while (values[j])
	{
		if (!parse_number(values[j], &value) || !append_node(stack, value))
			return (0);
		j++;
	}
	return (1);
}

int	stack_init(t_stack_node **stack, int argc, char **argv)
{
	char	**values;
	int		i;

	if (!stack || !argv || argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
		{
			i++;
			continue;
		}
		values = ft_split(argv[i], ' ');
		if (!values || !values[0])
		{
			free_values(values);
			return (0);
		}
		if (!append_values(stack, values))
		{
			free_values(values);
			return (0);
		}
		free_values(values);
		i++;
	}
	if (is_duplicate_number(*stack))
		return (0);
	return (*stack != NULL);
}
