/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:33:03 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/06 16:48:39 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *s, char c)
{
	size_t	cw;

	cw = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cw;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cw);
}

static void	split_free(char **s)
{
	size_t	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

static char	**init(size_t *i, char const *s, char c)
{
	if (!s)
		return (NULL);
	*i = 0;
	return (malloc((count_word(s, c) + 1) * sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	char	**cw;
	size_t	i;
	size_t	len;

	cw = init(&i, s, c);
	if (!cw)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			cw[i] = ft_substr(s - len, 0, len);
			if (!cw[i])
				return (split_free(cw), NULL);
			i++;
		}
		else
			++s;
	}
	cw[i] = NULL;
	return (cw);
}

// int	main(){
// 	char str[] = "    卐卐卐卐卐   nigga        heil     hitler     卐卐卐卐卐";

// 	char **arr = ft_split(str, ' ');

// 	for (int i = 0; arr[i]; i++)
// 	{
// 		printf("%s\n", arr[i]);
// 	}
// 	return (0);
// }
