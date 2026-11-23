/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-leo <erde-leo@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:01:16 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/23 13:01:20 by erde-leo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder_stderr(double disorder)
{
	int	whole;
	int	hundredths;

	if (disorder < 0.0)
		disorder = 0.0;
	whole = (int)disorder;
	hundredths = (int)((disorder - (double)whole) * 100.0 + 0.5);
	if (hundredths >= 100)
	{
		whole += 1;
		hundredths = 0;
	}
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (hundredths < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(hundredths, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_single_op(const char *name, int count)
{
	ft_putstr_fd("  ", 2);
	ft_putstr_fd((char *)name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_ops_breakdown_stderr(t_bench *bench)
{
	ft_putstr_fd("Operations:\n", 2);
	print_single_op("sa", bench->sa);
	print_single_op("sb", bench->sb);
	print_single_op("ss", bench->ss);
	print_single_op("pa", bench->pa);
	print_single_op("pb", bench->pb);
	print_single_op("ra", bench->ra);
	print_single_op("rb", bench->rb);
	print_single_op("rr", bench->rr);
	print_single_op("rra", bench->rra);
	print_single_op("rrb", bench->rrb);
	print_single_op("rrr", bench->rrr);
}

void    print_bench(t_bench *bench, const char *strategy, const char *complex)
{
    int total;
    
    if (!bench || !bench->enabled)
        return ;
	total = bench->sa + bench->sb + bench->ss
		+ bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr;
	ft_putstr_fd("=== BENCHMARK ===\n", 2);
	ft_putstr_fd("strategy: ", 2);
	ft_putstr_fd((char *)strategy, 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd((char *)complex, 2);
	ft_putstr_fd(")\n", 2);
	print_disorder_stderr(bench->disorder);
	ft_putstr_fd("total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_ops_breakdown_stderr(bench);
}