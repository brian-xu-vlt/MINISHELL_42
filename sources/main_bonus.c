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

int		main(int ac, char **av, char **envp)
{
	t_le		*le;
	
	(void)ac;
	(void)av;

	init_minishell();
	init_env(envp);
	le = get_struct(GET);
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
		if (test(le->cmd_line) == FAILURE)
		{
			exit_routine_le(NULL);
			return (EXIT_FAILURE);//ERREUR
		}
		vct_clear(le->cmd_line);
	}
	exit_routine_le(NULL);
	return (EXIT_SUCCESS);
}
