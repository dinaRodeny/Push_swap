/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 21:55:07 by user              #+#    #+#             */
/*   Updated: 2026/11/21 16:09:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "libs/libft.h"
# include "libs/ft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					rank;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

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

t_stack_node	*create_node(int value);
int				append_node(t_stack_node **stack, int value);
int				stack_init(t_stack_node **stack, int argc, char **argv);
int				get_stack_size(t_stack_node *stack);
int				parse_number(const char *str, int *number);
int				index_disorder(t_stack_node *stack);
int				is_duplicate_number(t_stack_node *stack);
void			print_stack(t_stack_node *stack);
void			sa(t_stack_node **a, t_bench *bench);
void			sb(t_stack_node **b, t_bench *bench);
void			ss(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			pa(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			pb(t_stack_node **b, t_stack_node **a, t_bench *bench);
void			ra(t_stack_node **a, t_bench *bench);
void			rra(t_stack_node **a, t_bench *bench);
void			rb(t_stack_node **b, t_bench *bench);
void			rrb(t_stack_node **b, t_bench *bench);
void			rr(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			rrr(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			error_exit(t_stack_node **a, t_stack_node **b);
void			free_stack_nodes(t_stack_node **stack);
void			sort_up_to_five(t_stack_node **a, t_stack_node **b,
					t_bench *bench);
void			algo_adaptive(t_stack_node **a, t_stack_node **b,
					t_bench *bench);
void			chunk_sort(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			radix_sort(t_stack_node **a, t_stack_node **b,
					t_bench *bench);
double			calc_disorder_pct(t_stack_node *stack);
void			print_bench(t_bench *bench, const char *strategy,
					const char *complex);
void			init_bench(t_bench *bench);
void			detect_bench_flag(int argc, char **argv, t_bench *bench);
#endif
