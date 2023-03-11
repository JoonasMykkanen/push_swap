

// #include "push_swap.h"

// static void	calc_avg(stack *s, algo_data *a)
// {
// 	int	sum;
// 	int	index;

// 	sum = 0;
// 	index = -1;
// 	a->size_avg = 0;
// 	while (++index < s->size_a)
// 	{
// 		sum = sum + s->a[index];
// 	}
// 	a->avg_1 = sum / (s->size_a - 1);
// 	sum = 0;
// 	index = -1;
// 	while (++index < s->size_a)
// 	{
// 		if (s->a[index] < a->avg_1)
// 		{
// 			sum = sum + s->a[index];
// 			a->size_avg++;
// 		}
// 	}
// 	a->avg_2 = sum / a->size_avg;
// }

// static	int	find_smallest(stack *s)
// {
// 	int	temp;
// 	int	index;
// 	int	ret;

// 	temp = s->a[0];
// 	index = -1;
// 	while (++index < s->size_a)
// 	{
// 		if (s->a[index] <= temp)
// 		{
// 			temp = s->a[index];
// 			ret = index;
// 		}
// 	}
// 	return (ret);
// }

// static int find_biggest(stack *s, algo_data *a)
// {
// 	int	temp;
// 	int	index;
// 	int	ret;

// 	temp = s->a[0];
// 	index = -1;
// 	while (++index < s->size_a)
// 	{
// 		if (s->a[index] >= temp)
// 		{
// 			temp = s->a[index];
// 			ret = index;
// 		}
// 	}
// 	return (ret);
// }

// static void	second_half(stack *s, algo_data *a)
// {
// 	int index;
// 	int	offset;

// 	while (s->size_a > 0)
// 	{
// 		index = find_smallest(s);
// 		offset = index;
// 		// ft_printf("index: %d \n", index);
// 		if (index == 0)
// 		{
// 			rra(s);
// 			pb(s);
// 		}
// 		else if (offset >= s->size_a / 2)
// 		{
// 			offset = (s->size_a - 1) - index;	
// 			while (offset-- > 0)
// 				ra(s);
// 			pb(s);
// 		}
// 		else
// 		{
// 			while (offset-- >= 0)
// 				rra(s);
// 			pb(s);
// 		}
// 		// print_stack(s);
// 	}
// }

// static void	first_half(stack *s, algo_data *a)
// {
// 	int index;
// 	int	offset;

// 	while (s->size_b < a->size_avg)
// 	{
// 		index = find_biggest(s, a);
// 		offset = index;
// 		// ft_printf("index: %d \n", index);
// 		if (index == 0)
// 		{
// 			rra(s);
// 			pb(s);
// 		}
// 		else if (offset >= s->size_a / 2)
// 		{
// 			offset = (s->size_a - 1) - index;	
// 			while (offset-- > 0)
// 				ra(s);
// 			pb(s);
// 		}
// 		else
// 		{
// 			while (offset-- >= 0)
// 				rra(s);
// 			pb(s);
// 		}
// 		// print_stack(s);
// 	}
// }

// static void	push_back(stack *s)
// {
// 	int	top;
// 	int	bot;

// 	while (s->size_b > 0)
// 	{
// 		top = s->b[s->size_b - 1];
// 		bot = s->b[0];
// 		if (top < bot)
// 		{
// 			rrb(s);
// 			pa(s);
// 		}	
// 		else
// 			pa(s);
// 		// print_stack(s);
// 	}
// }

// void	sort_algo(stack *s)
// {
// 	algo_data a;

// 	calc_avg(s, &a);
// 	// ft_printf("avg1: %d, avg2 %d, size: %d \n", a.avg_1, a.avg_2, a.size_avg);
// 	// ft_printf("BEFORE \n");
// 	// print_stack(s);
// 	first_half(s, &a);
// 	// ft_printf("second half\n");
// 	second_half(s, &a);
// 	push_back(s);
// 	// ft_printf("AFTER \n");
// 	// print_stack(s);
// }