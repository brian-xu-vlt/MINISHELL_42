/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:15:07 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/03 15:15:08 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	initialisation_x_conversion(t_option *option, t_option *cpy_option,
										char **number, unsigned long x)
{
	cpy_option->width = option->width;
	cpy_option->precision = option->precision;
	*number = ft_ultoa_base(x, 16);
	return (ft_strlen(*number));
}

int		string_str_zero(t_option *option, t_option *cpy_option, unsigned int x,
							size_t len)
{
	return ((((cpy_option->precision == 0 && option->width == 0) ||
			(cpy_option->precision == 0 && option->width == len) ||
			(cpy_option->precision == 0 &&
			option->width > cpy_option->precision)) && x == 0 && len == 1 &&
			option->flag & MOD_DOT) == TRUE ? TRUE : FALSE);
}

void	get_width_x(t_option *option, size_t len)
{
	if (option->width > len && option->width > option->precision)
	{
		if (len > option->precision)
			option->width -= len;
		else
			option->width -= option->precision;
	}
	else
		option->width = 0;
}

void	get_precision_x(t_option *cpy_option, t_option *option, size_t len)
{
	if ((cpy_option->width > len && len < option->precision) ||
			(cpy_option->width < option->precision && option->precision > len))
		option->precision -= len;
	else
		option->precision = 0;
}

char	*x_is_zero(t_option *option, t_option *cpy_option)
{
	char	*new_str;

	new_str = NULL;
	if (cpy_option->width != 0)
	{
		new_str = (char *)malloc(sizeof(char) * (cpy_option->width + 1));
		if (new_str == NULL)
		{
			option->len_conversion = 0;
			return (NULL);
		}
	}
	option->len_conversion = cpy_option->width != 0 ? cpy_option->width : 0;
	return (cpy_option->width != 0 ? ft_memset(new_str, ' ',
				cpy_option->width) : '\0');
}
