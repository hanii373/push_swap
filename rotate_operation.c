/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:36 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *stack;
	if (!first || !first->next)
		return ;
	last = lstlast(first);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, t_count_opers *op)
{
	rotate(a);
	write(1, "ra\n", 3);
	op->ra++;
	op->all_op++;
}

void	rb(t_stack_node **b, t_count_opers *op)
{
	rotate(b);
	write(1, "rb\n", 3);
	op->rb++;
	op->all_op++;
}

void	rr(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	op->rr++;
	op->all_op++;
}
