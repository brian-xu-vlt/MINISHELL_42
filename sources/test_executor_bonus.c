#include "minishell_bonus.h"

static void	debug_print_mask(int mask)
{
	int			i;

	i = 0;
	ft_printf("Print mask : %d\n", mask);
	while (i <= 4)
		ft_printf("%d", (mask & (1 << i++)) != 0 ? 1 : 0);
	ft_printf("\n");
}

static void	clean(t_cmd *command)
{
	int			i;
	int			original_ac;
	int			open_flags;
	mode_t		mode_flags;
	t_vector	*file_path;
	int			fd_ret;

	fd_ret = 0;
	open_flags = 0;
	mode_flags = 0;
	i = 0;
	command->redirection = 0;
	original_ac = command->ac;
	while (i < original_ac)
	{
		if (ft_strequ(command->av[i], "<") == TRUE)
		{
			open_flags = O_RDONLY;
			if (is_absolute_path(command->fd_string[STDIN_FILENO]) == FALSE)
			{
				file_path = vct_new();
				if (file_path == NULL)
					exit_routine_le(ERR_MALLOC);
				vct_addstr(file_path, "/tmp/in/");
				vct_addstr(file_path, command->av[i + 1]);
				ft_strdel(&command->fd_string[STDIN_FILENO]);
				command->fd_string[STDIN_FILENO] = ft_strdup(vct_getstr(file_path));
				vct_del(&file_path);
			}
			fd_ret = open(command->fd_string[STDIN_FILENO], open_flags, mode_flags);
			ft_strdel(&command->av[i]);
			if (command->av[i + 1] != NULL)
				ft_strdel(&command->av[i + 1]);
			command->ac = i;
			if (fd_ret < 0)
			{
				command->redirection |= F_REDIRECT_FAILURE;
				print_set_errno(errno, NULL, command->fd_string[STDIN_FILENO], NULL);
			}
			else
				command->redirection |= F_REDIRECT_IN;
			close(fd_ret);
		}
		else if (ft_strequ(command->av[i], ">") == TRUE || ft_strequ(command->av[i], ">>") == TRUE)
		{
			mode_flags = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
			if (ft_strequ(command->av[i], ">>") == TRUE)
				open_flags = O_WRONLY | O_CREAT | O_APPEND;
			else
				open_flags = O_WRONLY | O_CREAT | O_TRUNC;
			if (is_absolute_path(command->fd_string[STDOUT_FILENO]) == FALSE)
			{
				file_path = vct_new();
				if (file_path == NULL)
					exit_routine_le(ERR_MALLOC);
				vct_addstr(file_path, "/tmp/out/");
				vct_addstr(file_path, command->av[i + 1]);
				ft_strdel(&command->fd_string[STDOUT_FILENO]);
				command->fd_string[STDOUT_FILENO] = ft_strdup(vct_getstr(file_path));
				vct_del(&file_path);
			}
			fd_ret  = open(command->fd_string[STDOUT_FILENO], open_flags, mode_flags);
			ft_strdel(&command->av[i]);
			if (command->av[i + 1] != NULL)
				ft_strdel(&command->av[i + 1]);
			command->ac = i;
			if (fd_ret < 0)
			{
				command->redirection |= F_REDIRECT_FAILURE;
				print_set_errno(errno, NULL, command->fd_string[STDOUT_FILENO], NULL);
			}
			else
				command->redirection |= F_REDIRECT_OUT;
			if (open_flags & O_APPEND)
				command->redirection |= F_REDIRECT_OUT_APPEND;
			close(fd_ret);
			debug_print_mask(command->redirection);
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
			clean(cursor_cmd->content);
			cursor_cmd = cursor_cmd->next;
		}
		cursor_job = cursor_job->next;
	}
	debug_jobs(jobs);
}

int			test_executor(t_list *jobs)
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
