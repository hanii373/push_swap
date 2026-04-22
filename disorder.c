/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:55 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Computes the disorder of stack a using the inversion-pair formula.
** disorder = mistakes / total_pairs, result in [0.0 .. 1.0].
** Works on the linked list directly.
*/
double	compute_disorder(t_stack_node *a)
{
	t_stack_node	*outer;
	t_stack_node	*inner;
	int				mistakes;
	int				total;

	mistakes = 0;
	total = 0;
	outer = a;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			total++;
			if (outer->value > inner->value)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / total);
}

/*
** Same calculation on a plain int array (used before the stack is built).
*/
float	calculate_disorder(int arr[], int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / total_pairs);
}
