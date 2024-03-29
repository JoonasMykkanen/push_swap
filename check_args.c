/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *s)
{
	int	i;
	int	l;

	i = -1;
	l = -1;
	while (++i < s->size_a)
	{
		while (++l < s->size_a)
		{
			if (s->a[l] == s->a[i] && l != i)
			{
				ft_putstr_fd("Error\n", 2);
				free(s->a);
				free(s->b);
				exit(-1);
			}
		}
		l = -1;
	}
}

static int	check_each(int argc, char **argv)
{
	int	i;

	i = -1;
	while (--argc > 0)
	{
		while (argv[argc][++i] != '\0')
		{
			while (argv[argc][i] == ' ')
				i++;
			if (argv[argc][i] == '-')
				i++;
			if (ft_isdigit(argv[argc][i]) == 0)
				return (-1);
		}
		if (i == 0 && argv[argc][i] == '\0')
			return (-1);
		i = -1;
	}
	return (1);
}

void	check_args(t_stack *s, int argc, char **argv)
{
	if (argc < 2)
	{
		exit(-1);
	}
	if (check_each(argc, argv) < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
}
