/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 21:12:04 by user              #+#    #+#             */
/*   Updated: 2026/11/19 23:34:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		ft_printf("Node %d: %d\n", i, stack->value);
		stack = stack->next;
		i++;
	}
}

static void	free_stack(char **values)
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
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


int	stack_init(t_stack_node **stack, int argc, char **argv)
{
	char	**values;
	int		i;
	int		j;
	int		value;

	if ( !argv || argc < 2)
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
			free_stack(values);
			return (0);
		}
		j = 0;
		while (values[j])
		{
			if (!parse_number(values[j], &value)
				|| !append_node(stack, value))
			{
				free_stack(values);
				return (0);
			}
			j++;
		}
		free_stack(values);
		i++;
	}
	if (is_duplicate_number(*stack))
		return (0);
	return (1);
}

int	append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (!stack)
		return (0);
	new = create_node(value);
	if (!new)
		return (0);
	if (*stack == NULL)
	{
		*stack = new;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (1);
}
int	get_stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack_nodes(t_stack_node **stack)
{
	t_stack_node *tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
