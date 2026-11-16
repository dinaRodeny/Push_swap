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

void sa(t_stack_node **a)
{
	if (swap(a)) //Si el swap se hace con éxito
		write(1,"sa\n",3);  //imprimimos la instrucción
}

void sb(t_stack_node **b)
{
	if (swap(b)) //Si el swap se hace con éxito
		write(1,"sb\n",3);  //imprimimos la instrucción
}

void ss(t_stack_node **a, t_stack_node **b)
{
	if (swap(a) || swap(b)) //Si el swap se hace con éxito
		write(1,"ss\n",3);  //imprimimos la instrucción
}

	
