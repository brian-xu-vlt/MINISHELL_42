#include "minishell_bonus.h"

static void	del_token(void *token)
{
	t_token *tmp;

	tmp = token;
	if (tmp->data != NULL)
		free(tmp->data);
	free(tmp);
}

void		free_list_token(t_list **token)
{
	ft_lstdel(token, del_token);
}

void		exit_routine_lexer(t_vector *word, t_vector *vct, t_vector *tmp,
								t_token *token)
{
	(void)token;
	if (word != NULL)
		vct_del(&word);
	if (vct != NULL)
		vct_del(&vct);
	if (tmp != NULL)
		vct_del(&tmp);
}

void		free_token(t_list *node, t_token *token)
{
	ft_lstdelone(node, NULL);
	free(node);
	free(token->data);
	free(token);
}
