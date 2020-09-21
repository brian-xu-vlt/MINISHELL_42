#include "minishell_bonus.h"

static void	print_prompt(void)
{
	ft_printf("SHELL > ");
}

static t_vector	*read_loop()
{
	t_vector	*input;

	input = vct_new();
	print_prompt();
	if (vct_readline(input, 0) <= 0)
		return (NULL);
	return (input);
}

static int	test(t_vector *input, t_list *lexer_list)
{
	lexer_list = lexer(input);
	if (lexer_list == NULL)
	{
		free_list(&lexer_list);
		vct_del(&input);
		return (FAILURE);
	}
	if (parser_token(lexer_list) == FALSE)
	{
		free_list(&lexer_list);
		vct_del(&input);
		return (FAILURE);
	}
	return (SUCCESS);
}

int		main(int ac, char **av, char **env)
{
	t_le	*le;
	t_vector	*input;
	t_list		*lexer_list;

	init_minishell();
	le = get_struct(GET);
	//init_env(env);
	(void)ac;
	(void)av;
	(void)env;
	input = vct_new();
	while (ft_strncmp(vct_getstr(le->cmd_line), "quit", 5) != 0)
	{
		vct_clear(le->cmd_line);
		/*if (BONUS_FLAG == TRUE)
		{
			line_editor();
			save_history();
			if (test(le->cmd_line, lexer_list) == FAILURE)
			{
				free_list(&lexer_list);
				vct_del(&input);
				return (EXIT_FAILURE);
			} 
		}*/
		//else
	//	{
			input = read_loop();
			if (input == NULL)
			{
				vct_del(&input);
				free_list(&lexer_list);
			}
			if (test(input, lexer_list) == FAILURE)
			{
				free_list(&lexer_list);
				vct_del(&input);
				return (EXIT_FAILURE);
			}
	//	}
		if (ft_strncmp(vct_getstr(le->cmd_line), "history", 8) == 0)
			print_history();
	}
	exit_routine_le(NULL);
	vct_del(&input);
	free_list(&lexer_list);
	return (EXIT_SUCCESS);
}
