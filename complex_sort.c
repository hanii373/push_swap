/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:29:00 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/28 15:37:33 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_rank)
{
	int	bits;

	bits = 0;
	while ((1 << bits) <= max_rank)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack_node **a, t_stack_node **b,
				t_count_opers *op, int bit)
{
	int	size;
	int	j;

	size = stack_size(*a);
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
}

void	complex_sort(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	int	size;
	int	max_bits;
	int	bit;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 3)
		return (sort_three(a, op));
	if (size <= 5)
		return (simple_sort(a, b, op));
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, op, bit);
		bit++;
	}
}
