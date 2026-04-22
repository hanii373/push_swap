#include "push_swap.h"

void	init_flags(t_strat *flags)
{
	flags->simple = 0;
	flags->medium = 0;
	flags->complex = 0;
	flags->adaptive = 1;
	flags->bench = 0;
}

void	parse_flags(int argc, char **argv, t_strat *flags)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--simple"))
			flags->simple = 1;
		else if (!ft_strcmp(argv[i], "--medium"))
			flags->medium = 1;
		else if (!ft_strcmp(argv[i], "--complex"))
			flags->complex = 1;
		else if (!ft_strcmp(argv[i], "--adaptive"))
			flags->adaptive = 1;
		else if (!ft_strcmp(argv[i], "--bench"))
			flags->bench = 1;
		i++;
	}
}