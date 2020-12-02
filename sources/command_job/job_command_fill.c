#include "minishell.h"

int		fill_name(t_token *token, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->av = (char **)malloc(sizeof(char *) * (cmd->ac + 1));
		if (cmd->av == NULL)
			exit_routine(EXIT_MALLOC);
		cmd->av[cmd->ac] = NULL;
		cmd->type = (enum e_token_type *)malloc(sizeof(enum e_token_type) *
						(cmd->ac + 1));
		if (cmd->type == NULL)
			exit_routine(EXIT_MALLOC);
	}
	if (token == NULL)
		count = 0;
	else
	{
		cmd->av[count] = ft_strdup(token->data == NULL
			&& (token->type == E_LESS_THAN || token->type == E_GREATER_THAN ||
				token->type == E_DOUBLE_GREATER)
			? get_data(token->type) : token->data);
		cmd->type[count] = token->type;
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
			exit_routine(EXIT_MALLOC);
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
			exit_routine(EXIT_MALLOC);
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
