
#include "push_swap.h"

void	clean_up(stack *s)
{
	// free(s->a);
	// free(s->b);
}

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
	int	printable;

	i = s->size_a;
	l = s->size_b;
	if (i > l)
		printable = i;
	else
		printable = l;
	ft_printf("a:   b:\n");
	while (printable > 0)
	{
		if (i > 0)
		{
			ft_printf("%d    ", s->a[i - 1]);
			i--;
		}
		else
			ft_printf("      ");
		if (l > 0)
		{
			ft_printf("%d", s->b[l - 1]);
			l--;	
		}
		ft_printf("\n");
		printable--;
	}
}