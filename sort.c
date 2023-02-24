
#include "push_swap.h"

static void	sort_tiny(stack *s)
{
	if (s->a[1] > s->a[0])
	{
		sa(s);
	}
}

static void	sort_small(stack *s)
{
	if (s->a[1] > s->a[0] && s->a[2] > s->a[1])
	{
		sa(s);
		rra(s);
	}
	if (s->a[2] < s->a[1] && s->a[1] > s->a[0])
	{
		sa(s);
		ra(s);
	}
	if (s->a[2] > s->a[1] && s->a[1] < s->a[0])
	{
		ra(s);
	}
	if (s->a[2] > s->a[1])
	{
		sa(s);
	}
}

static void	sort_medium(stack *s)
{

}

void	sort(stack *s)
{
	if (s->size_a == 1)
		return ;
	else if (s->size_a == 2)
		sort_tiny(s);
	else if (s->size_a == 3)
		sort_small(s);
	else if (s->size_a > 3 && s->size_a > 6)
		sort_medium(s);
}