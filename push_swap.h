
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_stack
{
	int	*a;
	int	*b;
	int stack_size;
}	stack;

# include "libft/libft.h"

int		arr_size(char **arr);
void	check_duplicates(stack *s);
void	check_args(stack *s, int argc, char **argv);

#endif