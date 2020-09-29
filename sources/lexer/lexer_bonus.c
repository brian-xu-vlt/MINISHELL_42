#include "minishell_bonus.h"

/*static void	debug(int type)
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
		ft_printf("token->type = E_START\n");
	if (type == 15)
		ft_printf("token->type = E_END\n");
}*/

int			extract_token(t_list **token_list, char *str, size_t type)
{
	t_token	*token;
	t_list	*node;

	token = (t_token *)malloc(sizeof(t_token));
	node = NULL;
	if (token == NULL)
		return (FAILURE);
	token->data = NULL;
	if ((type >= E_WORD && type < E_START) || type == E_SIMPLE_QUOTE || type == E_QUOTE)
	{
		if (quote_checker(str) == FAILURE)
		{
		//	ft_printf("str = %s\n", str);//DEBUG
			free(token);
			return (FAILURE);
		}	
		token->data = ft_strdup(str);
	}
	token->type = type;
	//ft_printf("token->data = %s\n", token->data); //DEBUG
	//debug(token->type);//DEBUG
	//ft_printf("\n");//DEBUG
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

static int	extract_token_word(t_list **token_list, t_vector *vct)
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

static int	no_word(t_list **token_list, t_vector *word, size_t type)
{
	int	ret;

	ret = SUCCESS;
	if (vct_getlen(word) != 0)
	{
		//ft_printf("EXTRACT WORD\n");//DEBUG
		ret = extract_token_word(token_list, word);
	}
	if (type != E_SPACE && type != E_TAB && type != E_SIMPLE_QUOTE && type != E_QUOTE)
	{
		//ft_printf("EXTRACT OTHER");//DEBUG
		ret = extract_token(token_list, NULL, type);
	}
	return (ret);
}

static int	process_lexer(t_vector *input, t_list **token_list, t_vector *word)
{
	static ssize_t	type;
	int		ret;
	char	c;

	ret = 0;
	while ((c = vct_getfirstchar(input)) == ' ')
		vct_pop(input);
	type = get_double_token(input);
//	ft_printf("INPUT = %s\n", vct_getstr(input));//DEBUG
//	ft_printf("WORD = %s\n", vct_getstr(word));//DEBUG
	if (type == NO_TYPE)
		type = get_token(c);
	if (c == '\'' || c == '\"')
		type = E_WORD;
	//ft_printf("TYPE = %d\n", type);//DEBUG
	if (type < E_WORD)
	{
		ret = no_word(token_list, word, type);
		vct_pop(input);
		if (type > DOUBLE_TOKEN)
			vct_pop(input);
	}
	else
	{
		type = E_WORD;
		handle_assign_quote(input, word);
		if (vct_chr(word, '=') > 0)
			type = E_ASSIGN;
		else if (vct_getfirstchar(word) == '$')
			type = E_EXP;
		ret = extract_token(token_list, vct_getstr(word), type);
		vct_clear(word);
	}
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
			exit_routine_lexer(word, NULL, NULL, NULL);
			free_list_token(&token_list);
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
