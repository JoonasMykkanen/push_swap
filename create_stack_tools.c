/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_exit(t_stack *s, char **arr)
{
	free(s->a);
	free(s->b);
	ft_error(arr);
}

void	from_string(t_stack *s, int argc, char **argv)
{
	char	**arr;
	int		i;
	int		l;

	arr = ft_split(argv[1], ' ');
	if (arr == NULL)
		ft_error(arr);
	s->a = ft_calloc(arr_size(arr), sizeof(int));
	if (s->a == NULL)
		ft_error(arr);
	s->b = ft_calloc(arr_size(arr), sizeof(int));
	if (s->b == NULL)
		ft_error(arr);
	l = arr_size(arr);
	s->size_a = l;
	i = -1;
	while (arr[++i] != NULL)
	{
		if (fake_atoi(arr[i]) == 'f')
			ft_exit(s, arr);
		s->a[--l] = ft_atoi(arr[i]);
	}
	ft_free(arr);
}

void	from_individual(t_stack *s, int argc, char **argv)
{
	char	**arr;
	int		i;
	int		l;

	s->size_a = argc - 1;
	s->a = ft_calloc(argc - 1, sizeof(int));
	if (s->a == NULL)
		ft_error(arr);
	s->b = ft_calloc(argc - 1, sizeof(int));
	if (s->b == NULL)
		ft_error(arr);
	i = -1;
	while (argc > 1)
	{
		if (fake_atoi(argv[--argc]) == 'f')
		{	
			free(s->a);
			free(s->b);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		s->a[++i] = ft_atoi(argv[argc]);
	}
}
