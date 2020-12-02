#include "minishell.h"

int	count_ac(t_list **list)
{
	int		count;
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
	int		count;
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
	int		count;
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
