#include "minishell.h"

ssize_t		get_double_token(t_vector *input)
{
	if (vct_chrnstr(input, DOUBLE_GREATER) == FALSE)
		return (E_DOUBLE_GREATER);
	else if (vct_chrnstr(input, OR) == FALSE)
		return (E_OR);
	else if (vct_chrnstr(input, AND) == FALSE)
		return (E_AND);
	return (NO_TYPE);
}

size_t		get_token(char c)
{
	const char	*grammar = GRAMMAR;
	size_t		i;

	i = 0;
	while (i < NB_GRAMMAR)
	{
		if (c == grammar[i])
			return (i);
		i++;
	}
	return (E_WORD);
}

static int	extract_data(size_t type, char *str, t_token *token)
{
	if ((type >= E_WORD && type < E_START) || type == E_SIMPLE_QUOTE
			|| type == E_QUOTE)
	{
		if (quote_checker(str) == FAILURE)
			return (FAILURE);
		token->data = ft_strdup(str);
	}
	return (SUCCESS);
}

int			extract_token(t_list **token_list, char *str, size_t type)
{
	t_token	*token;
	t_list	*node;

	token = (t_token *)malloc(sizeof(t_token));
	node = NULL;
	if (token == NULL)
		exit_routine(EXIT_MALLOC);
	token->data = NULL;
	if (extract_data(type, str, token) == FAILURE)
	{
		free_token(node, token);
		return (FAILURE);
	}
	token->type = type;
	node = ft_lstnew(token);
	if (node == NULL)
	{
		free_token(node, token);
		exit_routine(EXIT_MALLOC);
	}
	ft_lstadd_back(token_list, node);
	return (SUCCESS);
}

int			extract_token_word(t_list **token_list, t_vector *vct)
{
	int	ret;

	ret = SUCCESS;
	if (vct_chr(vct, EXP) != FAILURE && vct_chr(vct, ASSIGN) == FAILURE)
		ret = extract_token(token_list, vct_getstr(vct), E_EXP);
	else if (vct_chr(vct, ASSIGN) != FAILURE && vct_chr(vct, ASSIGN) != 0)
		ret = extract_token(token_list, vct_getstr(vct), E_ASSIGN);
	else
		ret = extract_token(token_list, vct_getstr(vct), E_WORD);
	vct_clear(vct);
	return (ret);
}
