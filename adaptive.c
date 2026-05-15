/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:29:12 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/28 14:38:19 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack_node **a, t_stack_node **b,
			float disorder, t_count_opers *op)
{
	int	size;

	size = stack_size(*a);
	if (size <= 10)
		simple_sort(a, b, op);
	else if (size <= 50 && disorder < 0.2f)
		simple_sort(a, b, op);
	else if (size <= 200 && disorder < 0.5f)
		medium_sort(a, b, op);
	else
		complex_sort(a, b, op);
}
