/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:35:01 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/23 18:43:41 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numbers_separator(char **argv, int *arr, int i, int *j)
{
	char	**buff;
	int		k;

	if (!ft_strchr(argv[i], ' '))
	{
		if (!isinteger(argv[i], 0, 0) || !repeating_num_check(arr, *j, argv[i]))
			return (0);
		arr[(*j)++] = ft_atoi(argv[i]);
	}
	else
	{
		buff = ft_split(argv[i], ' ');
		if (!buff)
			return (0);
		k = -1;
		while (buff[++k])
		{
			if (!isinteger(buff[k], 0, 0)
				|| !repeating_num_check(arr, *j, buff[k]))
				return (ft_free(buff), 0);
			arr[(*j)++] = ft_atoi(buff[k]);
		}
		ft_free(buff);
	}
	return (1);
}
