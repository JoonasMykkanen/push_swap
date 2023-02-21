

#include "push_swap.h"

void	sa(stack *s)
{
	if (s->size_a > 1)
	{
		int top;
		int	temp;

		top = s->size_a - 1;
		temp = s->a[top - 1];
		s->a[top - 1] = s->a[top];
		s->a[top] = temp;
	}
	s->operations++;
	ft_printf("sa\n");
}

void	sb(stack *s)
{
	if (s->size_b > 1)
	{
		int	top;
		int	temp;

		top = s->size_b - 1;
		temp = s->b[top - 1];
		s->b[top - 1] = s->b[top];
		s->b[top] = temp;
	}
	s->operations++;
	ft_printf("sb\n");
}

void	ss(stack *s)
{
	sa(s);
	sb(s);
	s->operations++;
	ft_printf("ss\n");
}
