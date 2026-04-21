/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:02 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **from, t_stack_node **to)
{
	t_stack_node	*node;

	if (!*from)
		return ;
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	node->prev = NULL;
	if (*to)
		(*to)->prev = node;
	*to = node;
}

void	pa(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	push(b, a);
	write(1, "pa\n", 3);
	op->pa++;
	op->all_op++;
}

void	pb(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	push(a, b);
	write(1, "pb\n", 3);
	op->pb++;
	op->all_op++;
}
