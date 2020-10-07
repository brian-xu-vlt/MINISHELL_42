#include "minishell_bonus.h"

static void	test1(int nb_job, int nb_command, t_cmd *cmd)
{
	int	ret;
	char	**av;
	char	**fd_string;

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		av[0] = "ls";
		fd_string[0] = "NULL";
		fd_string[1] = "NULL";
		fd_string[2] = "NULL";
		verif_name("ls", cmd->name);
		verif_ac(1, cmd->ac);
		verif_av(av, cmd->av);
		verif_fd_string(fd_string, cmd->fd_string);
		verif_condition(E_NONE, cmd->condition);
		verif_redirection(false, cmd->redirection);
	}
}

void	hub_test(int nb_job, int nb_command, t_cmd *cmd, int nb_test)
{
	if (nb_test == 0)
		test1(nb_job, nb_command, cmd);
}
