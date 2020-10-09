#include "minishell_bonus.h"

static int	test9(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = "export";
		av[1] = "TEST=\"ls -l - a\"";
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
		int	ac = 2;
		char	*av[2];
		av[0] = "echo";
		av[1] = "$TEST";
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
	if (nb_job == 3 && nb_command == 1)
	{
		int	ac = 1;
		char	*av[1];
		av[0] = "$LS";
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
	return (true);
}

static int	test8(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 4;
		char	*av[4];
		av[0] = "export";
		av[1] = "var";
		av[2] = "cat=";
		av[3] = "Makefile";
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
		int	ac = 3;
		char	*av[3];
		av[0] = "grep";
		av[1] = ">";
		av[2] = ".";
		fd_string[0] = NULL;
		fd_string[1] = ".";
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

static int	test7(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 4;
		char	*av[4];
		av[0] = "echo";
		av[1] = "test";
		av[2] = ">";
		av[3] = "ls";
		fd_string[0] = NULL;
		fd_string[1] = "ls";
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
		av[0] = ">>";
		av[1] = "ls";
		fd_string[0] = NULL;
		fd_string[1] = "ls";
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
			ret = verif_redirection(true, cmd->redirection);
		return (ret);
	}
	if (nb_job == 1 && nb_command == 3)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = ">>";
		av[1] = "ls";
		fd_string[0] = NULL;
		fd_string[1] = "ls";
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
			ret = verif_redirection(true, cmd->redirection);
		return (ret);
	}
	if (nb_job == 2 && nb_command == 1)
	{
		int	ac = 4;
		char	*av[4];
		av[0] = "echo";
		av[1] = "test";
		av[2] = ">>";
		av[3] = "ls";
		fd_string[0] = NULL;
		fd_string[1] = "ls";
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
			ret = verif_redirection(true, cmd->redirection);
		return (ret);
	}
	if (nb_job == 3 && nb_command == 1)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = "cat";
		av[1] = "ls";
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
	return (true);
}

static int	test6(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = "export";
		av[1] = "TEST=LOL";
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
		int	ac = 2;
		char	*av[2];
		av[0] = "echo";
		av[1] = "$TEST$TEST$TEST=lol$TEST";
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
	return (true);
}

static int	test5(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 4;
		char	*av[4];
		av[0] = "echo";
		av[1] = "2";
		av[2] = ">>";
		av[3] = "out1";
		fd_string[0] = NULL;
		fd_string[1] = "out1";
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
			ret = verif_redirection(true, cmd->redirection);
		return (ret);
	}
	if (nb_job == 1 && nb_command == 2)
	{
		int	ac = 3;
		char	*av[3];
		av[0] = ">";
		av[1] = "out2";
		av[2] = ".";
		fd_string[0] = NULL;
		fd_string[1] = "out2";
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

static int	test4(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = "cat";
		av[1] = "/dev/random";
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
		int	ac = 3;
		char	*av[3];
		av[0] = "head";
		av[1] = "-n";
		av[2] = "1";
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
	if (nb_job == 1 && nb_command == 3)
	{
		int	ac = 3;
		char	*av[3];
		av[0] = "cat";
		av[1] = "-e";
		av[2] = ".";
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
	return (true);
}

static int	test3(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 4;
		char	*av[4];
		av[0] = "ls";
		av[1] = "prout";
		av[2] = ">";
		av[3] = "lol";
		fd_string[0] = NULL;
		fd_string[1] = "lol";
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
	if (nb_job == 2 && nb_command == 1)
	{
		int	ac = 3;
		char	*av[3];
		av[0] = "ls";
		av[1] = "<";
		av[2] = "prout";
		fd_string[0] = "prout";
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
		int	ac = 2;
		char	*av[2];
		av[0] = "echo";
		av[1] = "\"hey=pipi\"";
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
	if (nb_job == 4 && nb_command == 1)
	{
		int	ac = 3;
		char	*av[3];
		av[0] = "prout";
		av[1] = ">>";
		av[2] = "lol";
		fd_string[0] = NULL;
		fd_string[1] = "lol";
		fd_string[2] = NULL;
		ret = verif_name(av[0], cmd->name);
		if (ret == true)
			ret = verif_ac(ac, cmd->ac);
		if (ret == true)
			ret = verif_av(av, cmd->av, cmd->ac);
		if (ret == true)
			ret = verif_fd_string(fd_string, cmd->fd_string);
		if (ret == true)
			ret = verif_condition(E_NOT_OR, cmd->condition);
		if (ret == true)
			ret = verif_redirection(true, cmd->redirection);
		return (ret);
	}
	return (true);
}

static int	test2(int nb_job, int nb_command, t_cmd *cmd)
{
	int		ret;
	char	*fd_string[3];

	ret = true;
	if (nb_job == 1 && nb_command == 1)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = "echo";
		av[1] = "\"prout\"";
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
		int	ac = 4;
		char	*av[4];
		av[0] = "cat";
		av[1] = "hey";
		av[2] = "<";
		av[3] = "prout=hello";
		fd_string[0] = "prout=hello";
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
	if (nb_job == 2 && nb_command == 2)
	{
		int	ac = 2;
		char	*av[2];
		av[0] = "cat";
		av[1] = "$prout";
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
	return (true);
}

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
		}
	}
	if (nb_test == 1)
	{
		ret = test2(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	if (nb_test == 2)
	{
		ret = test3(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	if (nb_test == 3)
	{
		ret = test4(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	if (nb_test == 4)
	{
		ret = test5(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	if (nb_test == 5)
	{
		ret = test6(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	if (nb_test == 6)
	{
		ret = test7(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	if (nb_test == 7)
	{
		ret = test8(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	if (nb_test == 8)
	{
		ret = test9(nb_job, nb_command, cmd);
		if (ret == false)
		{
			ft_printf("NB_TEST = %d	NB_JOB = %d	NB_COMMAND = %d\n", nb_test,
						nb_job, nb_command);
		}
	}
	return (SUCCESS);
}
