#include "minishell_bonus.h"

static void	clean(t_cmd *command)
{
	int		i;

	i = 0;
	while (command->av[i] != NULL)
	{
		if (ft_strequ(command->av[i], ">") == TRUE)
		{
			ft_strdel(&command->av[i]);
			if (command->av[i + 1] != NULL)
				ft_strdel(&command->av[i + 1]);
			command->ac = i;
			command->redirection = TRUE;
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
