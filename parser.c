/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:08 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Validates all argv tokens (after the optional flag) are integers. */
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

/* Expands a single argv[i] token (may contain spaces) into arr[]. */
int	numbers_separator(char **argv, int *arr, int i, int *j)
{
	char	**buff;
	int		k;

	if (!ft_strchr(argv[i], ' '))
	{
		if (!isinteger(argv[i]) || !repeating_num_check(arr, *j, argv[i]))
			return (0);
		arr[(*j)++] = ft_atoi(argv[i]);
	}
	else
	{
		buff = ft_split(argv[i], ' ');
		if (!buff)
			return (0);
		k = 0;
		while (buff[k])
		{
			if (!isinteger(buff[k]) || !repeating_num_check(arr, *j, buff[k]))
			{
				ft_free(buff);
				return (0);
			}
			arr[(*j)++] = ft_atoi(buff[k]);
			k++;
		}
		ft_free(buff);
	}
	return (1);
}

/* Fills arr[] with all integer arguments, returns arr or NULL on error. */
int	*parser(char **argv, int start_arg, int argc, int arr_len)
{
	int	*arr;
	int	i;
	int	j;

	j = 0;
	i = start_arg + 1;
	arr = malloc(arr_len * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < argc)
	{
		if (!numbers_separator(argv, arr, i, &j))
		{
			free(arr);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (arr);
}

/*
** Computes 0-based ranks for each element of arr[].
** rank[i] = number of elements in arr strictly less than arr[i].
** This turns arbitrary integers into 0..n-1 for radix/chunk sort.
*/
static int	*compute_ranks(int *arr, int len)
{
	int	*ranks;
	int	i;
	int	j;
	int	r;

	ranks = malloc(len * sizeof(int));
	if (!ranks)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r = 0;
		j = 0;
		while (j < len)
		{
			if (arr[j] < arr[i])
				r++;
			j++;
		}
		ranks[i] = r;
		i++;
	}
	return (ranks);
}

/* Parses all strategy flags from argv. Returns index of first number arg. */
int	comp_flag_check(int argc, char **argv, t_strat *yyy)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 20) == 0)
			yyy->simple = true;
		else if (ft_strncmp(argv[i], "--medium", 20) == 0)
			yyy->medium = true;
		else if (ft_strncmp(argv[i], "--complex", 20) == 0)
			yyy->complex = true;
		else if (ft_strncmp(argv[i], "--adaptive", 20) == 0)
			yyy->adaptive = true;
		else if (ft_strncmp(argv[i], "--bench", 20) == 0)
			yyy->bench = true;
		else
			return (i - 1);
		i++;
	}
	return (i - 1);
}

/* Initialises all flags to false. */
void	inicial_tflag(t_strat *yyy)
{
	yyy->simple = false;
	yyy->medium = false;
	yyy->complex = false;
	yyy->adaptive = false;
	yyy->bench = false;
}

/*
** Full argument parsing entry point.
** Returns the built stack a, or NULL if no numbers were given.
** Sets *dis to the disorder value before any moves.
*/
t_stack_node	*args_pars(int argc, char **argv, t_strat *flags, float *dis)
{
	int				start_arg;
	int				arr_len;
	int				*arr;
	int				*ranks;
	t_stack_node	*stack_a;

	if (argc < 2)
		return (NULL);
	start_arg = comp_flag_check(argc, argv, flags);
	arr_len = preparser_check(argv, start_arg, argc);
	if (arr_len == 0)
		return (NULL);
	arr = parser(argv, start_arg, argc, arr_len);
	if (!arr)
		return (NULL);
	ranks = compute_ranks(arr, arr_len);
	if (!ranks)
	{
		free(arr);
		return (NULL);
	}
	*dis = calculate_disorder(arr, arr_len);
	stack_a = get_stack_a(arr, ranks, arr_len);
	free(arr);
	free(ranks);
	return (stack_a);
}
