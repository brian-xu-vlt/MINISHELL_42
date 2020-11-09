#include "minishell_bonus.h"

static void		child_process(const t_cmd *command, int p_in[2], int p_out[2])
{
	int		ret;

	export_envp_content(command);
	signal_manager(SIG_MODE_DEFAULT);
	dup_pipes(command, p_in, p_out);
	ret = 1;
	if ((command->redirection & F_REDIRECT_FAILURE) == FALSE)
	{
		if (is_builtin(command) == TRUE)
			ret = exec_builtin(command);
		else
			ret = exec_binary(command);
	}
	if (command->redirection & F_REDIRECT_IN)
		close(command->fd[STDIN_FILENO]);
	if (command->redirection & F_REDIRECT_OUT)
		close(command->fd[STDOUT_FILENO]);
	exit(ret);
}

static void		exec_subshell(t_job *job, const t_cmd *command,
													int p_in[2], int p_out[2])
{
	pid_t	pid;

	pid = fork_process();
	if (pid == 0)
		child_process(command, p_in, p_out);
	else if (pid > 0)
	{
		signal_manager(SIG_MODE_EXEC);
		job->last_pid = pid;
	}
}

int		execution_process(t_job *job, const t_cmd *command,
													int p_in[2], int p_out[2])
{
	int		ret;

	ret = 0;
	if (is_solo_builtin(job->nb_cmd, command) == TRUE)
		ret = exec_builtin(command);
	else
		exec_subshell(job, command, p_in, p_out);
	close_pipe_end(p_in[R_END]);
	close_pipe_end(p_in[W_END]);
	return (ret);
}
