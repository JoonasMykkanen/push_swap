
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

# include "libft/libft.h"





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
void	clean_up(stack *s);
void	sort_algo(stack *s);
void	sort_small(stack *s);
int		arr_size(char **arr);
void	sort_medium(stack *s);
void	check_duplicates(stack *s);
void	check_args(stack *s, int argc, char **argv);

#endif