/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:51:43 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/28 14:20:13 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_valid(char *base)
{
	int			i;

	i = 1;
	if (base == NULL || ft_strlen(base) < 2)
		return (0);
	while (*base != '\0')
	{
		while (base[i] != '\0')
		{
			if (*base == base[i] || (base[i] == '+' || base[i] == '-'))
				return (0);
			i++;
		}
		i = 1;
		base++;
	}
	return (1);
}

static int		ft_locate_inbase(char c, char *base)
{
	size_t	rank;

	rank = 0;
	while (base[rank] != '\0' && base[rank] != c)
		rank++;
	if (base[rank] == '\0')
		rank = -1;
	return (rank);
}

static int		ft_convert(const char *str, char *base, size_t b_size)
{
	int		i;
	int		y;
	int		ret;
	int		rank;

	y = 0;
	i = 0;
	ret = 0;
	while (str[i] != '\0' && ft_isalnum(str[i]) != 0)
		i++;
	i--;
	while (i >= 0)
	{
		rank = ft_locate_inbase(str[i], base);
		if (rank == -1)
			return (-1);
		ret = (rank * ft_pow(b_size, y)) + ret;
		i--;
		y++;
	}
	return (ret);
}

int				ft_atoi_base(const char *str, char *base)
{
	int		ret;
	int		sign;

	if (str == NULL || ft_is_valid(base) == 0)
		return (0);
	while (*str != '\0')
	{
		if (ft_isalnum(*str) != 0 || *str == '-' || *str == '+')
		{
			while (str[1] != '\0' && ft_isalnum(str[1]) != 1)
				str++;
			break ;
		}
		str++;
	}
	if (*str == '\0')
		return (0);
	sign = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	ret = ft_convert(str, base, ft_strlen(base));
	if (ret == -1)
		return (0);
	ret = ret * sign;
	return (ret);
}
