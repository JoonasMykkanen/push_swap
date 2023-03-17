/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *s)
{
	if (s->size_b > 0)
	{
		s->a[s->size_a] = s->b[s->size_b - 1];
		s->size_a++;
		s->size_b--;
		s->operations++;
		ft_printf("pa\n");
	}
}

void	pb(t_stack *s)
{
	if (s->size_a > 0)
	{
		s->b[s->size_b] = s->a[s->size_a - 1];
		s->size_a--;
		s->size_b++;
		s->operations++;
		ft_printf("pb\n");
	}
}
