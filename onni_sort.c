
#include "push_swap.h"

int	find_spot(stack *s, int value)
{
	int	delta;
	int	index;
	int	smallest;
	int	spot_holder;

	delta = 0;
	if (value < s->a[find_smallest(s)])
	{
		spot_holder = s->a[find_smallest(s)];
	}
	else if (value > s->a[find_biggest(s)])
	{
		spot_holder = s->a[find_biggest(s) - 1];
	}
	else
	{
		smallest = s->a[find_smallest(s)];
		while (s->a[s->size_a - 1] != smallest)
		{
			delta++;
			fake_ra(s);
		}
		index = -1;
		while (++index < s->size_a)
		{
			// ft_printf("a: %d < value: %d \n", s->a[index], value);
			if (s->a[index] < value)
			{
				spot_holder = s->a[index - 1];	
				break ;
			}
		}
		while (delta-- > 0)
			fake_rra(s);
	}
	// ft_printf("spotholder: %d \n", spot_holder);
	index = 0;
	while (s->a[index] != spot_holder)
		index++;
	// ft_printf("index from spot: %d \n", index);
	return (index);
}

void	calc_moves_a(stack *s, moves *m)
{
	int	value;
	int	index;

	value = s->b[m->index];
	index = find_spot(s, value);
	// ft_printf("AAA --> index: %d >= threshold: %d\n", index, s->size_a / 2);
	if (index >= s->size_a / 2)
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
	// ft_printf("BBB --> index: %d >= threshold: %d\n", m->index, s->size_b / 2);
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
		// ft_printf("index: %d, a: %d, b: %d ab: %d\n", m->index, m->offset_a, m->offset_b, m->offset_ab);
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

void	rotate(stack *s)
{
	int	index;
	int	smallest;

	index = find_smallest(s);
	smallest = s->a[find_smallest(s)];
	if (index >= s->size_a / 2)
	{
		while (s->a[s->size_a - 1] != smallest)
			ra(s);
	}
	else
	{
		while (s->a[s->size_a - 1] != smallest)
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
		// print_stack(s);
		least_moves(s, &m, &l);
		// ft_printf("smallest: %d \n", l.index);
		do_moves(s, l);
	}
	// print_stack(s);
	rotate(s);
	// print_stack(s);
}