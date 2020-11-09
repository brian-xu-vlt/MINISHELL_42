#include "minishell_bonus.h"

static void	print_prompt(void)
{
	ft_printf("SHELL > ");
}

static void	read_loop(t_vector *cmd_line)
{
	print_prompt();
	vct_readline(cmd_line, 0);
}

static void	usage(int ac, char **av)
{
	(void)ac;
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

int			main(int ac, char **av)
{
	t_vector	*cmd_line;
	t_list		*jobs;

	usage(ac, av);
	init_env();
	cmd_line = vct_new();
	if (cmd_line == NULL)
		exit_routine_le(ERR_MALLOC);
	init_line_editor(cmd_line);
	jobs = NULL;
	while (1)
	{
		signal_manager(SIG_MODE_CMD_LINE);
		if (DEBUG_MODE == TRUE)
			read_loop(cmd_line);
		else
			line_editor();
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
	}
	exit_routine_le(NULL);
	free_list_job(&jobs);
	return (EXIT_SUCCESS);
}
