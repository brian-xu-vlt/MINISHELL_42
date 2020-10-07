/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base_post.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:16:49 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/03 15:16:50 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	l_fill_str_post(char *str, long nb, size_t *size, long base)
{
	if (nb < 0)
		l_fill_str_post(str, nb * -1, size, base);
	else if (nb < base)
	{
		if (nb < 10)
			str[*size] = (char)nb + '0';
		else
			str[*size] = (char)nb % 10 + 'A';
		(*size)++;
	}
	else
	{
		l_fill_str_post(str, nb / base, size, base);
		l_fill_str_post(str, nb % base, size, base);
	}
}

char		*ft_ltoa_base_post(long nb, long base)
{
	size_t				size;
	long				tmp;
	char				*str;

	if (base < 2 || base > 16)
		return (NULL);
	size = 0;
	if (nb <= 0)
		size++;
	tmp = nb;
	while (tmp != 0)
	{
		tmp /= base;
		size++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	l_fill_str_post(str, nb, &size, base);
	str[size] = '\0';
	return (str);
}
