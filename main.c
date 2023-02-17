
#include "push_swap.h"

static void	create_stack(stack *s, int argc, char **argv)
{
	int		i;
	int		l;
	char	**arr;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		s->a = ft_calloc(arr_size(arr), sizeof(int));
		if (s->a == NULL)
		{
			free(arr);
			ft_putstr_fd("Error", 2);
			exit(-1);
		}
		s->b = ft_calloc(arr_size(arr), sizeof(int));
		if (s->b == NULL)
		{
			free(arr);
			ft_putstr_fd("Error", 2);
			exit(-1);
		}
		l = arr_size(arr);
		s->stack_size = l;
		i = -1;
		while (arr[++i] != NULL)
			s->a[--l] = ft_atoi(arr[i]);
		free(arr);
	}
	else if (argc > 2)
	{
		s->stack_size = argc - 1;
		s->a = ft_calloc(argc - 1, sizeof(int));
		if (s->a == NULL)
			exit(-1);
		s->b = ft_calloc(argc - 1, sizeof(int));
		if (s->b == NULL)
			exit(-1);
		i = -1;
		while (argc > 1)
			s->a[++i] = ft_atoi(argv[--argc]);
	}
}

static void	clean_up(stack *s)
{
	free(s->a);
	free(s->b);
}

int	main(int argc, char **argv)
{
	stack	s;

	check_args(&s, argc, argv);
	create_stack(&s, argc, argv);
	check_duplicates(&s);
	clean_up(&s);
	ft_printf("\n");
	return (0);
}
