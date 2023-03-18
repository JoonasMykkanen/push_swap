/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	fake_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	sum;

	i = 0;
	sum = 0;
	neg = 1;
	while (((str[i] < 14 && str[i] > 8) || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		sum = sum * 10 + (str[i] - '0');
		if ((neg == -1 && sum > 2147483648) || (neg != -1 && sum > 2147483647))
			return ('f');
		i++;
	}
	return ('s');
}
