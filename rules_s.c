/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	int	top;
	int	temp;

	if (s->size_a > 1)
	{
		top = s->size_a - 1;
		temp = s->a[top - 1];
		s->a[top - 1] = s->a[top];
		s->a[top] = temp;
	}
	s->operations++;
	ft_printf("sa\n");
}

void	sb(t_stack *s)
{
	int	top;
	int	temp;

	if (s->size_b > 1)
	{
		top = s->size_b - 1;
		temp = s->b[top - 1];
		s->b[top - 1] = s->b[top];
		s->b[top] = temp;
	}
	s->operations++;
	ft_printf("sb\n");
}

void	ss(t_stack *s)
{
	sa(s);
	sb(s);
	s->operations++;
	ft_printf("ss\n");
}
