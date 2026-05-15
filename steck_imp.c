/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steck_imp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:27:29 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/23 18:40:51 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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
