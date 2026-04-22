/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:29:05 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* Declared in strategy.c */
const char	*strategy_name(t_strat flags, float disorder);

/*
** Prints benchmark statistics to stderr after sorting.
** Only called when --bench flag is present.
** Output format matches the subject specification.
*/
void	bench(float disorder, t_count_opers op, t_strat flags)
{
	dprintf(2, "[bench] disorder: %.2f%%\n", disorder * 100);
	dprintf(2, "[bench] strategy: %s\n", strategy_name(flags, disorder));
	dprintf(2, "[bench] total_ops: %d\n", op.all_op);
	dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		op.sa, op.sb, op.ss, op.pa, op.pb);
	dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		op.ra, op.rb, op.rr, op.rra, op.rrb, op.rrr);
}
