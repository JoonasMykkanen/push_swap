
#include "push_swap.h"

void	ra(stack *s)
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
	s->operations++;
	ft_printf("ra\n");
}

void	rb(stack *s)
{
	int	temp;
	int	i;
	
	if (s->size_b > 1)
	{
		i = s->size_b;
		temp = s->b[i - 1];
		while (i >= 0)
		{
			s->b[i + 1] = s->b[i];
			i--;
		}
		s->b[0] = temp;
	}
	s->operations++;
	ft_printf("rb\n");
}

static void	r_ra(stack *s)
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

static void	r_rb(stack *s)
{
	int	temp;
	int	i;
	
	if (s->size_b > 1)
	{
		i = s->size_b;
		temp = s->b[i - 1];
		while (i >= 0)
		{
			s->b[i + 1] = s->b[i];
			i--;
		}
		s->b[0] = temp;
	}
}

void	rr(stack *s)
{
	r_ra(s);
	r_rb(s);
	s->operations++;
	ft_printf("rr\n");
}
