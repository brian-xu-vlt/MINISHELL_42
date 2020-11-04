#include "minishell_bonus.h"

int		fill_name(char *str, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->av = (char **)malloc(sizeof(char *) * (cmd->ac + 1));
		if (cmd->av == NULL)
			return (FAILURE);
		cmd->av[cmd->ac] = NULL;
	}
	if (str == NULL)
		count = 0;
	else
	{
		cmd->av[count] = ft_strdup(str);
		count++;
	}
	return (count);
}

int		fill_assign(int flag, int count_ac, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->tab_assign = (size_t *)malloc(sizeof(size_t) *
							(cmd->count_assign));
		if (cmd->tab_assign == NULL)
			return (FAILURE);
	}
	if (flag == FAILURE)
		count = 0;
	else
	{
		cmd->tab_assign[count] = count_ac - 1;
		count++;
	}
	return (SUCCESS);
}

int		fill_exp(int flag, int count_ac, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->tab_exp = (size_t *)malloc(sizeof(size_t) * (cmd->count_exp));
		if (cmd->tab_exp == NULL)
			return (FAILURE);
	}
	if (flag == FAILURE)
		count = 0;
	else
	{
		cmd->tab_exp[count] = count_ac - 1;
		count++;
	}
	return (SUCCESS);
}

int		fill_ac(char **av)
{
	int	ac;

	ac = 0;
	while (av[ac] != NULL)
		ac++;
	return (ac);
}
