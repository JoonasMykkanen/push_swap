/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->a[0];
	while (i < s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->size_a - 1] = temp;
	s->operations++;
	ft_printf("rra\n");
}

void	rrb(t_stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->b[0];
	while (i < s->size_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->size_b - 1] = temp;
	s->operations++;
	ft_printf("rrb\n");
}

static void	rr_rra(t_stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->a[0];
	while (i < s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->size_a - 1] = temp;
}

static void	rr_rrb(t_stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->b[0];
	while (i < s->size_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->size_b - 1] = temp;
}

void	rrr(t_stack *s)
{
	rr_rra(s);
	rr_rrb(s);
	s->operations++;
	ft_printf("rrr\n");
}
