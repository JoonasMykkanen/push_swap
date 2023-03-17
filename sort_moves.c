/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_ab(t_stack *s, t_least *l)
{
	while (l->offset_ab-- > 0)
	{
		if (l->dir_a == 1)
			rr(s);
		else
			rrr(s);
	}
}

void	do_moves(t_stack *s, t_least l)
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
