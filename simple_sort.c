/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:06 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotates the element at position pos to the top of the stack using
** the cheapest direction: ra if pos <= size/2, rra otherwise.
*/
static void	rotate_to_top(t_stack_node **stack, int pos,
				int size, t_count_opers *op)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack, op);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack, op);
	}
}

/*
** Simple O(n^2) selection sort adaptation.
** Each pass finds the minimum, rotates it to top, pushes to b.
** After all elements are in b (in reverse sorted order), push all back to a.
** Result: a is sorted ascending with the smallest at top.
*/
void	simple_sort(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	while (size > 0 && !is_sorted(*a))
	{
		min_pos = find_min_pos(*a);
		rotate_to_top(a, min_pos, size, op);
		pb(a, b, op);
		size--;
	}
	while (*b)
		pa(a, b, op);
}
