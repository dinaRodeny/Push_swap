/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delroudi <delroudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 21:55:07 by user              #+#    #+#             */
/*   Updated: 2026/11/16 17:32:12 by delroudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
#include "libs/libft.h"
#include "libs/ft_printf.h"
typedef struct s_stack_node
{
    int value;
    int index;
    struct s_stack_node * next;
    struct s_stack_node * prev;
}t_stack_node;

t_stack_node	*create_node(int value);
void add_node_back(t_stack_node **stack, int value);
int	get_stack_size(t_stack_node *st);
void sa(t_stack_node **a);
void sb(t_stack_node **b);
void ss(t_stack_node **a, t_stack_node **b);
void pa(t_stack_node **a, t_stack_node **b);
void pb(t_stack_node **b, t_stack_node **a);
#endif