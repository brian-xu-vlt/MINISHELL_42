#include "minishell_bonus.h"

static void	child_process(t_cmd *cmd, int p_in[2], int p_out[2])
{
	int		ret;

	if (get_struct(GET)->stdout_stat != SUCCESS)
		close(STDOUT_FILENO);
	if (get_struct(GET)->stderr_stat != SUCCESS)
		close(STDOUT_FILENO);
	if ((cmd->redirection & F_REDIRECT_FAILURE) == TRUE)
		exit_routine_le(ERR_NO_MESSAGE);
	signal_manager(SIG_MODE_DEFAULT);
	dup_pipes(cmd, p_in, p_out);
	ret = 1;
	if ((cmd->redirection & F_REDIRECT_FAILURE) == FALSE)
	{
		if (is_builtin(cmd) == TRUE)
			ret = exec_builtin(cmd);
		else
		{
			export_envp(cmd->envp);
			ret = exec_binary(cmd);
		}
	}
	exit(ret);
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
