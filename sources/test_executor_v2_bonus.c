#include "minishell_bonus.h"

static void	clean(t_cmd *command)
{
	int			i;
	int			open_flags;
	mode_t		mode_flags;
	t_vector	*file_path;

	open_flags = 0;
	mode_flags = 0;
	i = 0;
	while (command->av[i] != NULL)
	{
		if (ft_strequ(command->av[i], ">") == TRUE || ft_strequ(command->av[i], ">>") == TRUE)
		{
			if (command->av[i + 1] == NULL)
				return ;
			mode_flags = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
			open_flags = O_WRONLY | O_CREAT | O_TRUNC;
			if (ft_strequ(command->av[i], ">") == TRUE)
					open_flags |= O_APPEND;
			file_path = vct_new();
			if (file_path == NULL)
				exit_routine_le(ERR_MALLOC);
			vct_addstr(file_path, "/tmp/toto/");
			vct_addstr(file_path, command->av[i + 1]);
			ft_printf("path ======== %s\n\n", vct_getstr(file_path));
			command->fd[STDOUT_FILENO] = open(vct_getstr(file_path), open_flags, mode_flags);
			vct_del(&file_path);
			ft_strdel(&command->av[i]);
			if (command->av[i + 1] != NULL)
				ft_strdel(&command->av[i + 1]);
			command->ac = i;
			if (command->fd[1] < 0)
				command->redirection = FAILURE;
		}
		i++;
	}
}

static void	fake_cleaner(t_list *jobs)
{
	t_list	*cursor_job;
	t_list	*cursor_cmd;

	cursor_job = jobs;
	while (cursor_job != NULL)
	{
		cursor_cmd = ((t_job *)cursor_job->content)->cmd_lst;
		while (cursor_cmd != NULL)
		{
			if (((t_cmd *)cursor_cmd->content)->fd_string[1] != NULL)
				clean(cursor_cmd->content);
			cursor_cmd = cursor_cmd->next;
		}
		cursor_job = cursor_job->next;
	}
	debug_jobs(jobs);
}

int			test_executor_v2(t_list *jobs)
{
	if (jobs == NULL)
		return (FAILURE);
	while (jobs != NULL)
	{
		fake_cleaner(jobs);
		if (jobs->content != NULL)
			executor(jobs->content);
		jobs = jobs->next;
	}
	return (SUCCESS);
}
