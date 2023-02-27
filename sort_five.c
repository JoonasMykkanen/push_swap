
#include "push_swap.h"

static	int	find_smallest(stack *s)
{
	int	temp;
	int	index;
	int	ret;

	temp = s->a[0];
	index = -1;
	while (++index < s->size_a)
	{
		if (s->a[index] < temp)
		{
			temp = s->a[index];
			ret = index;
		}
	}
	return (ret);
}

void	sort_five(stack *s)
{
	int	index;
	int	offset;

	while (s->size_a > 3)
	{
		index = find_smallest(s);
		offset = (s->size_a - 1) - index;
		ft_printf("offset: %d\n", offset);
		if (offset == 0)
			pb(s);
		else if (offset >= s->size_a / 2)
		{
			while (offset-- > 0)
				rra(s);
			pb(s);
		}
		else
		{
			while (offset-- > 0)
				ra(s);
			pb(s);
		}
	}
	ft_printf("bef\n");
	print_stack(s);
	sort_small(s);
	ft_printf("after\n");
}