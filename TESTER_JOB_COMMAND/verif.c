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
	if (good != ac)
	{
		ft_printf("\033[31;01mERROR ON AC\033[00m\n");
		ft_printf("good = %d	ac = %d\n", good, ac);//DEBUG
		return (false);
	}
	return (true);
}

int	verif_av(char **good, char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (strcmp(good[i], av[i]) != 0)
		{
			ft_printf("\033[31;01mERROR ON AV[%d]\033[00m\n", i);
			ft_printf("good[%d] = %s	av[%d] = %s\n", i, good[i], i, av[i]);//DEBUG
			return (false);
		}
		i++;
	}
	return (true);
}

int	verif_fd_string(char **good, char **fd_string)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (good[i] == NULL && fd_string[i] != NULL)
		{
			ft_printf("\033[31;01mERROR ON FD_STRING[%d]\033[00m\n", i);
			ft_printf("good[%d] = %s	fd_string[%d] = %s\n", i, good[i], i, fd_string[i]);//DEBUG
			return (false);
		}
		else if (good[i] != NULL && fd_string[i] == NULL)
		{
			ft_printf("\033[31;01mERROR ON FD_STRING[%d]\033[00m\n", i);
			ft_printf("good[%d] = %s	fd_string[%d] = %s\n", i, good[i], i, fd_string[i]);//DEBUG
			return (false);
		}
		else if (good[i] != NULL && fd_string[i] != NULL)
		{
			if (strcmp(good[i], fd_string[i]) != 0)
			{
				ft_printf("\033[31;01mERROR ON FD_STRING[%d]\033[00m\n", i);
				ft_printf("good[%d] = %s	fd_string[%d] = %s\n", i, good[i], i, fd_string[i]);//DEBUG
				return (false);
			}
		}
		i++;
	}
	return (true);
}

int	verif_condition(int good, int condition)
{
	if (good != condition)
	{
		ft_printf("\033[31;01mERROR ON CONDITION\033[00m\n");
		ft_printf("good = %d	condition = %d\n", good, condition);//DEBUG
		return (false);
	}
	return (true);
}

int	verif_redirection(int good, int redirection)
{
	if (good != redirection)
	{
		ft_printf("\033[31;01mERROR ON CONDITION\033[00m\n");
		ft_printf("good = %d	redirection = %d\n", good, redirection);//DEBUG
		return (false);
	}
	return (true);
}
