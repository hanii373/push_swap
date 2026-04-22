/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:22 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the name string of the active strategy for --bench output.
** Used only by bench.c.
*/
const char	*strategy_name(t_strat flags, float disorder)
{
	if (flags.simple)
		return ("Simple / O(n^2)");
	if (flags.medium)
		return ("Medium / O(n*sqrt(n))");
	if (flags.complex)
		return ("Complex / O(n log n)");
	if (disorder < 0.2f)
		return ("Adaptive -> Simple / O(n^2)");
	if (disorder < 0.5f)
		return ("Adaptive -> Medium / O(n*sqrt(n))");
	return ("Adaptive -> Complex / O(n log n)");
}
