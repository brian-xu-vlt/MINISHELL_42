/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:19:55 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:19:56 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ms_tputs(const char *str, int affcnt, int (*putc_function)(int))
{
	int			ret;

	errno = 0;
	ret = tputs(str, affcnt, putc_function);
	if (ret == FAILURE)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		ft_putchar_fd('\r', STDERR_FILENO);
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine(EXIT_MS_TPUTS);
	}
	return (ret);
}

int		ms_putchar(int c)
{
	int			ret;

	errno = 0;
	ret = write(STDERR_FILENO, &c, 1);
	if (ret == FAILURE)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		ft_putchar_fd('\r', STDERR_FILENO);
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine(EXIT_MS_PUTCHAR);
	}
	return (ret);
}

t_le	*get_struct(t_le *mem)
{
	static t_le	*mem_backup = NULL;

	if (mem != NULL)
		mem_backup = mem;
	return (mem_backup);
}
