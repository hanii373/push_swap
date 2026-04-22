/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:16 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack_node **a, t_count_opers *op)
{
	swap(a);
	write(1, "sa\n", 3);
	op->sa++;
	op->all_op++;
}

void	sb(t_stack_node **b, t_count_opers *op)
{
	swap(b);
	write(1, "sb\n", 3);
	op->sb++;
	op->all_op++;
}

void	ss(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	op->ss++;
	op->all_op++;
}
