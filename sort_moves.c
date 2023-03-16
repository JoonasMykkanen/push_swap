
#include "push_swap.h"

static void	move_ab(stack *s, least *l)
{
	while (l->offset_ab-- > 0)
	{
		if (l->dir_a == 1)
			rr(s);
		else
			rrr(s);
	}
}

void	do_moves(stack *s, least l)
{	
	if (l.offset_ab > 0)
		move_ab(s, &l);
	while (l.offset_a-- > 0)
	{
		if (l.dir_a == 1)
			ra(s);
		else
			rra(s);
	}
	while (l.offset_b-- > 0)
	{
		if (l.dir_b == 1)
			rb(s);
		else
			rrb(s);
	}
	pa(s);
}