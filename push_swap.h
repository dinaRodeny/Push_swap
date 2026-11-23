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
# include <limits.h>

typedef struct s_stack_node
{
    int value;
    int index;
    struct s_stack_node * next;
    struct s_stack_node * prev;
}t_stack_node;

typedef struct s_bench
{
	int		enabled;
	double	disorder;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

t_stack_node    *create_node(int value);
int    append_node(t_stack_node **stack, int value);
int    stack_init(t_stack_node **stack, int argc, char **argv);
int    get_stack_size(t_stack_node *st);
int    parse_number(const char *str, int *number);
int    index_disorder(t_stack_node *stack);
int    is_duplicate_number(t_stack_node *stack);
int    find_min_pos(t_stack_node *stack);
void    print_stack(t_stack_node *stack);
void    sa(t_stack_node **a);
void    sb(t_stack_node **b);
void    ss(t_stack_node **a, t_stack_node **b);
void    pa(t_stack_node **a, t_stack_node **b);
void    pb(t_stack_node **b, t_stack_node **a);
void    ra(t_stack_node **a);
void    rra(t_stack_node **a);
void    rb(t_stack_node **b);
void    rrb(t_stack_node **b);
void    rrr(t_stack_node **a, t_stack_node **b);
void    error_exit(t_stack_node **stack_a, t_stack_node  **stack_b);
void    free_stack_nodes(t_stack_node **stack);
void	sort_two(t_stack_node **a);
void	sort_three(t_stack_node **a);
void	bring_min_to_top(t_stack_node **a, int size);
void	sort_up_to_five(t_stack_node **a, t_stack_node **b);
void	algo_adaptive(t_stack_node **a, t_stack_node **b);
void    bubble_sort(t_stack_node **a);
void    medium * missing
void    radix_sort(t_stack_node **a, t_stack_node **b);
#endif
