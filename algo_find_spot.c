/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_find_spot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_rotate(t_stack *s, int *smallest, int *delta, int *index)
{
	*smallest = s->a[find_smallest(s)];
	while (s->a[s->size_a - 1] != *smallest && *delta < s->size_a)
	{
		*delta += 1;
		fake_ra(s);
	}
	*index = 0;
}

static void	loop(t_stack *s, int *index, int *spot_holder, int value)
{
	while (*index < s->size_a)
	{
		if (s->a[*index] < value)
		{
			if (*index == 0)
				*spot_holder = s->a[s->size_a - 1];
			else
				*spot_holder = s->a[*index - 1];
			break ;
		}
		*index += 1;
	}
}

static void	rotate_back(t_stack *s, int *delta)
{
	while (*delta > 0)
	{
		fake_rra(s);
		*delta -= 1;
	}
}

static void	find_spotholder(t_stack *s, int *index, int *spot_holder)
{
	*index = 0;
	while (s->a[*index] != *spot_holder && *index < s->size_a)
		*index += 1;
}

int	find_spot(t_stack *s, int value)
{
	int	delta;
	int	index;
	int	smallest;
	int	spot_holder;

	delta = 0;
	if (value < s->a[find_smallest(s)])
		spot_holder = s->a[find_smallest(s)];
	else if (value > s->a[find_biggest(s)])
	{
		if (find_biggest(s) == 0)
			spot_holder = s->a[0];
		else
			spot_holder = s->a[find_biggest(s) - 1];
	}
	else
	{
		start_rotate(s, &smallest, &delta, &index);
		loop(s, &index, &spot_holder, value);
		rotate_back(s, &delta);
	}
	find_spotholder(s, &index, &spot_holder);
	return (index);
}
