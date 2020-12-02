/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:33:28 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:34:33 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			history_builtin(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	ft_dprintf(STDERR_FILENO, "History Builtin is available with line edition "
"only...\n");
	return (BUILTIN_SUCCESS);
}
