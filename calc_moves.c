

#include "push_swap.h"

static void	same_dir(stack *s, moves *m)
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

void	calc_together(stack *s, moves *m)
{
	if (m->dir_a == m->dir_b && m->offset_a > 0 && m->offset_b > 0)
	{
		same_dir(s, m);
	}
	else
	{
		m->moves = m->offset_a + m->offset_b + 1;
		m->offset_ab = 0;
	}
}