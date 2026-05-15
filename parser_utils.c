/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:14 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/23 18:37:32 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isinteger(char *nptr, int i, unsigned long number)
{
	long			sign;

	sign = 1;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (ft_isdigit(nptr[i]))
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
		if ((sign == 1 && number > (unsigned long)INT_MAX)
			|| (sign == -1 && number > (unsigned long)INT_MAX + 1))
			return (0);
	}
	if (nptr[i] != '\0')
		return (0);
	return (1);
}

int	num_check(char *str, int *numbers_count)
{
	int	i;
	int	moving_checker;

	i = 0;
	moving_checker = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i])
			|| (str[i] == '-' && ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && ft_isdigit(str[i + 1])))
		{
			i++;
			(*numbers_count)++;
		}
		while (ft_isdigit(str[i]))
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			return (1);
		if (moving_checker == i)
			break ;
		moving_checker = i;
	}
	return (0);
}

int	repeating_num_check(int *arr, int j, char *str)
{
	int	i;
	int	number_to_find;

	i = 0;
	number_to_find = ft_atoi(str);
	while (i < j)
	{
		if (arr[i] == number_to_find)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

int	preparser_check(char **argv, int start_arg, int argc)
{
	int	i;
	int	numbers_count;

	numbers_count = 0;
	i = start_arg + 1;
	while (i < argc)
	{
		if (!num_check(argv[i], &numbers_count))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (numbers_count);
}
