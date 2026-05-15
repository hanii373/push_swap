/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:06 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/28 15:53:04 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// void	sort_max3(t_stack_node **a, t_count_opers *count)
// {
// 	if (!a || (*a)->next == NULL)
// 		return;
// 	else if (ft_lstsize(*a) == 2)
// 	{
// 		if ((*a)->rank > (*a)->next->rank)
// 			sa(a, count);
// 	}
// 	else if (ft_lstsize(*a) == 3)
// 	{
// 		while (compute_disorder(*a) != 0)
// 		{
// 			if ((*a)->rank > ft_lstlast(*a)->rank)
// 				ra(a, count);
// 			else if ((*a)->rank > (*a)->next->rank)
// 				sa(a, count);
// 			else if ((*a)->next->rank > ft_lstlast(*a)->rank)
// 				rra(a, count);	
// 		}
// 	}
// }

void	simple_sort(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	int	size;
	int	min_pos;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 3)
		return (sort_three(a, op));
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
