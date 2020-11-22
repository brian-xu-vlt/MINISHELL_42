#include "minishell_bonus.h"

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

	ret = SUCCESS;
	if (handle_assign_quote(input, word) == FAILURE)
		return (ERROR_NEWLINE);
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
	int			ret_process_lexer;

	word = vct_new();
	token_list = NULL;
	if (extract_token(&token_list, NULL, E_START) == FAILURE)
		return (NULL);
	while (vct_getlen(input) > 0)
	{
		ret_process_lexer = process_lexer(input, &token_list, word);
		if (handle_ret_lexer(ret_process_lexer, token_list, word, LEXER)
				== FAILURE)
			return (NULL);
	}
	if (handle_ret_lexer(0, token_list, word, TOKEN) == FAILURE)
		return (NULL);
	vct_del(&word);
	extract_token(&token_list, NULL, E_END);
	return (token_list);
}
