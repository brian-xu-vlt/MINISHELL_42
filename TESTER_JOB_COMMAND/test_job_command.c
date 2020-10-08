#include "minishell_bonus.h"

static int	test1(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 1;
		char	*av[1];
		av[0] = "ls";
		fd_string[0] = NULL;
		fd_string[1] = NULL;
		fd_string[2] = NULL;
		ret = verif_name(av[0], cmd->name);
		if (ret == true)
			ret = verif_ac(ac, cmd->ac);
		if (ret == true)
			ret = verif_av(av, cmd->av, cmd->ac);
		if (ret == true)
			ret = verif_fd_string(fd_string, cmd->fd_string);
		if (ret == true)
			ret = verif_condition(E_NONE, cmd->condition);
		if (ret == true)
			ret = verif_redirection(false, cmd->redirection);
		return (ret);
	}
	if (nb_job == 1 && nb_command == 2)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = "cat";
		av[1] = "-e";
		fd_string[0] = NULL;
		fd_string[1] = NULL;
		fd_string[2] = NULL;
		ret = verif_name(av[0], cmd->name);
		if (ret == true)
			ret = verif_ac(ac, cmd->ac);
		if (ret == true)
			ret = verif_av(av, cmd->av, cmd->ac);
		if (ret == true)
			ret = verif_fd_string(fd_string, cmd->fd_string);
		if (ret == true)
			ret = verif_condition(E_NONE, cmd->condition);
		if (ret == true)
			ret = verif_redirection(false, cmd->redirection);
		return (ret);
	}
	if (nb_job == 2 && nb_command == 1)
	{
		int	ac = 1;
		char	*av[1];
		av[0] = "echo";
		fd_string[0] = NULL;
		fd_string[1] = NULL;
		fd_string[2] = NULL;
		ret = verif_name(av[0], cmd->name);
		if (ret == true)
			ret = verif_ac(ac, cmd->ac);
		if (ret == true)
			ret = verif_av(av, cmd->av, cmd->ac);
		if (ret == true)
			ret = verif_fd_string(fd_string, cmd->fd_string);
		if (ret == true)
			ret = verif_condition(E_YES_AND, cmd->condition);
		if (ret == true)
			ret = verif_redirection(false, cmd->redirection);
		return (ret);
	}
	if (nb_job == 3 && nb_command == 1)
	{
		int	ac = 5;
		char	*av[5];
		av[0] = "cat";
		av[1] = "-e";
		av[2] = "hey";
		av[3] = ">";
		av[4] = "prout";
		fd_string[0] = NULL;
		fd_string[1] = "prout";
		fd_string[2] = NULL;
		ret = verif_name(av[0], cmd->name);
		if (ret == true)
			ret = verif_ac(ac, cmd->ac);
		if (ret == true)
			ret = verif_av(av, cmd->av, cmd->ac);
		if (ret == true)
			ret = verif_fd_string(fd_string, cmd->fd_string);
		if (ret == true)
			ret = verif_condition(E_NONE, cmd->condition);
		if (ret == true)
			ret = verif_redirection(false, cmd->redirection);
		return (ret);
	}
	return (true);
}

int	hub_test(int nb_job, int nb_command, t_cmd *cmd, int nb_test)
{
	int	ret;

	ret = true;
	if (nb_test == 0)
	{
		ret = test1(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
			return (FAILURE);
		}
		return (SUCCESS);
	}
	return (SUCCESS);
}
