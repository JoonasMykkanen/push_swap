
#include "push_swap.h"

void	calc_moves_a(stack *s, moves *m)
{
	int	value;
	int	index;

	value = s->b[m->index];
	index = find_spot(s, value);
	if (index == 0)
	{
		if (s->a[0] < s->a[s->size_a - 1])
		{
			m->offset_a = 1;
			m->dir_a = 0;
		}
		else if (value > s->a[s->size_a - 1] && value < s->a[0])
		{
			m->offset_a = 1;
			m->dir_a = 0;
		}
		else
		{
			m->offset_a = 0;
			m->dir_a = 1;
		}
	}
	else if (index >= s->size_a / 2)
	{
		m->offset_a = (s->size_a - 1) - index;
		m->dir_a = 1;
	}
	else
	{
		m->offset_a = index + 1;
		m->dir_a = 0;
	}
}

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

void	calc_together(stack *s, moves *m)
{
	if (m->dir_a == m->dir_b && m->offset_a > 0 && m->offset_b > 0)
	{
		if (m->offset_a == m->offset_b)
		{
			m->offset_ab = m->offset_a;
			m->offset_a = 0;
			m->offset_b = 0;
			m->moves = m->offset_ab + 1;
		}
		else if (m->offset_a > m->offset_b)
		{
			m->offset_ab = m->offset_b;
			m->offset_a = m->offset_a - m->offset_b;
			m->offset_b = 0;
			m->moves = m->offset_ab + m->offset_a + 1;
		}
		else
		{
			m->offset_ab = m->offset_a;
			m->offset_b = m->offset_b - m->offset_a;
			m->offset_a = 0;
			m->moves = m->offset_ab + m->offset_b + 1;
		}
	}
	else
	{
		m->moves = m->offset_a + m->offset_b + 1;
		m->offset_ab = 0;
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

void	do_moves(stack *s, least l)
{	
	if (l.offset_ab > 0)
	{
		while (l.offset_ab-- > 0)
		{
			if (l.dir_a == 1)
				rr(s);
			else
				rrr(s);
		}
	}
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