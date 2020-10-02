#include "minishell_bonus.h"

void	debug(int type)
{
	if (type == 0)
		ft_printf("token->type = %s\n", SEPARATOR);
	if (type == 1)
		ft_printf("token->type = %s\n", PIPE);
	if (type == 2)
		ft_printf("token->type = %s\n", SIMPLE_QUOTE);
	if (type == 3)
		ft_printf("token->type = %s\n", QUOTE);
	if (type == 4)
		ft_printf("token->type = %s\n", LESS_THAN);
	if (type == 5)
		ft_printf("token->type = %s\n", GREATER_THAN);
	if (type == 6)
		ft_printf("token->type = %s\n", SPACE);
	if (type == 7)
		ft_printf("token->type = %s\n", TAB);
	if (type == 8)
		ft_printf("token->type = %s\n", DOUBLE_GREATER);
	if (type == 9)
		ft_printf("token->type = %s\n", OR);
	if (type == 10)
		ft_printf("token->type = %s\n", AND);
	if (type == 11)
		ft_printf("token->type = WORD\n");
	if (type == 12)
		ft_printf("token->type = %c\n", EXP);
	if (type == 13)
		ft_printf("token->type = %c\n", ASSIGN);
	if (type == 14)
		ft_printf("token->type = %c\n", '(');
	if (type == 15)
		ft_printf("token->type = %c\n", ')');
	if (type == 16)
		ft_printf("token->type = E_START\n");
	if (type == 17)
		ft_printf("token->type = E_END\n");
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
	int	new_type;

	ret = SUCCESS;
	new_type = get_new_type(input);
	handle_assign_quote(input, word, token_list, new_type);
	type = E_WORD;
	if (vct_getlen(word) != 0)
	{
		if (vct_chr(word, '=') > 0)
			type = E_ASSIGN;
		else if (vct_getfirstchar(word) == '$')
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
	while ((c = vct_getfirstchar(input)) == ' ')
		vct_pop(input);
	if (vct_getlen(input) == 0)
		return (ret);
	type = get_double_token(input);
	if (type == NO_TYPE)
		type = get_token(c);
	if (c == '\'' || c == '\"')
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
			//exit_routine_lexer(word, NULL, NULL, NULL);
			//free_list_token(&token_list);
			return (NULL);
		}
	}
	if (vct_getlen(word) != 0)
	{
		if (extract_token_word(&token_list, word) == FAILURE)
			return (NULL);
	}
	vct_del(&word);
	extract_token(&token_list, NULL, E_END);
	return (token_list);
}
