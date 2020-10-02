#include "minishell_bonus.h"

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

static char *extract_data(size_t type, char *str, t_token *token, t_list **token_list)
{
	char	*ret;

	if ((type >= E_WORD && type < E_OPEN_BRACKET) || type == E_SIMPLE_QUOTE
			|| type == E_QUOTE)
	{
		if (quote_checker(str) == FAILURE)
			return ("failure");
		if (ft_strchr(str, '(') == NULL && ft_strchr(str, ')') == NULL)
			token->data = ft_strdup(str);
		else
		{
			if (ft_strchr(str, C_QUOTE) != NULL
					|| ft_strchr(str, C_SIMPLE_QUOTE) != NULL)
			{
				if (str[ft_strlen(str) - 1] == '(' || str[ft_strlen(str) - 1] == ')')
				{
					ret = handle_bracket(str, token_list);
					if (ret == NULL)
						return (NULL);
					return (ret);
				}
				token->data = ft_strdup(str);
				return (NULL);
			}
			ret = handle_bracket(str, token_list);
			if (ret == NULL)
				return (NULL);
			return (ret);
		}
	}
	return (NULL);
}

int			extract_token(t_list **token_list, char *str, size_t type)
{
	t_token	*token;
	t_list	*node;
	char	*ret;
	size_t	i;

	i = 0;
	token = (t_token *)malloc(sizeof(t_token));
	node = NULL;
	if (token == NULL)
		return (FAILURE);
	token->data = NULL;
	ret = extract_data(type, str, token, token_list);
	if (ret != NULL && ft_strequ(ret, "failure") == TRUE)
	{
		ft_lstdelone(node, NULL);
		free(node);
		return (FAILURE);
	}
	if (ret != NULL)
	{
		while (ret[i] != '\0')
		{
			token->data = NULL;
			token->type = ret[i] == '(' ? E_OPEN_BRACKET : E_CLOSE_BRACKET;
			ft_printf("token->data = %s\n", token->data); //DEBUG
			debug(token->type);//DEBUG
			ft_printf("\n");//DEBUG
			node = ft_lstnew(token);
			if (node == NULL)
			{
				ft_lstdelone(node, NULL);
				free(node);
				return (FAILURE);
			}
			i++;
		}
		return (SUCCESS);
	}
	token->type = type;
	ft_printf("token->data = %s\n", token->data); //DEBUG
	debug(token->type);//DEBUG
	ft_printf("\n");//DEBUG
	node = ft_lstnew(token);
	if (node == NULL)
	{
		ft_lstdelone(node, NULL);
		free(node);
		return (FAILURE);
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
