/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_t_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_zero(t_stack *s, t_moves *m, int value)
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

void	calc_moves_a(t_stack *s, t_moves *m)
{
	int	value;
	int	index;

	value = s->b[m->index];
	index = find_spot(s, value);
	if (index == 0)
	{
		index_zero(s, m, value);
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
