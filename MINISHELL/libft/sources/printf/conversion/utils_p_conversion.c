/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:15:01 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/03 15:15:02 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_p_width(t_option *option, size_t len)
{
	if (option->width > len && option->width > option->precision)
	{
		if (len > option->precision)
			option->width = option->width > (len + 2) ?
				option->width - (len + 2) : 0;
		else
			option->width = option->width - (option->precision + 2);
	}
	else
		option->width = 0;
}

void	initialisation_wipre_p_conversion(t_option *option,
											t_option *cpy_option, size_t len,
											unsigned long p)
{
	if ((option->flag & MOD_ZERO))
		option->width = 0;
	else
		get_p_width(option, len);
	if (p == 0 && cpy_option->width != 0 && len == 1 &&
			(option->flag & MOD_ZERO))
		option->precision = cpy_option->width - 2 - len;
	else
		option->precision = option->precision <= len ?
								0 : option->precision - len;
}

size_t	initialisation_p_conversion(t_option *option, t_option *cpy_option,
										char **number, unsigned long p)
{
	cpy_option->flag = option->flag;
	cpy_option->precision = option->precision;
	cpy_option->width = option->width;
	*number = ft_ultoa_base(p, 16);
	return (ft_strlen(*number));
}

char	*p_is_zero(t_option *option, t_option *cpy_option)
{
	char		*str_pzero;
	const char	*pre_string = "0x";

	option->width = cpy_option->width - 2;
	if (cpy_option->width != 0)
	{
		str_pzero = (char *)malloc(sizeof(char) * (cpy_option->width + 2));
		if (str_pzero == NULL)
		{
			option->len_conversion = 0;
			return (NULL);
		}
		str_pzero = strjoin_p_conversion(str_pzero, cpy_option, option, "\0");
		if (str_pzero == NULL)
			return (NULL);
		else
			return (str_pzero);
	}
	option->len_conversion = 2;
	return (ft_strdup(pre_string));
}
