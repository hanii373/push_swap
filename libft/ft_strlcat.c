/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:24:14 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/04 18:44:35 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	sum;

	i = 0;
	sum = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (size > d)
		sum = d + s;
	else
		sum = s + size;
	while (src[i] && size > (d + 1))
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (sum);
}
