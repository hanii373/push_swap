/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:40:47 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/06 19:05:17 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = itoa_len(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	res[len] = '\0';
	len--;
	while (n)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
