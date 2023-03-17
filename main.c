/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **garbage)
{
	int	i;

	i = -1;
	if (garbage != NULL)
	{
		while (garbage[++i] != NULL)
			free(garbage[i]);
		free(garbage);
	}
}

void	ft_error(char **garbage)
{
	ft_free(garbage);
	ft_putstr_fd("Error", 2);
	exit(-1);
}

static void	create_stack(t_stack *s, int argc, char **argv)
{
	if (argc == 2)
	{
		from_string(s, argc, argv);
	}
	else if (argc > 2)
	{
		from_individual(s, argc, argv);
	}
}

int	main(int argc, char **argv)
{
	t_stack	s;

	check_args(&s, argc, argv);
	create_stack(&s, argc, argv);
	check_duplicates(&s);
	init(&s);
	sort(&s);
	clean_up(&s);
	if (s.operations == 0)
		ft_printf("\n");
	return (0);
}
