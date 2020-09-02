/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_x_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:14:50 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/03 15:14:52 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*not_mod_minus_x(char *new_str, t_option *origin,
									t_option *option, char *number)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(number);
	i = 0;
	if (origin->precision < origin->width || option->precision == option->width)
	{
		if (option->precision == 0 && option->width == len)
			ft_memset(new_str, option->flag & MOD_ZERO &&
						(option->flag & MOD_DOT) == FALSE ?
						'0' : ' ', option->width);
		else
			ft_memset(new_str, (option->flag & MOD_ZERO) &&
						option->precision < option->width &&
						origin->precision != len &&
						((option->flag & MOD_DOT) == FALSE) ?
						'0' : ' ', option->width);
		i = option->width;
	}
	ft_memset(new_str + i, '0', option->precision);
	memjoin_free(&new_str, number, (option->width + option->precision), len);
	new_str[option->precision + option->width + len] = '\0';
	return (new_str);
}

static char		*mod_minus_x(char *new_str, t_option *option, char *number)
{
	size_t	len;
	char	*str_width;

	len = ft_strlen(number);
	str_width = (char *)malloc(sizeof(char) * (option->width + 1));
	if (str_width == NULL)
		return (NULL);
	ft_memset(new_str, '0', option->precision);
	memjoin_free(&new_str, number, option->precision, len);
	ft_memset(str_width, ' ', option->width);
	memjoin_free(&new_str, str_width, (option->precision + len), option->width);
	new_str[option->precision + option->width + len] = '\0';
	free(str_width);
	return (new_str);
}

static size_t	xmin_and_len(t_option *option, int not_minus,
								char *str_not_minus, char *str_minus)
{
	if (option->flag & CONV_XMIN)
		ft_striter(not_minus == 1 ? str_not_minus : str_minus, ft_tolower);
	if (not_minus == 1 || not_minus == 0)
		return (ft_strlen(not_minus == 1 ? str_not_minus : str_minus));
	else
		return (1);
}

char			*strjoin_xminxmaj_conversion(char *new_str, t_option *origin,
											t_option *option, char *number)
{
	char	*str_not_minus;
	char	*str_minus;
	int		not_minus;

	str_not_minus = NULL;
	str_minus = NULL;
	not_minus = 0;
	if ((option->flag & MOD_MINUS) == FALSE)
	{
		str_not_minus = not_mod_minus_x(new_str, origin, option, number);
		not_minus++;
	}
	else
	{
		str_minus = mod_minus_x(new_str, option, number);
		if (str_minus == NULL)
			return (NULL);
	}
	option->len_conversion = xmin_and_len(option, not_minus, str_not_minus,
											str_minus);
	return (not_minus == 1 ? str_not_minus : str_minus);
}
