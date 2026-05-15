/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:31 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/28 15:31:11 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_chunks_to_b(t_stack_node **a, t_stack_node **b,
				t_count_opers *op, t_chunk *c)
{
	while (c->pushed < c->size)
	{
		c->i = 0;
		while (c->i < c->size && c->pushed < c->size)
		{
			if ((*a)->rank >= c->chunk_start
				&& (*a)->rank < c->chunk_start + c->chunk_size)
			{
				pb(a, b, op);
				if ((*b)->rank < c->chunk_start + c->chunk_size / 2)
					rb(b, op);
				c->pushed++;
			}
			else
				ra(a, op);
			c->i++;
		}
		c->chunk_start += c->chunk_size;
	}
}

void	medium_sort(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	t_chunk	c;

	if (is_sorted(*a))
		return ;
	if (stack_size(*a) == 3)
		return (sort_three(a, op));
	c.size = stack_size(*a);
	c.chunk_size = (int)ceil(sqrt((double)c.size) * 1.5);
	if (c.size <= 5)
		return (simple_sort(a, b, op));
	if (c.chunk_size < 4)
		c.chunk_size = 4;
	c.chunk_start = 0;
	c.pushed = 0;
	c.i = 0;
	push_chunks_to_b(a, b, op, &c);
	while (*b)
		push_max_to_a(a, b, op);
}
