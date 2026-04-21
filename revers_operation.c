/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:55 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *stack;
	if (!first || !first->next)
		return ;
	last = lstlast(first);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a, t_count_opers *op)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	op->rra++;
	op->all_op++;
}

void	rrb(t_stack_node **b, t_count_opers *op)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	op->rrb++;
	op->all_op++;
}

void	rrr(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	op->rrr++;
	op->all_op++;
}
