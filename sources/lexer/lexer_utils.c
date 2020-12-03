#include "minishell.h"

void		pop_input_word(t_vector *input, t_vector *word)
{
	vct_pop(input);
	safe_vct_add(word, vct_getfirstchar(input));
	vct_pop(input);
}

const char	*get_token_str(const int type)
{
	static const char *tokens[] = {SEPARATOR, PIPE, SIMPLE_QUOTE, QUOTE,
					LESS_THAN, GREATER_THAN, SPACE, TAB, DOUBLE_GREATER,
					OR, AND, S_WORD, S_EXP, S_ASSIGN, S_START, S_END
					, S_NO_TYPE};

	return (tokens[type]);
}

int			no_word(t_list **token_list, t_vector *word, size_t type)
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
