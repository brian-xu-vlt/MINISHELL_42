#include "minishell_bonus.h"

static void	del_token(void *token)
{
	t_token *tmp;

	tmp = token;
	ft_strdel(&tmp->data);
	free(tmp);
}

void		free_list_token(t_list **token)
{
	ft_lstdel(token, del_token);
}
