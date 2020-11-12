#include "minishell_bonus.h"

const char	*get_token_str(const int type)
{
	static const char *tokens[] = {SEPARATOR, PIPE, SIMPLE_QUOTE, QUOTE,
					LESS_THAN, GREATER_THAN, SPACE, TAB, DOUBLE_GREATER,
					OR, AND, S_WORD, S_EXP, S_ASSIGN, S_START, S_END
					, S_NO_TYPE};

	return (tokens[type]);
}

void		debug(const int type)
{
	ft_printf("token->type = %s\n", get_token_str(type));
}

static int	no_word(t_list **token_list, t_vector *word, size_t type)
{
	int	ret;

	ret = SUCCESS;
	if (vct_getlen(word) != 0)
		ret = extract_token_word(token_list, word);
	if (type != E_SPACE && type != E_TAB && type != E_SIMPLE_QUOTE
			&& type != E_QUOTE)
		ret = extract_token(token_list, NULL, type);
	return (ret);
}

static int	process_lexer_no_word(ssize_t type, t_list **token_list,
		t_vector *word, t_vector *input)
{
	int	ret;

	ret = no_word(token_list, word, type);
	vct_pop(input);
	if (type > DOUBLE_TOKEN)
		vct_pop(input);
	return (ret);
}

static int	process_lexer_word_assign(ssize_t type, t_list **token_list,
		t_vector *word, t_vector *input)
{
	int	ret;

	ret = handle_assign_quote(input, word);
	// if ret == failure : \ cause error miss endl 
	type = E_WORD;
	if (vct_getlen(word) != 0)
	{
		if (vct_chr(word, ASSIGN) > 0)
			type = E_ASSIGN;
		else if (vct_getfirstchar(word) == EXP)
			type = E_EXP;
		ret = extract_token(token_list, vct_getstr(word), type);
	}
	vct_clear(word);
	return (ret);
}

static int	process_lexer(t_vector *input, t_list **token_list, t_vector *word)
{
	static ssize_t	type;
	int				ret;
	char			c;

	ret = 0;
	while (vct_getfirstchar(input) == C_SPACE
			|| vct_getfirstchar(input) == C_TAB)
		vct_pop(input);
	c = vct_getfirstchar(input);
	if (vct_getlen(input) == 0)
		return (ret);
	type = get_double_token(input);
	if (type == NO_TYPE)
		type = get_token(c);
	if (c == C_SIMPLE_QUOTE || c == C_QUOTE)
		type = E_WORD;
	if (type < E_WORD)
		ret = process_lexer_no_word(type, token_list, word, input);
	else
		ret = process_lexer_word_assign(type, token_list, word, input);
	return (ret);
}

t_list		*lexer(t_vector *input)
{
	t_list		*token_list;
	t_vector	*word;

	word = vct_new();
	token_list = NULL;
	if (extract_token(&token_list, NULL, E_START) == FAILURE)
		return (NULL);
	while (vct_getlen(input) > 0)
	{
		if (process_lexer(input, &token_list, word) == FAILURE)
		{
			free_list_token(&token_list);
			exit_routine_lexer(word, NULL, NULL, NULL);
			return (NULL);
		}
	}
	if (vct_getlen(word) != 0)
	{
		if (extract_token_word(&token_list, word) == FAILURE)
		{
			free_list_token(&token_list);
			exit_routine_lexer(word, NULL, NULL, NULL);
			return (NULL);
		}
	}
	vct_del(&word);
	extract_token(&token_list, NULL, E_END);
	return (token_list);
}
