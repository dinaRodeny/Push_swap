/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-leo <erde-leo@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:52:20 by erde-leo          #+#    #+#             */
/*   Updated: 2026/11/23 14:52:24 by erde-leo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	if (!bench)
		return ;
	bench->enabled = 0;
	bench->disorder = 0.0;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	detect_bench_flag(int argc, char **argv, t_bench *bench)
{
	int	i;

	if (!argv || !bench)
		return ;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
		{
			bench->enabled = 1;
			return ;
		}
		i++;
	}
}