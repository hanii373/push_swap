/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:15:19 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/07 17:44:25 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*fin;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	fin = (char *)malloc((len + 1) * sizeof(char));
	if (!fin)
		return (NULL);
	while (i < len)
	{
		fin[i] = f(i, s[i]);
		i++;
	}
	fin[i] = '\0';
	return (fin);
}
