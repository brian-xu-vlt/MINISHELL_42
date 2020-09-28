#include "minishell_bonus.h"

void		exit_routine_lexer(t_vector *word, t_vector *vct, t_vector *tmp,
								t_token *token)
{
	if (word != NULL)
		vct_del(&word);
	if (vct != NULL)
		vct_del(&vct);
	if (tmp != NULL)
		vct_del(&tmp);
	if (token != NULL)
	{
		free(token->data);
		token->type = 0;
	}
}
