#include "minishell_bonus.h"

static void	debug(int type)
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
}

static void	extract_token(t_list **token_list, char *str, size_t type)
{
	t_token	*token;
	t_list	*node;

	token = (t_token *)malloc(sizeof(t_token));
	node = NULL;
	/*if (token == NULL)
		exit_routine(token, node);//EXIT_ROUTINE*/
	token->data = NULL;
	if (type >= E_WORD || type == E_SIMPLE_QUOTE || type == E_QUOTE)
		token->data = ft_strdup(str);
	token->type = type;
	ft_printf("token->data = %s\n", token->data); //DEBUG
	debug(token->type);//DEBUG
	ft_printf("\n");//DEBUG
	node = ft_lstnew(token);
	/*if (node == NULL
		exit_routine(token, node);//EXIT_ROUTINE*/
	ft_lstadd_back(token_list, node);
}

static void	extract_token_word(t_list **token_list, t_vector *vct)
{
	if (vct_chr(vct, EXP) != FAILURE && vct_chr(vct, ASSIGN) == FAILURE)
		extract_token(token_list, vct_getstr(vct), E_EXP);
	else if (vct_chr(vct, ASSIGN) != FAILURE && vct_chr(vct, ASSIGN) != 0
			&& vct_chr(vct, ASSIGN) != (ssize_t)vct_getlen(vct) - 1)
		extract_token(token_list, vct_getstr(vct), E_ASSIGN);
	else
		extract_token(token_list, vct_getstr(vct), E_WORD);
	vct_clear(vct);
}

static int	no_word(t_list **token_list, t_vector *word, size_t type)
{
	if (vct_getlen(word) != 0)
		extract_token_word(token_list, word);
	if (type == E_SIMPLE_QUOTE)
		return (N_SIMPLE_QUOTE);
	if (type == E_QUOTE)
		return (N_QUOTE);
	if (type != E_SPACE && type != E_TAB)
		extract_token(token_list, NULL, type);
	return (FALSE);
}

t_list			*lexer(t_vector *input)
{
	t_list		*token_list;
	t_vector	*word;
	ssize_t		type;
	int			ret;
	size_t		len;

	word = vct_new();
	token_list = NULL;
	while (vct_getlen(input) > 0)
	{
		type = get_double_token(input);
		if (type == FAILURE)
			return (NULL);
		if (type == NO_TYPE)
			type = get_token(vct_getcharat(input, FIRST_CHAR));
		if (type < E_WORD)
			ret = no_word(&token_list, word, type);
		else
			vct_add(word, vct_getcharat(input, FIRST_CHAR));
		if (ret == N_SIMPLE_QUOTE || ret == N_QUOTE)
		{
			vct_pop(input);
			word = vct_cdup(input, ret == N_SIMPLE_QUOTE ? C_SIMPLE_QUOTE
								: C_QUOTE);
			vct_add(word, ret == N_SIMPLE_QUOTE ? C_SIMPLE_QUOTE : C_QUOTE);
			vct_addcharat(word, FIRST_CHAR, ret == N_SIMPLE_QUOTE
							? C_SIMPLE_QUOTE : C_QUOTE);
			extract_token(&token_list, vct_getstr(word), ret == N_SIMPLE_QUOTE
							? E_SIMPLE_QUOTE : E_QUOTE);
			len = vct_getlen(word);
			vct_clear(word);
			vct_popfrom(input, len - 1);
		}
		if (ret == FALSE)
			vct_pop(input);
		if (type > DOUBLE_TOKEN && type < EXP_ASSIGN)
			vct_pop(input);
		ret = FALSE;
	}
	if (vct_getlen(word) != 0)
		extract_token_word(&token_list, word);
	vct_del(&word);
	return (token_list);
}
