/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:37:33 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/26 16:15:03 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

size_t	ft_putint(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		len += ft_putchar('-');
		num = -num;
	}
	len += ft_putnbr_base(num, "0123456789");
	return (len);
}

size_t	ft_putunsigned(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789"));
}
