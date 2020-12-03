/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_subshell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:17:04 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:17:05 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process(t_cmd *cmd, int p_in[2], int p_out[2])
{
	int		ret;

	ret = 1;
	if (cmd->ac == 0 && cmd->count_assign != 0)
		assign_envp_content(cmd);
	if ((cmd->redirection & F_REDIRECT_FAILURE) == false)
	{
		signal_manager(SIG_MODE_DEFAULT);
		dup_pipes(cmd, p_in, p_out);
		ret = 1;
		if ((cmd->redirection & F_REDIRECT_FAILURE) == false)
		{
			if (is_builtin(cmd) == TRUE)
				ret = exec_builtin(cmd);
			else
			{
				export_envp(cmd->envp);
				ret = exec_binary(cmd);
			}
		}
	}
	ms_setenv_int(get_env_list(GET), "?", ret, F_OVERWRITE);
	exit_routine(EXIT_NORMAL);
}

void		exec_subshell(t_job *job, t_cmd *cmd, int p_in[2], int p_out[2])
{
	pid_t	pid;

	pid = fork_process();
	if (pid == 0)
		child_process(cmd, p_in, p_out);
	else if (pid > 0)
	{
		signal_manager(SIG_MODE_EXEC);
		job->last_pid = pid;
	}
}
