/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_t_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	same_dir(t_stack *s, t_moves *m)
{
	if (m->offset_a == m->offset_b)
	{
		m->offset_ab = m->offset_a;
		m->offset_a = 0;
		m->offset_b = 0;
		m->t_moves = m->offset_ab + 1;
	}
	else if (m->offset_a > m->offset_b)
	{
		m->offset_ab = m->offset_b;
		m->offset_a = m->offset_a - m->offset_b;
		m->offset_b = 0;
		m->t_moves = m->offset_ab + m->offset_a + 1;
	}
	else
	{
		m->offset_ab = m->offset_a;
		m->offset_b = m->offset_b - m->offset_a;
		m->offset_a = 0;
		m->t_moves = m->offset_ab + m->offset_b + 1;
	}
}

void	calc_together(t_stack *s, t_moves *m)
{
	if (m->dir_a == m->dir_b && m->offset_a > 0 && m->offset_b > 0)
	{
		same_dir(s, m);
	}
	else
	{
		m->t_moves = m->offset_a + m->offset_b + 1;
		m->offset_ab = 0;
	}
}
