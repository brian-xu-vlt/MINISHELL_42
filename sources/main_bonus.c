#include "minishell_bonus.h"

static void	print_prompt(void)
{
	ft_printf("SHELL > ");
}

static void	read_loop()
{
	t_le		*le;

	le = get_struct(GET);
	print_prompt();
	vct_readline(le->cmd_line, 0);
}

int		main(int ac, char **av, char **env)
{
	t_le		*le;
	t_list		*lexer_list;
	t_list		*jobs;
	int			ret_parser;
	
	(void)ac;
	(void)av;

	init_minishell();
	init_env(env);
	le = get_struct(GET);
	lexer_list = NULL;
	ret_parser = SUCCESS;
	while (1)
	{
		if (BONUS_FLAG == TRUE)
		{
			line_editor();
			save_history();
		}
		else
			read_loop();
		if (ft_strncmp(vct_getstr(le->cmd_line), "exit", 5) == 0)
			break ;
		lexer_list = test_lexer(le->cmd_line);
		/*if (lexer_list != NULL)
			ret_parser = test_parser(lexer_list);*/
		/*if (ret_parser != FALSE)
			jobs = test_jobs(lexer_list)*/
		free_list_token(&lexer_list);
		vct_clear(le->cmd_line);
	}
	exit_routine_le(NULL);
	return (EXIT_SUCCESS);
}
