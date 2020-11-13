#include "minishell_bonus.h"

void	print_prompt(void)
{
	t_le	*le;
	char	*prompt_str;

	le = get_struct(GET);
	if (DEBUG_MODE == TRUE)
		prompt_str = PROMPT_SIMPLE;
	else
		prompt_str = PROMPT_LINE_EDITION;
	if (le->stdout_stat != FAILURE)
		ft_putstr_fd(prompt_str, STDOUT_FILENO);
	else if (le->stderr_stat != FAILURE)
		ft_putstr_fd(prompt_str, STDERR_FILENO);
}

static void	read_loop(t_vector *cmd_line)
{
	print_prompt();
	if (vct_readline(cmd_line, 0) == FAILURE)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine_le(ERR_NO_MESSAGE);
	}
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

static void	check_stdout_stderr(void)
{
	t_le	*le;

	le = get_struct(GET);
	if (write(STDOUT_FILENO, "", 1) == FAILURE)
		le->stdout_stat = FAILURE;
	if (write(STDERR_FILENO, "", 1) == FAILURE)
		le->stderr_stat = FAILURE;
}

static void	check_stdin(void)
{
	struct stat	wstat;

	if (fstat(STDIN_FILENO, &wstat) != 0)
	  	exit(0);
}

int			main(int ac, char **av)
{
	t_vector	*cmd_line;
	t_list		*jobs;

	check_stdin();
	usage(ac, av);
	init_env();
	cmd_line = vct_new();
	if (cmd_line == NULL)
		exit_routine_le(ERR_MALLOC);
	init_line_editor(cmd_line);
	check_stdout_stderr();
	jobs = NULL;
	while (1)
	{
		signal_manager(SIG_MODE_CMD_LINE);
		if (DEBUG_MODE == TRUE || get_struct(GET)->stdout_stat == FAILURE)
			read_loop(cmd_line);
		else
			line_editor();
		ft_putchar_fd('\n', STDERR_FILENO);
		jobs = process_minishell(cmd_line);
		if (jobs != NULL)
		{
			if (hub_cleaner(jobs) == FAILURE)
			{
				vct_clear(cmd_line);
				free_list_job(&jobs);
				exit_routine_le(NULL);
				return (EXIT_FAILURE);
			}
		}
		vct_clear(cmd_line);
		free_list_job(&jobs);
//	ft_printf("\t\t\t\t[LAST EXIT STATUS %3d]\r", get_env_value_int(get_env_list(GET), "?"));  //TODO remove
	}
	exit_routine_le(NULL);
	free_list_job(&jobs);
	return (EXIT_SUCCESS);
}
