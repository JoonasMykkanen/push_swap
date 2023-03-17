/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:18:13 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/01 10:18:15 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_match(char *hayt_stack, char *needle, int i, int min)
{
	int		l;

	l = 0;
	while (min > 0)
	{
		if (hayt_stack[i] != needle[l])
			return (0);
		else
		{
			i++;
			l++;
			min--;
		}
	}
	return (1);
}

char	*ft_strnstr(const char *hayt_stack, const char *needle, size_t n)
{
	int		i;
	int		min;
	int		found;

	i = 0;
	found = 0;
	min = ft_strlen((char *)needle);
	if (needle[0] == '\0')
		return ((char *)hayt_stack);
	while (n > 0 && hayt_stack[i] != '\0')
	{	
		if (min > (int)n)
			return (NULL);
		if (hayt_stack[i] == needle[0])
		{
			found = check_match((char *)hayt_stack, (char *)needle, i, min);
			if (found == 1)
				return ((char *)&hayt_stack[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
