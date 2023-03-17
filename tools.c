/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_up(t_stack *s)
{
	free(s->a);
	free(s->b);
}

int	arr_size(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
		;
	return (i);
}

int	find_smallest(t_stack *s)
{
	int	temp;
	int	index;
	int	ret;

	temp = s->a[0];
	ret = 0;
	index = -1;
	while (++index < s->size_a)
	{
		if (s->a[index] <= temp)
		{
			temp = s->a[index];
			ret = index;
		}
	}
	return (ret);
}

void	init(t_stack *s)
{
	s->size_b = 0;
	s->operations = 0;
}
