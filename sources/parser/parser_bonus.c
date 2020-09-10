#include "minishell_bonus.h"

static void	tab_redirect(t_valid_token *token)
{
	static enum e_token_type	tab_valid[] = {E_SIMPLE_QUOTE, E_QUOTE,
												E_WORD, E_EXP, E_ASSIGN,
												NO_TYPE};
	
	token[E_LESS_THAN].next_token = tab_valid;
	token[E_GREATER_THAN].next_token = tab_valid;
	token[E_DOUBLE_GREATER].next_token = tab_valid;

}

static void	tab_word_exp_assign(t_valid_token *token)
{
	static enum e_token_type	tab_valid[] = {E_SEPARATOR, E_PIPE,
												E_SIMPLE_QUOTE, E_QUOTE,
												E_LESS_THAN, E_GREATER_THAN,
												E_DOUBLE_GREATER, E_OR, E_AND,
												E_WORD, E_EXP, E_ASSIGN, E_END,
												NO_TYPE};

	token[E_SIMPLE_QUOTE].next_token = tab_valid;
	token[E_QUOTE].next_token = tab_valid;
	token[E_WORD].next_token = tab_valid;
	token[E_EXP].next_token = tab_valid;
	token[E_ASSIGN].next_token = tab_valid;
}

static void	tab_pipe_or_and(t_valid_token *token)
{
	static enum e_token_type	tab_valid[] = {E_SIMPLE_QUOTE, E_QUOTE,
												E_LESS_THAN, E_GREATER_THAN,
												E_DOUBLE_GREATER, E_WORD,
												E_EXP, E_ASSIGN, NO_TYPE};
	
	token[E_PIPE].next_token = tab_valid;
	token[E_OR].next_token = tab_valid;
	token[E_AND].next_token = tab_valid;
}

static void	tab_start_separator(t_valid_token *token)
{
	static enum e_token_type	tab_valid[] = {E_SIMPLE_QUOTE, E_QUOTE,
												E_LESS_THAN, E_GREATER_THAN,
												E_DOUBLE_GREATER, E_WORD,
												E_EXP, E_ASSIGN, E_START, E_END,
												NO_TYPE};
	
	token[E_SEPARATOR].next_token = tab_valid;
	token[E_START].next_token = tab_valid;
}

t_btree 	*parser_token(t_list *token_list)
{
	t_btree	*ast;
	static t_valid_token valid_token[NB_TOKEN];

	ast = NULL;
	ft_bzero(&valid_token, sizeof(valid_token));
	tab_start_separator(valid_token);
	tab_pipe_or_and(valid_token);
	tab_word_exp_assign(valid_token);
	tab_redirect(valid_token);
	process_parser(token_list, valid_token);
	return (NULL);	
}
