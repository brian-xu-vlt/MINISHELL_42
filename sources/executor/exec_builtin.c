/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:57 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:16:58 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_exit(t_cmd *cmd)
{
	if (ft_strequ(cmd->name, "exit") == true
								&& cmd->ac >= 1 && cmd->solo_builtin == true)
		ft_dprintf(STDERR_FILENO, "%s\n", EXIT);
}

int			exec_builtin(t_cmd *cmd)
{
	int					i;
	int					ret_value;
	static const char	*builtin_names[NB_BUILTIN] = {
	"cd", "echo", "pwd", "exit", "env", "export", "unset", "history", "set" };
	static int			(*builtin[NB_BUILTIN])(int, char **, char **) = {
		cd_builtin, echo_builtin, pwd_builtin, exit_builtin, env_builtin,
		export_builtin, unset_builtin, history_builtin, set_builtin };

	i = 0;
	ret_value = 0;
	if ((cmd->redirection & F_REDIRECT_FAILURE) == TRUE)
		return (1);
	while (i < NB_BUILTIN)
	{
		if (ft_strequ((char *)cmd->name, (char *)builtin_names[i]) == TRUE)
		{
			print_exit(cmd);
			ret_value = (builtin[i])(cmd->ac, cmd->av, cmd->envp);
			if (ft_strequ(cmd->name, "exit") == true && ret_value == EXIT_FAIL)
				cmd->err_exit = true;
			return (ret_value);
		}
		i++;
	}
	return (0);
}
