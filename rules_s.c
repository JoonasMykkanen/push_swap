

#include "push_swap.h"

void	sa(stack *s)
{
	if (s->size_a > 1)
	{
		int	temp;

		temp = s->a[s->size_a];
		s->a[s->size_a] = s->a[s->size_a - 1];
		s->a[s->size_a - 1] = temp;
	}
}

void	sb(stack *s)
{
	if (s->size_b > 1)
	{
		int	temp;

		temp = s->b[s->size_b];
		s->b[s->size_b] = s->b[s->size_b - 1];
		s->b[s->size_b - 1] = temp;
	}
}

void	ss(stack *s)
{
	sa(s);
	sb(s);
}
