/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s)
{
	int	temp;
	int	i;

	if (s->size_a > 1)
	{
		i = s->size_a;
		temp = s->a[i - 1];
		while (i >= 0)
		{
			s->a[i + 1] = s->a[i];
			i--;
		}
		s->a[0] = temp;
	}
	s->operations++;
	ft_printf("ra\n");
}

void	rb(t_stack *s)
{
	int	temp;
	int	i;

	if (s->size_b > 1)
	{
		i = s->size_b;
		temp = s->b[i - 1];
		while (i >= 0)
		{
			s->b[i + 1] = s->b[i];
			i--;
		}
		s->b[0] = temp;
	}
	s->operations++;
	ft_printf("rb\n");
}

static void	r_ra(t_stack *s)
{
	int	temp;
	int	i;

	if (s->size_a > 1)
	{
		i = s->size_a;
		temp = s->a[i - 1];
		while (i >= 0)
		{
			s->a[i + 1] = s->a[i];
			i--;
		}
		s->a[0] = temp;
	}
}

static void	r_rb(t_stack *s)
{
	int	temp;
	int	i;

	if (s->size_b > 1)
	{
		i = s->size_b;
		temp = s->b[i - 1];
		while (i >= 0)
		{
			s->b[i + 1] = s->b[i];
			i--;
		}
		s->b[0] = temp;
	}
}

void	rr(t_stack *s)
{
	r_ra(s);
	r_rb(s);
	s->operations++;
	ft_printf("rr\n");
}
