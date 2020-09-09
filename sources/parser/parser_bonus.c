#include "minishell_bonus.h"

static void	tab_redirect(enum e_token_type *valid_token)
{

}

static void	tab_word_exp_assign(enum e_token_type *valid_token)
{

}

static void	tab_pipe_or_and(enum e_token_type *valid_token)
{

}

static void	tab_start_separator(enum e_token_type *valid_token)
{

}

t_btree 	*parser_token(t_list *token_list)
{
	t_btree	*ast;
	static enum e_token_type valid_token[NB_TOKEN];

	ast = NULL;
	ft_bzero(&valid_token, sizeof(valid_token));
	tab_start_separator(valid_token);
	tab_pipe_or_and(valid_token);
	tab_word_exp_assign(valid_token);
	tab_redirect(valid_token);
	ft_printf("HEY CA PASSE\n");//DEBUG
	return (ast);
}
