#include "minishell_bonus.h"

int	get_tablen(char **av)
{
	(void)av;
	return (0);
}


int	next_is_end(t_list **token_list)
{
	t_list	*tmp_list;
	t_token	*token;

	tmp_list = *token_list;
	tmp_list = tmp_list->next;
	if (tmp_list == NULL)
		return (false);
	token = tmp_list->content;
	return (token->type == E_END ? true : false);
}

bool	is_job_sep(t_token *token)
{
	return (token->type == E_OR || token->type == E_AND
				|| token->type == E_SEPARATOR ? true : false);
}

bool	is_cmd_sep(t_token *token)
{
	return (is_job_sep(token) || token->type == E_PIPE);
}

int	next_is_cmd_sep(t_list *token_list)
{
	t_list	*tmp_list;
	t_token	*token;

	tmp_list = token_list;
	tmp_list = tmp_list->next;
	if (tmp_list == NULL)
		return (false);
	token = tmp_list->content;
	return (is_cmd_sep(token) == true ? true : false);
}
