/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:56:18 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/26 16:14:39 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(unsigned long num, char *base)
{
	int	base_len;
	int	len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (num >= (unsigned long)base_len)
		len += ft_putnbr_base(num / base_len, base);
	len += ft_putchar(base[num % base_len]);
	return (len);
}

size_t	ft_puthex(unsigned int n, int uppercase)
{
	if (uppercase)
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
	return (ft_putnbr_base(n, "0123456789abcdef"));
}

size_t	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				len;
	
	if (!ptr){
		return (write(1, "(nil)", 5));
	}
	address = (unsigned long)ptr;
	len = 0;
	len += write(1, "0x", 2);
	len += ft_putnbr_base(address, "0123456789abcdef");
	return (len);
}
