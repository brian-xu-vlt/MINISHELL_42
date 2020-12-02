#include "minishell.h"

static int	read_loop(void)
{
	int			read_ret;
	t_data		*data;


	read_ret = 0;
	data = get_data_struct(GET);
	if (data == NULL)
		exit_routine(EXIT_MALLOC);
	init_prompt();
	errno = 0;
	if ((read_ret = vct_readline(data->cmd_line, 0)) == FAILURE)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine(EXIT_ERRNO);
	}
	return (read_ret);
}

static void	usage(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: Minishell does not take any argument\n");
		exit (FAILURE);
	}
}

static t_list	*process_minishell(t_vector *cmd_line)
{
	t_list		*lexer_list;
	t_list		*jobs;
	int			ret_parser;

	lexer_list = NULL;
	jobs = NULL;
	ret_parser = SUCCESS;
	lexer_list = test_lexer(cmd_line);
	if (lexer_list != NULL)
	{
		ret_parser = test_parser(lexer_list);
		if (ret_parser != FALSE)
			jobs = test_jobs(lexer_list);
		if (jobs == NULL)
			free_list_job(&jobs);
	}
	free_list_token(&lexer_list);
	return (jobs);
}

static void	check_std_fd(void)
{
	struct stat	wstat;

	// if (DEBUG_MODE != true)
	// {
	// if (isatty(STDOUT_FILENO) == false)										// BONUS ONLY
	// 	exit_routine(EXIT_NO_TTY);
	// if (isatty(STDIN_FILENO) == false)										// BONUS ONLY
	// 	exit_routine(EXIT_NO_TTY);
	// }

	if ((write(STDOUT_FILENO, "", 0) == FAILURE)
	|| (write(STDERR_FILENO, "", 0) == FAILURE)
	|| (fstat(STDIN_FILENO, &wstat) != 0))
		exit_routine(EXIT_NO_TTY);
}

static t_data	*init_data_struct(void)
{
	t_data		*new_data;

	new_data = (t_data*)ft_calloc(1, sizeof(t_data));
	if (new_data == NULL)
	 	exit (FAILURE);
	get_data_struct(new_data);
	return (new_data);
}

static int	reader(void)
{
	int			ret_read;

	ret_read = 0;
	if (DEBUG_MODE != TRUE)
	{
		signal_manager(SIG_MODE_CMD_LINE);
		ret_read = line_editor();
	}
	else
	{
		signal_manager(SIG_MODE_CMD_LINE_NO_BONUS);
		ret_read = read_loop();
	}
	return (ret_read);
}

static int exit_main()
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

int			main(int ac, char **av)
{
	t_vector	*cmd_line;
	t_list		*jobs;
	t_data		*data;
	int			ret_read;

	check_std_fd();
	usage(ac, av);

	data = init_data_struct();

	jobs = NULL;
	ret_read = 1;
	cmd_line = safe_vct_new();
	data->cmd_line = cmd_line;

	init_env();

	if (DEBUG_MODE != TRUE)
		data->line_editor_data = init_line_editor(cmd_line);

	while (ret_read > 0)
	{
		ret_read = reader();
		if (vct_getlen(cmd_line) > 0)
		{
			jobs = process_minishell(cmd_line);
			if (jobs != NULL)
			{
				data->current_jobs = jobs;
				if (hub_cleaner(jobs) == FAILURE)
					exit_routine(EXIT_MALLOC);
				free_list_job(&jobs);
				data->current_jobs = NULL;
				vct_clear(cmd_line);
			}
		}
	}
	if (DEBUG_MODE != true)
		ft_dprintf(STDERR_FILENO, "%s\n", EXIT);
	return (exit_main());
}
