
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
typedef struct t_stack
{
	int	*a;
	int	*b;
	int size_a;
	int size_b;
	int	operations;
}	stack;

typedef struct t_algo_data
{
	int	avg_1;
	int	avg_2;
	int	size_avg;
}	algo_data;

typedef	struct t_moves
{
	int		offset_ab;
	int		offset_a;
	int		offset_b;
	int		moves;
	int		index;
	int		dir_a;
	int		dir_b;
	int		state;
}	moves;

typedef struct t_least
{
	int		offset_ab;
	int		offset_a;
	int		offset_b;
	int		index;
	int		dir_a;
	int		dir_b;
}	least;

void	print_stack(stack *s);

void	pa(stack *s);
void	pb(stack *s);
void	ra(stack *s);
void	rb(stack *s);
void	rr(stack *s);
void	sa(stack *s);
void	sb(stack *s);
void	ss(stack *s);
void	rra(stack *s);
void	rrb(stack *s);
void	rrr(stack *s);
void	sort(stack *s);
void	rotate(stack *s);
void	fake_ra(stack *s);
void	fake_rra(stack *s);
void	clean_up(stack *s);
void	onni_sort(stack *s);
void	sort_algo(stack *s);
int		arr_size(char **arr);
void	sort_medium(stack *s);
int 	find_biggest(stack *s);
void	sort_small(stack *s);
int		find_smallest(stack *s);
void	check_duplicates(stack *s);
void	do_moves(stack *s, least l);
int		find_spot(stack *s, int value);
void	calc_moves_a(stack *s, moves *m);
void	calc_together(stack *s, moves *m);
void	check_args(stack *s, int argc, char **argv);

#endif