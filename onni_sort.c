

#include "push_swap.h"

void	calc_moves_a(stack *s, moves *m)
{
	
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
	if (m->dir_a == m->dir_b)
	{
		if (m->offset_a > m->offset_b)
		{
			m->offset_ab = m->offset_b;
			m->offset_b = 0;
			m->offset_a = m->offset_a - m->offset_b;
			m->moves = m->offset_ab + m->offset_a + 1;
		}
		else
		{
			m->offset_ab = m->offset_a;
			m->offset_a = 0;
			m->offset_a = m->offset_b - m->offset_a;
			m->moves = m->offset_ab + m->offset_b + 1;
		}
	}
	else
		m->moves = m->offset_a + m->offset_b + 1;
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
		ft_printf("index: %d, a: %d, b: %d\n", m->index, m->offset_a, m->offset_b);
	}
}

void	do_moves(stack *s, least l)
{
	if (l.dir_a == l.dir_b)
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
		if (l.dir_a == 1)
			rb(s);
		else
			rrb(s);
	}
	pa(s);
}

void	rotate(stack *s)
{
	int	index;
	int	temp;
	int	ret;

	index = -1;
	temp = 2147483647;
	while (++index < s->size_a - 1)
	{
		if (s->a[index] < temp)
		{
			ret = index;
			temp = s->a[index];
		}
	}
	ft_printf("ret: %d \n", ret);
	if (ret >= (s->size_a - 1) / 2)
	{
		while (ret-- > 0)
			ra(s);
	}
	else
	{
		ret++;
		while (ret-- > 0)
			rra(s);
	}
}

void	onni_sort(stack *s)
{
	moves	m;
	least	l;
	int		offset;

	while (s->size_a > 3)
		pb(s);
	sort_small(s);
	while (s->size_b > 0)
	{
		print_stack(s);
		least_moves(s, &m, &l);
		ft_printf("smallest: %d \n", l.index);
		do_moves(s, l);
	}
	print_stack(s);
	rotate(s);
	print_stack(s);
}