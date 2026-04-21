/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:31 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pushes the element with the maximum rank in b to the top of b,
** then pushes it to a.  Used when restoring b -> a in sorted order.
*/
static void	push_max_to_a(t_stack_node **a, t_stack_node **b,
				t_count_opers *op)
{
	int	size;
	int	max_pos;

	size = stack_size(*b);
	max_pos = find_max_pos(*b);
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(b, op);
	}
	else
	{
		max_pos = size - max_pos;
		while (max_pos-- > 0)
			rrb(b, op);
	}
	pa(a, b, op);
}

/*
** Medium O(n√n) chunk sort.
**
** Phase 1 – push to b in chunks of size √n:
**   Divide the rank range [0, n) into chunks of chunk_size = ceil(√n).
**   Scan a repeatedly; whenever the top of a has a rank in the current
**   chunk window [chunk_start, chunk_start + chunk_size), push it to b.
**   Use rb() to keep b roughly sorted within each chunk (largest on top
**   of b helps when pulling back).
**
** Phase 2 – pull back from b:
**   Repeatedly find the max-rank element in b, rotate it to top, pa.
**   This places elements into a in descending rank order, so a ends up
**   sorted ascending (smallest rank = smallest value at top).
*/
void	medium_sort(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	int	size;
	int	chunk_size;
	int	chunk_start;
	int	pushed;
	int	i;

	size = stack_size(*a);
	chunk_size = (int)ceil(sqrt((double)size));
	chunk_start = 0;
	pushed = 0;
	while (pushed < size)
	{
		i = 0;
		while (i < size && pushed < size)
		{
			if ((*a)->rank >= chunk_start
				&& (*a)->rank < chunk_start + chunk_size)
			{
				pb(a, b, op);
				if ((*b)->rank < chunk_start + chunk_size / 2)
					rb(b, op);
				pushed++;
			}
			else
				ra(a, op);
			i++;
		}
		chunk_start += chunk_size;
	}
	while (*b)
		push_max_to_a(a, b, op);
}
