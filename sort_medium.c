
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
		if (s->a[index] <= temp)
		{
			temp = s->a[index];
			ret = index;
		}
	}
	return (ret);
}

static int	is_sorted(stack *s)
{
	int	i;
	int	temp;

	i = s->size_a - 1;
	temp = s->a[i];
	while (i > 0)
	{
		if (temp > s->a[i - 1])
			return (1);
		temp = s->a[--i];
	}
	return (0);
}

void	sort_medium(stack *s)
{
	int	index;
	int	offset;

	if (is_sorted(s) == 0)
		return ;
	while (s->size_a > 3)
	{
		index = find_smallest(s);
		// ft_printf("BEFORE\n");
		// print_stack(s);
		// ft_printf("index: %d \n", index);
		offset = index;
		if (offset >= s->size_a / 2)
		{
			offset = (s->size_a - 1) - index;	
			while (offset-- > 0)
				ra(s);
			pb(s);
		}
		else
		{
			while (offset-- >= 0)
				rra(s);
			pb(s);
		}
		// ft_printf("AFTER\n");
		// print_stack(s);
	}
	sort_small(s);
	while (s->size_b > 0)
		pa(s);
}