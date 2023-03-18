/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tiny(t_stack *s)
{
	if (s->a[1] > s->a[0])
	{
		sa(s);
	}
}

void	sort_small(t_stack *s)
{
	if (s->a[2] > s->a[1] && s->a[2] < s->a[0])
		sa(s);
	if (s->a[2] > s->a[1] && s->a[1] < s->a[0])
		ra(s);
	if (s->a[1] > s->a[0] && s->a[2] < s->a[1])
		rra(s);
	if (s->a[2] > s->a[1])
		sa(s);
	if (s->a[1] > s->a[0] && s->a[2] < s->a[1])
		rra(s);
}

void	sort(t_stack *s)
{
	if (s->size_a == 1)
		return ;
	else if (s->size_a == 2)
		sort_tiny(s);
	else if (s->size_a == 3)
		sort_small(s);
	else if (s->size_a < 10)
		sort_medium(s);
	else if (s->size_a >= 10)
		sort_algo(s);
}
