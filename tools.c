
#include "push_swap.h"

int	arr_size(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
		;
	return (i);
}

void	print_stack(stack *s)
{
	int	i;
	int l;

	i = s->size_a;
	l = s->size_b;
	ft_printf("a:   b:\n");
	while (i > 0)
	{
		if (i > 0)
			ft_printf("%d    ", s->a[i - 1]);
		if (l > 0)
		{
			ft_printf("%d", s->b[l - 1]);
			l--;
		}
		ft_printf("\n");
		i--;
	}
}