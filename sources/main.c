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

int			main(int ac, char **av, char **envp)
{
	t_vector	*cmd_line;	

	usage(ac, av);
	init_env(envp);
	cmd_line = vct_new();
	if (cmd_line == NULL)
		exit_routine_le(ERR_MALLOC);
	while (1)
	{
		read_loop(cmd_line);
		if (ft_strequ(vct_getstr(cmd_line), "exit") == TRUE)
			break ;
		if (test_env(cmd_line) == FAILURE)
		{
			exit_routine_le(NULL);
			return (EXIT_FAILURE);//ERREUR
		}
		vct_clear(cmd_line);
	}
	exit_routine_le(NULL);
	return (EXIT_SUCCESS);
}
