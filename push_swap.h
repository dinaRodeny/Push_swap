/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 21:55:07 by user              #+#    #+#             */
/*   Updated: 2026/11/19 20:12:18 by user             ###   ########.fr       */
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
#include <limits.h>
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
void		print_stack(t_stack_node *stack);
int		append_node(t_stack_node **stack, int value);
int		stack_init(t_stack_node **stack, int argc, char **argv);
int	get_stack_size(t_stack_node *st);
int		parse_number(const char *str, int *number);
int index_disorder(t_stack_node *stack);
void sa(t_stack_node **a);
void sb(t_stack_node **b);
void ss(t_stack_node **a, t_stack_node **b);
void pa(t_stack_node **a, t_stack_node **b);
void pb(t_stack_node **b, t_stack_node **a);
void ra(t_stack_node **a);
void rra(t_stack_node **a);
void rb(t_stack_node **b);
void rrb(t_stack_node **b);
void rrr(t_stack_node **a, t_stack_node **b);
void error_exit(t_stack_node **stack_a, t_stack_node  **stack_b);
int	is_duplicate_number(t_stack_node *stack);
void free_stack_nodes(t_stack_node **stack);
void bubble_sort(t_stack_node **a);
void radix_sort(t_stack_node **a, t_stack_node **b);
#endif
