/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:29:38 by gogalsty          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>
# include <math.h>

/* ── Node ── */
typedef struct s_stack_node
{
	int					value;
	int					rank;
	int					stack_size;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

/* ── Operation counter ── */
typedef struct s_count_opers
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	all_op;
}	t_count_opers;

/* ── Strategy flags ── */
typedef struct s_strat
{
	bool	simple;
	bool	medium;
	bool	complex;
	bool	adaptive;
	bool	bench;
}	t_strat;

/* ── parser_utils.c ── */
int				isinteger(char *nptr);
int				num_check(char *str, int *numbers_count);
int				repeating_num_check(int *arr, int j, char *str);
void			ft_free(char **arr);

/* ── parser.c ── */
int				preparser_check(char **argv, int start_arg, int argc);
int				*parser(char **argv, int start_arg, int argc, int arr_len);
int				numbers_separator(char **argv, int *arr, int i, int *j);
int				comp_flag_check(int argc, char **argv, t_strat *yyy);
void			inicial_tflag(t_strat *yyy);
t_stack_node	*args_pars(int argc, char **argv, t_strat *flags, float *dis);

/* ── steck_imp.c ── */
t_stack_node	*lstnew_node(int number, int rank);
t_stack_node	*get_stack_a(int arr[], int ranks[], int len);
t_stack_node	*lstlast(t_stack_node *lst);
void			del_stack(t_stack_node *lst);
int				stack_size(t_stack_node *lst);
int				is_sorted(t_stack_node *stack);
void			init_op_counter(t_count_opers *op);
int				find_min_pos(t_stack_node *stack);
int				find_max_pos(t_stack_node *stack);
int				find_max_rank(t_stack_node *stack);

/* ── operations ── */
void			sa(t_stack_node **a, t_count_opers *op);
void			sb(t_stack_node **b, t_count_opers *op);
void			ss(t_stack_node **a, t_stack_node **b, t_count_opers *op);
void			ra(t_stack_node **a, t_count_opers *op);
void			rb(t_stack_node **b, t_count_opers *op);
void			rr(t_stack_node **a, t_stack_node **b, t_count_opers *op);
void			rra(t_stack_node **a, t_count_opers *op);
void			rrb(t_stack_node **b, t_count_opers *op);
void			rrr(t_stack_node **a, t_stack_node **b, t_count_opers *op);
void			pa(t_stack_node **a, t_stack_node **b, t_count_opers *op);
void			pb(t_stack_node **a, t_stack_node **b, t_count_opers *op);

/* ── sort algorithms ── */
void			simple_sort(t_stack_node **a, t_stack_node **b,
					t_count_opers *op);
void			medium_sort(t_stack_node **a, t_stack_node **b,
					t_count_opers *op);
void			complex_sort(t_stack_node **a, t_stack_node **b,
					t_count_opers *op);
void			adaptive_sort(t_stack_node **a, t_stack_node **b,
					float disorder, t_count_opers *op);

/* ── disorder / bench ── */
double			compute_disorder(t_stack_node *a);
float			calculate_disorder(int arr[], int size);
void			bench(float disorder, t_count_opers op, t_strat flags);

#endif
