/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:29:00 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the number of bits needed to represent max_rank.
** e.g. max_rank = 7 -> 3 bits, max_rank = 500 -> 9 bits.
*/
static int	get_max_bits(int max_rank)
{
	int	bits;

	bits = 0;
	while ((1 << bits) <= max_rank)
		bits++;
	return (bits);
}

/*
** Complex O(n log n) LSD radix sort.
**
** Works on node->rank (always in [0, n-1]) so no negative-number issues.
** For each bit position from LSB to MSB:
**   - iterate through all n elements of a:
**       if bit i of rank is 0  -> pb (goes to b)
**       if bit i of rank is 1  -> ra (stays in a, rotated to bottom)
**   - push everything from b back to a (pa)
** After log2(n) passes, a is sorted ascending by rank.
*/
void	complex_sort(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	int	size;
	int	max_bits;
	int	bit;
	int	j;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size <= 5)
	{
		medium_sort(a, b, op);
		return ;
	}
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->rank) >> bit) & 1)
				ra(a, op);
			else
				pb(a, b, op);
			j++;
		}
		while (*b)
			pa(a, b, op);
		bit++;
	}
}
