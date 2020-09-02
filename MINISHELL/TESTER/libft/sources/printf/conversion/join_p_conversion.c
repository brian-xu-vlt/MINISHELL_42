/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_p_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:14:47 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/03 15:14:48 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			memjoin_free_option(char **dest, char *src, t_option *option)
{
	char	*str;
	size_t	len_str;

	str = NULL;
	len_str = option->len_dest + option->len_src;
	if (*dest != NULL && src != NULL)
	{
		str = (char *)malloc(sizeof(char) * (len_str + 1));
		if (str != NULL)
		{
			ft_memcpy(str, *dest, option->len_dest);
			if (ft_strncmp(src, "0X", 2) == SUCCESS)
				option->len_dest = option->width;
			ft_memcpy(str + option->len_dest, src, option->len_src);
			str[len_str] = '\0';
		}
	}
	else if (*dest == NULL)
		str = ft_memdup(src, len_str);
	else if (src == NULL)
		str = ft_memdup(*dest, len_str);
	free(*dest);
	*dest = str;
}

static size_t	initialisation_not_min(t_option *option, char *number)
{
	size_t	len_number;

	len_number = ft_strlen(number);
	option->len_dest = option->width + option->precision + len_number;
	option->len_src = 2;
	return (len_number);
}

static void		not_mod_minus_p(char **new_str, t_option *origin,
									t_option *option, char *number)
{
	size_t			i;
	size_t			len_number;
	static char		*str_zerox = "0X";

	len_number = initialisation_not_min(option, number);
	if (origin->precision < origin->width || (option->precision == 0 &&
				option->flag & MOD_DOT))
	{
		ft_memset(*new_str, ' ', option->width);
		memjoin_free_option(new_str, str_zerox, option);
		i = option->width + option->len_src;
	}
	else
	{
		memjoin_free_option(new_str, str_zerox, option);
		i = 2;
	}
	ft_memset(*new_str + i, '0', option->precision);
	memjoin_free(new_str, number, (option->width +
					option->precision + option->len_src), len_number);
	ft_striter(*new_str, ft_tolower);
	option->len_conversion = ft_strlen(*new_str);
}

static void		new_p_width(t_option *option, t_option *origin,
								size_t len_number)
{
	if (origin->width - 1 > len_number && origin->width >
			(origin->width - (len_number + 2)))
		option->width = origin->width - (len_number + 2);
	else
		option->width = 0;
}

char			*strjoin_p_conversion(char *new_str, t_option *origin,
										t_option *option, char *number)
{
	static char		*str_zerox = "0X";
	char			*str_width;
	size_t			len_number;

	len_number = ft_strlen(number);
	if ((option->flag & MOD_MINUS) == FALSE)
		not_mod_minus_p(&new_str, origin, option, number);
	else
	{
		free(new_str);
		new_str = NULL;
		str_width = (char *)malloc(sizeof(char) * (option->width + 1));
		if (str_width != NULL)
		{
			new_str = ft_strdup(str_zerox);
			new_p_width(option, origin, len_number);
			memjoin_free(&new_str, number, 2, len_number);
			ft_memset(str_width, ' ', option->width);
			memjoin_free(&new_str, str_width, 2 + len_number, option->width);
			free(str_width);
			ft_striter(new_str, ft_tolower);
			option->len_conversion = ft_strlen(new_str);
		}
	}
	return (new_str);
}
