/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:29:05 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/27 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_int_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_int_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static void	bench_disorder(float disorder)
{
	int	whole;
	int	frac;

	whole = (int)(disorder * 100);
	frac = (int)(disorder * 10000) % 100;
	write(2, "[bench] disorder: ", 18);
	put_int_fd(whole, 2);
	write(2, ".", 1);
	if (frac < 10)
		write(2, "0", 1);
	put_int_fd(frac, 2);
	write(2, "%\n", 2);
}

static void	bench_ops(t_count_opers op)
{
	write(2, "[bench] sa: ", 12);
	put_int_fd(op.sa, 2);
	write(2, " sb: ", 5);
	put_int_fd(op.sb, 2);
	write(2, " ss: ", 5);
	put_int_fd(op.ss, 2);
	write(2, " pa: ", 5);
	put_int_fd(op.pa, 2);
	write(2, " pb: ", 5);
	put_int_fd(op.pb, 2);
	write(2, "\n[bench] ra: ", 13);
	put_int_fd(op.ra, 2);
	write(2, " rb: ", 5);
	put_int_fd(op.rb, 2);
	write(2, " rr: ", 5);
	put_int_fd(op.rr, 2);
	write(2, " rra: ", 6);
	put_int_fd(op.rra, 2);
	write(2, " rrb: ", 6);
	put_int_fd(op.rrb, 2);
	write(2, " rrr: ", 6);
	put_int_fd(op.rrr, 2);
	write(2, "\n", 1);
}

void	bench(float disorder, t_count_opers op, t_strat flags)
{
	const char	*name;

	bench_disorder(disorder);
	name = strategy_name(flags, disorder);
	write(2, "[bench] strategy: ", 18);
	write(2, name, ft_strlen(name));
	write(2, "\n[bench] total_ops: ", 20);
	put_int_fd(op.all_op, 2);
	write(2, "\n", 1);
	bench_ops(op);
}
