/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:32:41 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/12 10:21:51 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_fill_str(long n, char *str, size_t size)
{
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		size--;
		str[size] = n % 10 + 48;
		n /= 10;
	}
}

static size_t	ft_get_size_of_nbr(long n)
{
	size_t	size;

	size = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_get_size_of_nbr((long)n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
		ft_fill_str((long)n, str, size);
	return (str);
}
