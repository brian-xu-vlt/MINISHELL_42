#include "minishell_bonus.h"

int	fill_name(char *str, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->av = (char **)malloc(sizeof(char *) * (cmd->ac + 1));
		if (cmd->av == NULL)
			return (FAILURE); //ERROR
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

void	fill_assign(int flag, int count_ac, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->tab_assign = (size_t *)malloc(sizeof(size_t) * (cmd->count_assign));
		if (cmd->tab_assign == NULL)
			return ; //ERROR
	}
	if (flag == FAILURE)
		count = 0;
	else
	{
		cmd->tab_assign[count] = count_ac - 1;
		count++;
	}
}

void	fill_exp(int flag, int count_ac, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->tab_exp = (size_t *)malloc(sizeof(size_t) * (cmd->count_exp));
		if (cmd->tab_exp == NULL)
			return ; //ERROR
	}
	if (flag == FAILURE)
		count = 0;
	else
	{
		cmd->tab_exp[count] = count_ac - 1;
		count++;
	}
}

int	fill_ac(char **av)
{
	int	ac;

	ac = 0;
	while (av[ac] != NULL)
		ac++;
	return (ac);
}

int	count_ac(t_list **list)
{
	int	count;
	t_list	*cpy_list;
	t_token	*token;

	count = 0;
	cpy_list = *list;
	token = cpy_list->content;
	while (cpy_list != NULL)
	{
		token = cpy_list->content;
		if (is_cmd_sep(token) == true || token->type == E_START)
			cpy_list = cpy_list->next;
		else
			break ;
	}
	while (cpy_list != NULL)
	{
		token = cpy_list->content;
		if (is_cmd_sep(token) == true || token->type == E_END)
			return (count);
		count++;
		cpy_list = cpy_list->next;
	}
	return (count);
}

int	count_assign(t_list **list)
{
	int	count;
	t_list	*cpy_list;
	t_token	*token;

	count = 0;
	cpy_list = *list;
	token = cpy_list->content;
	while (cpy_list != NULL)
	{
		token = cpy_list->content;
		if (is_cmd_sep(token) == true || token->type == E_START)
			cpy_list = cpy_list->next;
		else
			break ;
	}
	while (cpy_list != NULL)
	{
		token = cpy_list->content;
		if (is_cmd_sep(token) == true || token->type == E_END)
			return (count);
		if (token->type == E_ASSIGN)
			count++;
		cpy_list = cpy_list->next;
	}
	return (count);
}

int	count_exp(t_list **list)
{
	int	count;
	t_list	*cpy_list;
	t_token	*token;

	count = 0;
	cpy_list = *list;
	token = cpy_list->content;
	while (cpy_list != NULL)
	{
		token = cpy_list->content;
		if (is_cmd_sep(token) == true || token->type == E_START)
			cpy_list = cpy_list->next;
		else
			break ;
	}
	while (cpy_list != NULL)
	{
		token = cpy_list->content;
		if (is_cmd_sep(token) == true || token->type == E_END)
			return (count);
		if (token->type == E_EXP)
			count++;
		cpy_list = cpy_list->next;
	}
	return (count);
}
