/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steck_imp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:29 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns last node of a linked list. */
t_stack_node	*lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* Counts nodes in a linked list. */
int	stack_size(t_stack_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/* Returns 1 if stack is sorted ascending (top = smallest), else 0. */
int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Returns 0-based position of the node with the smallest value. */
int	find_min_pos(t_stack_node *stack)
{
	int				pos;
	int				min_pos;
	int				min_val;
	t_stack_node	*cur;

	pos = 0;
	min_pos = 0;
	min_val = stack->value;
	cur = stack;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}

/* Returns 0-based position of the node with the largest value. */
int	find_max_pos(t_stack_node *stack)
{
	int				pos;
	int				max_pos;
	int				max_val;
	t_stack_node	*cur;

	pos = 0;
	max_pos = 0;
	max_val = stack->value;
	cur = stack;
	while (cur)
	{
		if (cur->value > max_val)
		{
			max_val = cur->value;
			max_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (max_pos);
}

/* Returns the maximum rank value in the stack (used by radix sort). */
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

/* Allocates a single node. */
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

/*
** Builds stack a from arr[] (raw values) and ranks[] (0-based sorted rank).
** The first element of arr becomes the top of the stack.
*/
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
		{
			del_stack(head);
			return (NULL);
		}
		tmp->stack_size = len;
		prev->next = tmp;
		tmp->prev = prev;
		prev = tmp;
		i++;
	}
	return (head);
}

/* Frees the entire stack. */
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

/* Zeroes all counters in the op struct. */
void	init_op_counter(t_count_opers *op)
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
}
