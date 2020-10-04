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
	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: Minishell does not take any argument\n");
		exit (FAILURE);
	}
}

int			main(int ac, char **av, char **envp)
{
	t_vector	*cmd_line;	

	usage(ac, av);
	init_env(envp);
	cmd_line = vct_new();
	if (cmd_line == NULL)
		exit_routine_le(ERR_MALLOC);
	init_line_editor(cmd_line);
	while (1)
	{
		if (BONUS_FLAG == TRUE)
		{
			line_editor();
			save_history();
		}
		else
			read_loop(cmd_line);
		if (ft_strncmp(vct_getstr(cmd_line), "exit", 5) == 0)
			break ;
	//	if (test_env(cmd_line) == FAILURE || test_executor(cmd_line) == FAILURE)
		if (test_executor(cmd_line) == FAILURE)
		{
			exit_routine_le(NULL);
			return (EXIT_FAILURE);//ERREUR
		}
		vct_clear(cmd_line);
	}
	exit_routine_le(NULL);
	return (EXIT_SUCCESS);
}
