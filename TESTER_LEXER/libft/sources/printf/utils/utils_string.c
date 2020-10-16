/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:16:58 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/22 17:37:51 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	memjoin_free(char **dest, char *src, size_t len_dest, size_t len_src)
{
	char	*str;
	size_t	len_str;

	str = NULL;
	len_str = len_dest + len_src;
	if (*dest != NULL && src != NULL)
	{
		str = (char *)malloc(sizeof(char) * (len_str + 1));
		if (str != NULL)
		{
			ft_memcpy(str, *dest, len_dest);
			ft_memcpy(str + len_dest, src, len_src);
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

void	fill_buffer(t_st_machine *machine, char c)
{
	if (machine->len + 1 >= BUFFER_SIZE)
	{
		memjoin_free(&machine->out, machine->buffer, machine->len_out,
						machine->len);
		machine->len_out += machine->len;
		machine->len = 0;
		ft_bzero(machine->buffer, BUFFER_SIZE);
	}
	else
	{
		machine->buffer[machine->len] = c;
		machine->len++;
	}
}

int		is_flag(const char *s)
{
	const char	*str_mod[] = {STR_HH, STR_LL, STR_H, STR_L, STR_MIN, STR_ZERO,
								STR_DOT};
	size_t		nb_mod;
	size_t		i;

	i = 0;
	nb_mod = sizeof(str_mod) / sizeof(char *);
	while (i < nb_mod)
	{
		if (ft_memcmp(s, str_mod[i], i < 2 ? 2 : 1) == 0)
			return ((int)i);
		i++;
	}
	return (-1);
}

int		is_conversion(const char c)
{
	const char	str_conv[] = STR_CONV;
	size_t		i;
	size_t		nb_conv;

	i = 0;
	nb_conv = sizeof(str_conv) / sizeof(char);
	while (i < nb_conv)
	{
		if (c == str_conv[i])
			return ((int)i);
		i++;
	}
	return (-1);
}
