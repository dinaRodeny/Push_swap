/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 21:12:04 by user              #+#    #+#             */
/*   Updated: 2026/11/17 23:05:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

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
void add_node_back(t_stack_node **stack, int value)
{
    t_stack_node *new;
    t_stack_node *last;

    new = create_node(value);
    if (!new)
        return ;
    if (*stack == NULL)
    {
        *stack = new;
		return ;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
	new->prev = last;

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

void	free_stack(t_stack_node  **stack)
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
