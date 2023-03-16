
#include "push_swap.h"

void	calc_moves_b(stack *s, moves *m)
{
	int	top;

	top = s->size_b - 1;
	if (m->index >= (s->size_b / 2))
	{
		m->offset_b = top - m->index;
		m->dir_b = 1;
	}
	else
	{
		m->offset_b = m->index + 1;
		m->dir_b = 0;
	}
}

void	least_moves(stack *s, moves *m, least *l)
{
	int		temp;
	
	m->index = -1;
	temp = 2147483647;
	while (++m->index < s->size_b)
	{
		calc_moves_a(s, m);
		calc_moves_b(s, m);
		calc_together(s, m);
		if (m->moves <= temp)
		{
			temp = m->moves;
			l->dir_a = m->dir_a;
			l->dir_b = m->dir_b;
			l->index = m->index;
			l->offset_a = m->offset_a;
			l->offset_b = m->offset_b;
			l->offset_ab = m->offset_ab;
		}
	}
}

void	sort_algo(stack *s)
{
	moves	m;
	least	l;
	int		offset;

	while (s->size_a > 3)
		pb(s);
	sort_small(s);
	while (s->size_b > 0)
	{
		least_moves(s, &m, &l);
		do_moves(s, l);
	}
	rotate(s);
}