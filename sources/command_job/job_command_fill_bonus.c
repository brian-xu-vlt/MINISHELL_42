#include "minishell_bonus.h"

void	fill_name(char *str, t_cmd *cmd)
{
	static int count;

	if (count == 0)
	{
		cmd->av = (char **)malloc(sizeof(char *) * (cmd->ac + 1));
		if (cmd->av == NULL)
			return ; //ERROR
		cmd->av[cmd->ac] = NULL;
	}
	if (str == NULL)
		count = 0;
	else
	{
		cmd->av[count] = ft_strdup(str);
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
