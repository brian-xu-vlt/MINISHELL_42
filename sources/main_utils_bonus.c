#include "minishell.h"

void	usage(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: Minishell does not take any argument\n");
		exit(FAILURE);
	}
}

void	check_std_fd(void)
{
	struct stat	wstat;

	if (DEBUG_MODE != true)
	{
		if (isatty(STDOUT_FILENO) == false)
			exit_routine(EXIT_NO_TTY);
		if (isatty(STDIN_FILENO) == false)
			exit_routine(EXIT_NO_TTY);
	}
	if ((write(STDOUT_FILENO, "", 0) == FAILURE)
	|| (write(STDERR_FILENO, "", 0) == FAILURE)
	|| (fstat(STDIN_FILENO, &wstat) != 0))
		exit_routine(EXIT_NO_TTY);
}

t_data	*init_data_struct(void)
{
	t_data		*new_data;

	new_data = (t_data*)ft_calloc(1, sizeof(t_data));
	if (new_data == NULL)
		exit(FAILURE);
	get_data_struct(new_data);
	return (new_data);
}

int		exit_main(void)
{
	int			last_exit_status;
	t_data		*data;

	last_exit_status = get_env_value_int(get_env_list(GET), S_QUESTION_MARK);
	data = get_data_struct(GET);
	if (data != NULL)
	{
		if (data->cmd_line != NULL)
			vct_del(&data->cmd_line);
		exit_routine_line_edition(data->line_editor_data, EXIT_NORMAL);
		exit_routine_env();
		if (data->current_jobs != NULL)
			free_list_job(&data->current_jobs);
		free(data);
	}
	vct_readline(NULL, -42);
	return (last_exit_status);
}
