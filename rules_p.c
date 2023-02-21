
#include "push_swap.h"

void	pa(stack *s)
{
	if (s->size_b > 0)
	{
		s->a[s->size_a] = s->b[s->size_b - 1];
		s->size_a++;
		s->size_b--;
	}
	s->operations++;
	ft_printf("pa\n");
}

void	pb(stack *s)
{
	if (s->size_a > 0)
	{
		s->b[s->size_b] = s->a[s->size_a - 1];
		s->size_a--;
		s->size_b++;
	}
	s->operations++;
	ft_printf("pb\n");
}