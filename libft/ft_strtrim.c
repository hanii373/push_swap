/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:30:30 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/06 17:12:34 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	av(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*trim;
	int		beg;
	int		end;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] && av(set, s1[beg]))
		beg++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && av(set, s1[end]) && beg <= end)
		end--;
	trim = (char *)malloc(end - beg + 2);
	if (!trim)
		return (NULL);
	i = 0;
	while (beg + i <= end)
	{
		trim[i] = s1[beg + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
