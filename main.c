
#include "push_swap.h"

static void	ft_free(char **garbage)
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

static void	ft_error(char **garbage)
{
	ft_free(garbage);
	ft_putstr_fd("Error", 2);
	exit(-1);
}

static void	create_stack(stack *s, int argc, char **argv)
{
	int		i;
	int		l;
	char	**arr;

	if (argc == 2)
	{
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
			s->a[--l] = ft_atoi(arr[i]);
		ft_free(arr);
	}
	else if (argc > 2)
	{
		s->size_a = argc - 1;
		s->a = ft_calloc(argc - 1, sizeof(int));
		if (s->a == NULL)
			ft_error(arr);
		s->b = ft_calloc(argc - 1, sizeof(int));
		if (s->b == NULL)
			ft_error(arr);
		i = -1;
		while (argc > 1)
			s->a[++i] = ft_atoi(argv[--argc]);
	}
}

static void	init(stack *s)
{
	s->size_b = 0;
	s->operations = 0;
}

int	main(int argc, char **argv)
{
	stack	s;

	check_args(&s, argc, argv);
	create_stack(&s, argc, argv);
	check_duplicates(&s);
	init(&s);
	print_stack(&s);
	sort(&s);
	print_stack(&s);
	clean_up(&s);
	if (s.operations == 0)
		ft_printf("\n");
	return (0);
}
