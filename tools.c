
#include "push_swap.h"

int	arr_size(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
		;
	return (i);
}