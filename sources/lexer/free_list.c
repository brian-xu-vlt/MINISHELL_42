#include "minishell.h"

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

int			handle_ret_lexer(int ret_process_lexer, t_list *token_list,
								t_vector *word, int flag)
{
	if (ret_process_lexer <= FAILURE && flag == LEXER)
	{
		if (ret_process_lexer == FAILURE)
		{
			ms_setenv_int(get_env_list(GET), S_QUESTION_MARK, 2, F_OVERWRITE);
			print_set_errno(0, ERR_SYNTAX, NULL, NULL);
		}
		free_list_token(&token_list);
		exit_routine_lexer(word, NULL, NULL, NULL);
		return (FAILURE);
	}
	if (vct_getlen(word) != 0 && flag == TOKEN)
	{
		if (extract_token_word(&token_list, word) == FAILURE)
		{
			handle_ret_lexer(0, token_list, word, TOKEN);
			free_list_token(&token_list);
			exit_routine_lexer(word, NULL, NULL, NULL);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
