/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 16:37:08 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/22 16:42:04 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int			ft_dprintf(int fd, const char *format, ...)
{
	t_st_machine		machine;
	va_list				argptr;
	int					ret;
	ssize_t				ret_printf;

	ft_bzero(&machine, sizeof(machine));
	va_start(argptr, format);
	ret = parser((char *)format, &argptr, &machine);
	va_end(argptr);
	memjoin_free(&machine.out, machine.buffer, machine.len_out, machine.len);
	machine.len_out += machine.len;
	ret_printf = write(fd, machine.out, machine.len_out);
	free(machine.out);
	return (ret != FAILURE ? (int)ret_printf : FAILURE);
}

int			ft_asprintf(char **ptr, const char *format, ...)
{
	t_st_machine		machine;
	va_list				argptr;
	int					ret;

	ft_bzero(&machine, sizeof(machine));
	va_start(argptr, format);
	ret = parser((char *)format, &argptr, &machine);
	va_end(argptr);
	memjoin_free(&machine.out, machine.buffer, machine.len_out, machine.len);
	machine.len_out += machine.len;
	if (ptr != NULL)
		*ptr = ft_strndup(machine.out, machine.len_out);
	free(machine.out);
	return (ret != FAILURE ? (int)machine.len_out : FAILURE);
}
