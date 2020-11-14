#include "minishell_bonus.h"

static void waiter(const t_job *job)
{
	pid_t pid;
	int wstatus;
	int exit_status;

	wstatus = 0;
	pid = SUCCESS;
	while (pid != FAILURE)
	{
		pid = wait(&wstatus);
		if (pid == job->last_pid)
		{
			exit_status = manage_subshell_exit_status(wstatus);
			ms_setenv_int(get_env_list(GET), "?", exit_status, F_OVERWRITE);
		}
	}
}

static void open_files_and_export_env(t_cmd *command)
{
	process_open_file(command);
	if (command->ac == 0 && command->count_assign != 0)
		export_envp_content(command);
}

static void execute_and_wait(t_job *job, t_cmd *cmd,
							 int p_in[2], int p_out[2])
{
	int ret;

	ret = execution_main_process(job, cmd, p_in, p_out);
	if (is_solo_builtin(job->nb_cmd, cmd) == TRUE)
		ms_setenv_int(get_env_list(GET), "?", ret, F_OVERWRITE);
	else
		waiter(job);
}

static void execution_loop(t_job *job, int p_in[2], int p_out[2])
{
	t_list *cmd_cursor;
	size_t cmd_index;
	int			ret_equ;

	cmd_index = 0;
	cmd_cursor = job->cmd_lst;
	while (cmd_cursor != NULL && cmd_cursor->content != NULL)
	{
		open_files_and_export_env(cmd_cursor->content);
		if (((t_cmd *)cmd_cursor->content)->av != NULL)
		{
			if (ft_strequ("cd", ((t_cmd *)cmd_cursor->content)->av[0]) == TRUE)
			{
				cd_builtin(((t_cmd *)cmd_cursor->content)->ac,
						   ((t_cmd *)cmd_cursor->content)->av, NULL);
				ft_printf("#############################################\n"); //DEBUG
			}
		}
		if (is_last_cmd(cmd_index, job->nb_cmd) == FALSE)
		{
			ms_pipe(p_out);
			execution_main_process(job, cmd_cursor->content, p_in, p_out);
			ft_memmove(p_in, p_out, sizeof(int[2]));
			ft_memset(p_out, UNSET, sizeof(int[2]));
		}
		else
			execute_and_wait(job, cmd_cursor->content, p_in, p_out);
		cmd_cursor = cmd_cursor->next;
		cmd_index++;
	}
}

void executor(t_job *job)
{
	int p_in[2];
	int p_out[2];
	if (is_valid_job(job) == TRUE)
	{
		ft_memset(p_in, UNSET, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		execution_loop(job, p_in, p_out);
	}
}
