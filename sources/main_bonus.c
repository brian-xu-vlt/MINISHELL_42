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

int			main(int ac, char **av)
{
	t_vector	*cmd_line;
	t_list		*lexer_list;
	int			ret_parser;	

	usage(ac, av);
	init_env();
	cmd_line = vct_new();
	if (cmd_line == NULL)
		exit_routine_le(ERR_MALLOC);
	init_line_editor(cmd_line);
	//init_minishell();
	lexer_list = NULL;
	ret_parser = SUCCESS;
	while (1)
	{
		if (BONUS_FLAG == TRUE)
		{
			signal_manager(SIG_MODE_LINE_EDITOR);
			line_editor();
			save_history();
			ft_putstr_fd("\n", STDOUT_FILENO); //debug ?
			signal_manager(SIG_MODE_NORMAL);
		}
		else
			read_loop(cmd_line);
		if (ft_strncmp(vct_getstr(cmd_line), "exit", 5) == 0)
			break ;
	//	if (test_env(cmd_line) == FAILURE || test_executor(cmd_line) == FAILURE)
		signal_manager(SIG_MODE_EXEC);
		if (test_executor(cmd_line) == FAILURE)
		{
			exit_routine_le(NULL);
			return (EXIT_FAILURE);//ERREUR
		}
		lexer_list = test_lexer(cmd_line);
		if (lexer_list != NULL)
			ret_parser = test_parser(lexer_list);
		/*if (ret_parser != FALSE)
			jobs = test_jobs(lexer_list)*/
		free_list_token(&lexer_list);
		vct_clear(cmd_line);
	}
	exit_routine_le(NULL);
	return (EXIT_SUCCESS);
}
