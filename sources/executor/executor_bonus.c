#include "minishell_bonus.h"

static void		exec_subshell(const t_cmd *command, int p_in[2], int p_out[2])
{
	pid_t	pid;
	int		ret;

	pid = fork_process();
	if (pid == FAILURE) 						//implement error managment
		return ;
	else if (pid == 0)
	{
		signal_manager(SIG_MODE_DEFAULT);
		dup_pipes(command, p_in, p_out);
		if (is_builtin(command) == TRUE)
			ret = exec_builtin(command);
		else	
			ret = exec_binary(command);
		if (command->redirection & F_REDIRECT_IN)
			close(command->fd[STDIN_FILENO]);
		if (command->redirection & F_REDIRECT_OUT)
			close(command->fd[STDOUT_FILENO]);
		exit(ret);
	}
	else if (pid != 0 && pid != FAILURE)
	{
		signal_manager(SIG_MODE_EXEC);
		ms_setenv_int(get_env_list(GET), "!", (int)pid, F_OVERWRITE);
	}
}

static int		execution_process(const t_cmd *command, const int nb_cmd,
												int p_in[2], int p_out[2])
{
	int		ret;

	ret = 0;
	// open files with lila's functions
//	if (nb_cmd == 1 && command->name == NULL && command->env != NULL)
		//DO ASSIGNATIONS export_execution_context_env(command);
//	else if (ft_strequ(command->name, "exit") == TRUE)
	
	if ((command->redirection & F_REDIRECT_FAILURE) == FALSE)
	{
		if (is_solo_builtin(nb_cmd, command) == TRUE)
			ret = exec_builtin(command);
		else
			exec_subshell(command, p_in, p_out);
	}
	else
		return (-1);
	return (ret);
}

static void		waiter(const t_cmd *command, const int nb_cmd, int ret)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = SUCCESS;
	if (is_solo_builtin(nb_cmd, command) == TRUE)
		ms_setenv_int(get_env_list(GET), "?", ret, F_OVERWRITE);
	else
	{
		while (pid != FAILURE)
		{
			pid = wait(&wstatus);
			if (pid == get_env_value_int(get_env_list(GET), "!"))
				manage_exit_status(wstatus);
		}
	}
	ft_printf("\nJust set $? to = %d\n", get_env_value_int(get_env_list(GET), "?")); //to remove
}

static void		loop_commandes(const t_job *job, int p_in[2], int p_out[2])
{
	int		ret;
	size_t	i;
	t_list	*cmd_cursor;

	i = 0;
	cmd_cursor = job->cmd_lst;
	while (i < job->nb_cmd && cmd_cursor->content != NULL)
	{
		if (i < job->nb_cmd - 1)
			do_pipe(p_out);
		ret = execution_process(cmd_cursor->content, job->nb_cmd, p_in, p_out);
		close_pipe_end(p_in[R_END]);
		close_pipe_end(p_in[W_END]);
		if (i < job->nb_cmd - 1)
			ft_memmove(p_in, p_out, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		if (i >= job->nb_cmd - 1)
			waiter(cmd_cursor->content, job->nb_cmd, ret);
		cmd_cursor = cmd_cursor->next;
		i++;
	}
}

void			executor(const t_job *job)
{
	int		p_in[2];
	int		p_out[2];

	if (job != NULL && job->cmd_lst != NULL)
	{
		ft_memset(p_in, UNSET, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		loop_commandes(job, p_in, p_out);
	}
}
