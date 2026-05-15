/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:37 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/27 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_sort(t_stack_node **a, t_stack_node **b,
				t_strat flags, t_count_opers *op)
{
	if (flags.simple)
		simple_sort(a, b, op);
	else if (flags.medium)
		medium_sort(a, b, op);
	else if (flags.complex)
		complex_sort(a, b, op);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_strat			flags;
	t_count_opers	op;
	float			disorder;

	inicial_tflag(&flags);
	a = args_pars(argc, argv, &flags, &disorder);
	if (!a)
		return (0);
	b = NULL;
	init_op_counter(&op, flags.count_only);
	if (flags.simple || flags.medium || flags.complex)
		select_sort(&a, &b, flags, &op);
	else
		adaptive_sort(&a, &b, disorder, &op);
	if (flags.count_only)
		ft_printf("%d\n", op.all_op);
	if (flags.bench)
		bench(disorder, op, flags);
	return (del_stack(a), del_stack(b), 0);
}
