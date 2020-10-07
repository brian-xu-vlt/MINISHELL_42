#include "minishell_bonus.h"

int	verif_name(char *good, char *name)
{
	if (strcmp(good, name) != 0)
	{
		ft_printf("\033[31;01mERROR ON NAME\033[00m\n");
		ft_printf("good = %s	name = %s\n", good, name);//DEBUG
		return (false);
	}
	return (true);
}

int	verif_ac(int good, int ac)
{

}

int	verif_av(char **good, char **av)
{

}

int	verif_fd_string(char **good, char **fd_string)
{

}

int	verif_condition(int good, int condition)
{

}

int	verif_redirection(int good, int redirection)
{

}
