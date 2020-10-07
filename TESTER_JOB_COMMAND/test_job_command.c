#include "minishell_bonus.h"

static int	test1(int nb_job, int nb_command, t_cmd *cmd)
{
	int	ac1 = 1;
	char	*av1[1];
	char	*fd_string[3];
	int		ret;

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		av1[0] = "haha";
		fd_string[0] = "NULL";
		fd_string[1] = "NULL";
		fd_string[2] = "NULL";
		ret = verif_name(av1[0], cmd->name);
		ret = verif_ac(ac1, cmd->ac);
		ret = verif_av(av1, cmd->av);
		ret = verif_fd_string(fd_string, cmd->fd_string);
		ret = verif_condition(E_NONE, cmd->condition);
		ret = verif_redirection(false, cmd->redirection);
		return (false);
	}
	return (true);
}

void	hub_test(int nb_job, int nb_command, t_cmd *cmd, int nb_test)
{
	int	ret;

	ret = true;
	if (nb_test == 0)
	{
		ret = test1(nb_job, nb_command, cmd);
		if (ret == false)
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
	}
}
