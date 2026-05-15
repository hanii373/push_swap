/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:34:41 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/28 15:54:30 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a, t_count_opers *op)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->rank;
	mid = (*a)->next->rank;
	bot = (*a)->next->next->rank;
	if (top == 0 && mid == 2 && bot == 1)
		sa(a, op);
	else if (top == 1 && mid == 0 && bot == 2)
	{
		sa(a, op);
		rra(a, op);
	}
	else if (top == 1 && mid == 2 && bot == 0)
		rra(a, op);
	else if (top == 2 && mid == 0 && bot == 1)
		ra(a, op);
	else if (top == 2 && mid == 1 && bot == 0)
	{
		sa(a, op);
		ra(a, op);
	}
}
