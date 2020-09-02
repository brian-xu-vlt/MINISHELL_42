/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:14:55 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/03 15:24:10 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void	initialisation(t_st_machine *machine)
{
	ft_bzero(machine->buffer, BUFFER_SIZE);
	machine->len = 0;
	machine->len_out += machine->option.len_conversion;
	machine->option.len_conversion = 0;
	machine->char_error = '\0';
	machine->state = LETTER;
	ft_bzero(&machine->option, sizeof(t_option));
}

char	*process_conversion(va_list *argptr, t_st_machine *machine)
{
	char	*new_str;

	new_str = NULL;
	if (machine->option.flag & CONV_C)
		new_str = c_conv(va_arg(*argptr, int), &machine->option);
	else if (machine->option.flag & CONV_S)
		new_str = s_conv(va_arg(*argptr, char *), &machine->option);
	else if ((machine->option.flag & CONV_D) || (machine->option.flag & CONV_I))
		new_str = di_conv(va_arg(*argptr, long), &machine->option);
	else if ((machine->option.flag & CONV_U)
			|| (machine->option.flag & CONV_XMIN)
			|| (machine->option.flag & CONV_XMAJ)
			|| (machine->option.flag & CONV_P))
		new_str = puxxmaj_conv(va_arg(*argptr, unsigned long),
								&machine->option);
	else if (machine->option.flag & CONV_PERCENT)
		new_str = c_conv('%', &machine->option);
	else if (machine->option.flag & CONV_N)
		new_str = n_conv(va_arg(*argptr, long *), &machine->option,
				machine->len_out);
	else if (machine->option.flag & CONV_ERROR)
		new_str = c_conv(machine->char_error, &machine->option);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}
