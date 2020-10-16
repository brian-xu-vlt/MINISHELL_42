/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:32:31 by Brian             #+#    #+#             */
/*   Updated: 2020/03/01 13:13:05 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_valid(char *base)
{
	int						i;
	int						j;

	j = 0;
	i = 0;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			if (base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static size_t	ft_base_size(char *base)
{
	size_t					b_size;

	b_size = 0;
	while (base[b_size])
		b_size++;
	if (b_size <= 1)
		return (0);
	return (b_size);
}

static size_t	ft_nb_size(long long int nb_val, size_t b_size)
{
	size_t					len;

	len = 0;
	while (nb_val > 0)
	{
		nb_val = nb_val / b_size;
		len++;
	}
	return (len);
}

static char		*ft_fill(unsigned long long n_val, int sign, int i, char *base)
{
	size_t					b_size;
	char					*ret;

	b_size = ft_base_size(base);
	if (!(ret = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	i--;
	while (n_val > 0 && i >= 0)
	{
		ret[i] = base[n_val % b_size];
		n_val = n_val / b_size;
		i--;
	}
	if (sign == -1)
		ret[i] = '-';
	return (ret);
}

char			*ft_itoa_base(long long int nb, char *base)
{
	int						len;
	int						sign;
	unsigned long long int	nb_val;

	sign = 1;
	if (base == NULL || ft_is_valid(base) == 0)
		return (NULL);
	if (nb < 0)
		sign = -1;
	nb_val = nb * sign;
	len = ft_nb_size(nb_val, ft_base_size(base));
	if (sign == -1)
		len++;
	if (nb_val == 0)
		return (ft_strdup("0"));
	return (ft_fill(nb_val, sign, len, base));
}
