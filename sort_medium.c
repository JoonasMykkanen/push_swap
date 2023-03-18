/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	i;
	int	temp;

	i = s->size_a - 1;
	temp = s->a[i];
	while (i > 0)
	{
		if (temp > s->a[i - 1])
			return (1);
		temp = s->a[--i];
	}
	return (0);
}

static void	sort_b(t_stack *s)
{
	int	index;
	int	offset;

	if (is_sorted(s) == 0)
		return ;
	while (s->size_a > 3)
	{
		index = find_smallest(s);
		offset = index;
		if (offset >= s->size_a / 2)
		{
			offset = (s->size_a - 1) - index;
			while (offset-- > 0)
				ra(s);
			pb(s);
		}
		else
		{
			while (offset-- >= 0)
				rra(s);
			pb(s);
		}
	}
}

void	sort_medium(t_stack *s)
{
	sort_b(s);
	sort_small(s);
	while (s->size_b > 0)
		pa(s);
}
