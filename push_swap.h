/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct t_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	operations;
}	t_stack;

typedef struct t_algo_data
{
	int	avg_1;
	int	avg_2;
	int	size_avg;
}	t_algo_data;

typedef struct t_moves
{
	int		offset_ab;
	int		offset_a;
	int		offset_b;
	int		t_moves;
	int		index;
	int		dir_a;
	int		dir_b;
	int		state;
}	t_moves;

typedef struct t_least
{
	int		offset_ab;
	int		offset_a;
	int		offset_b;
	int		index;
	int		dir_a;
	int		dir_b;
}	t_least;

void	print_t_stack(t_stack *s);

void	pa(t_stack *s);
void	pb(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);
void	sort(t_stack *s);
void	init(t_stack *s);
void	rotate(t_stack *s);
void	fake_ra(t_stack *s);
void	fake_rra(t_stack *s);
void	clean_up(t_stack *s);
int		arr_size(char **arr);
void	onni_sort(t_stack *s);
void	sort_algo(t_stack *s);
int		is_sorted(t_stack *s);
void	sort_small(t_stack *s);
void	sort_medium(t_stack *s);
void	ft_free(char **garbage);
int		find_biggest(t_stack *s);
void	ft_error(char **garbage);
int		find_smallest(t_stack *s);
char	fake_atoi(const char *str);
void	check_duplicates(t_stack *s);
void	do_moves(t_stack *s, t_least l);
int		find_spot(t_stack *s, int value);
void	calc_moves_a(t_stack *s, t_moves *m);
void	calc_together(t_stack *s, t_moves *m);
void	check_args(t_stack *s, int argc, char **argv);
void	from_string(t_stack *s, int argc, char **argv);
void	from_individual(t_stack *s, int argc, char **argv);

#endif