/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:29:12 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 16:09:31 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Adaptive strategy: selects the algorithm based on the pre-computed disorder.
**   disorder < 0.2  -> O(n^2)   simple selection sort
**   disorder < 0.5  -> O(n√n)   chunk sort
**   disorder >= 0.5 -> O(n log n) radix sort (LSD on ranks)
**
** The disorder value is computed BEFORE any moves and passed in from main.
*/
void	adaptive_sort(t_stack_node **a, t_stack_node **b,
			float disorder, t_count_opers *op)
{
	int	size;

	size = stack_size(*a);
	if (size <= 10)
		simple_sort(a, b, op);
	else if (disorder < 0.2f)
		simple_sort(a, b, op);
	else if (disorder < 0.5f)
		medium_sort(a, b, op);
	else
		complex_sort(a, b, op);
}
