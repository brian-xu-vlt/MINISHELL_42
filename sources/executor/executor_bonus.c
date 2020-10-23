#include "minishell_bonus.h"

static int	manage_exit_status(int wstatus, pid_t pid)
{
	int		ret;

	ret = 0;
	if (WIFEXITED(wstatus) == TRUE)
	{
		ret = WEXITSTATUS(wstatus);
		ft_printf("\nEXIT_MANAGER : Exit status == %i", ret);
	}
	else if (WIFSIGNALED(wstatus) == TRUE)
	{
		ret = WTERMSIG(wstatus);
		ft_printf("\nEXIT_MANAGER : PID %i Got a signal %i ", pid, ret);
		if (WCOREDUMP(wstatus) != FALSE)
			ft_printf("(core dumped)");
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
	{
		ret = WSTOPSIG(wstatus);
		ft_printf("\nEXIT_MANAGER : Got a STOPED by pid %d", ret);
	}
	ft_printf("\n");
	return (ret);
}

static int		exec_bin(const t_cmd *command, int p_in[2], int p_out[2])
{
	int		ret_value;

	ret_value = -1;
	execute_bin(command->name, command, p_in, p_out);
	if (ret_value != 0 || errno != 0)
		ret_value = 128 + ret_value;
	return (ret_value);
}

static void		close_pipe(int pipe_fd[2])
{
	if (pipe_fd[R_END] != UNSET)
	{
		close(pipe_fd[R_END]);
		pipe_fd[R_END] = UNSET;
	}
	if (pipe_fd[W_END] != UNSET)
	{
		close(pipe_fd[W_END]);	
		pipe_fd[W_END] = UNSET;
	}
}

void			executor(const t_job *job)
{
	size_t	i;
	int		ret_value;
	t_list	*cmd_cursor;
	int		p_in[2];
	int		p_out[2];
	pid_t	pid;
	int		wstatus;
	
	if (job == NULL || job->cmd_lst == NULL)
		return ;
	i = 0;
	ft_memset(p_in, UNSET, sizeof(int[2]));
	ft_memset(p_out, UNSET, sizeof(int[2]));
	cmd_cursor = job->cmd_lst;
	while (i < job->nb_cmd && cmd_cursor->content != NULL)
	{
	//	system("ls -la /proc/$$/fd");
		ret_value = 0;
		if (i < job->nb_cmd - 1)
			pipe(p_out);

		exec_bin(cmd_cursor->content, p_in, p_out);
/*		if (is_builtin(cmd_cursor->content) == TRUE)
			ret_value = exec_builtin(cmd_cursor->content, p_in, p_out);
		else
			exec_bin(cmd_cursor->content, p_in, p_out);
*/
		
		
		close_pipe(p_in);
		if (i < job->nb_cmd - 1)
			ft_memmove(p_in, p_out, sizeof(int[2]));
		else
			close_pipe(p_out);
		cmd_cursor = cmd_cursor->next;
		i++;
	}
	while ((pid = wait(&wstatus)) > -1);
	ms_setenv_int(get_env_list(GET), "?", ret_value, F_OVERWRITE);
	ft_printf("\n(exec) $? = %d\n", get_env_value_int(get_env_list(GET), "?"));
	manage_exit_status(wstatus, pid);
}
