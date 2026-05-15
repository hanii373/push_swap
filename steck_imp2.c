/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steck_imp2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:39:39 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/23 18:39:48 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_rank(t_stack_node *stack)
{
	int	max;

	max = stack->rank;
	stack = stack->next;
	while (stack)
	{
		if (stack->rank > max)
			max = stack->rank;
		stack = stack->next;
	}
	return (max);
}

t_stack_node	*lstnew_node(int number, int rank)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	node->value = number;
	node->rank = rank;
	node->stack_size = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack_node	*get_stack_a(int arr[], int ranks[], int len)
{
	t_stack_node	*head;
	t_stack_node	*prev;
	t_stack_node	*tmp;
	int				i;

	head = lstnew_node(arr[0], ranks[0]);
	if (!head)
		return (NULL);
	head->stack_size = len;
	prev = head;
	i = 1;
	while (i < len)
	{
		tmp = lstnew_node(arr[i], ranks[i]);
		if (!tmp)
			return (del_stack(head), NULL);
		tmp->stack_size = len;
		prev->next = tmp;
		tmp->prev = prev;
		prev = tmp;
		i++;
	}
	return (head);
}

void	del_stack(t_stack_node *lst)
{
	t_stack_node	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	init_op_counter(t_count_opers *op, bool silent)
{
	op->sa = 0;
	op->sb = 0;
	op->ss = 0;
	op->pa = 0;
	op->pb = 0;
	op->ra = 0;
	op->rb = 0;
	op->rr = 0;
	op->rra = 0;
	op->rrb = 0;
	op->rrr = 0;
	op->all_op = 0;
	op->silent = silent;
}
