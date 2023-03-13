

#include "push_swap.h"

void	fake_ra(stack *s)
{
	int	temp;
	int	i;
	
	if (s->size_a > 1)
	{
		i = s->size_a;
		temp = s->a[i - 1];
		while (i >= 0)
		{
			s->a[i + 1] = s->a[i];
			i--;
		}
		s->a[0] = temp;
	}
}

void	fake_rra(stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->a[0];
	while (i < s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->size_a - 1] = temp;
}

int find_biggest(stack *s)
{
	int	temp;
	int	index;
	int	ret;

	temp = s->a[0];
	ret = 0;
	index = -1;
	while (++index < s->size_a)
	{
		if (s->a[index] >= temp)
		{
			temp = s->a[index];
			ret = index;
		}
	}
	return (ret);
}