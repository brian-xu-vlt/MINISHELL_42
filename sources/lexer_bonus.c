#include "minishell_bonus.h"

static ssize_t	get_double_token(t_vector *input)
{
	if (vct_chrnstr(input, DOUBLE_GREATER) == FALSE)
		return (E_DOUBLE_GREATER);
	else if (vct_chrnstr(input, OR) == FALSE)
		return (E_OR);
	else if (vct_chrnstr(input, AND) == FALSE)
		return (E_AND);
	return (NO_TYPE);
}

static size_t	get_token(char c)
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

static void		extract_token(t_list *token_list, char *str, size_t type)
{
	t_token	*token;
	t_list	*node;

	token = (t_token *)malloc(sizeof(t_token));
	node = NULL;
	if (token == NULL)
		exit_routine(token, node);// ERROR
	token->data = NULL;//in the case when it's not a word
	if (type >= E_WORD)
		token->data = ft_strdup(str);//in the case it's a word
	token->type = type;
	ft_printf("token->data = %s\n", token->data); //DEBUG
	printf("token.type = %u\n\n", token->type); //DEBUG
	node = ft_lstnew(token);//creation of the list de token (structure)
	if (node == NULL)
		exit_routine(token, node);// ERROR
	ft_lstadd_back(&token_list, node);//add the list to the node
}

static void		extract_token_word(t_list *token_list, t_vector *vct)
{
	if (vct_chr(vct, EXP) != FAILURE && vct_chr(vct, ASSIGN) == FAILURE)
		extract_token(token_list, vct_getstr(vct), E_EXP);
	else if (vct_chr(vct, ASSIGN) != FAILURE && vct_chr(vct, ASSIGN) != 0)
		extract_token(token_list, vct_getstr(vct), E_ASSIGN);
	else
		extract_token(token_list, vct_getstr(vct), E_WORD);
	vct_clear(vct);
}

static void		no_word(t_list *token_list, t_vector *word, size_t type)
{
	if (vct_getlen(word) != 0)//if char not word but the c/s before was a word
		extract_token_word(token_list, word);//we extract the word token
	if (type != E_SPACE && type != E_TAB)
		extract_token(token_list, NULL, type);
}

int		ft_lexer(t_vector *input, t_lexer *lexer)
{
	lexer->word = vct_new();
	lexer->token_list = NULL;
	while (vct_getlen(input) > 0)
	{
		lexer->type = get_double_token(input);
		if (lexer->type == FAILURE)
			return (FAILURE);
		if (lexer->type == NO_TYPE)
			lexer->type = get_token(vct_getcharat(input, 0));
		if (lexer->type < E_WORD)//if not a word
			no_word(lexer->token_list, lexer->word, lexer->type);
		else//if it's a word
			vct_add(lexer->word, vct_getcharat(input, 0));//add char to buffer word
		vct_pop(input);
		if (lexer->type > 7 && lexer->type < 11)
			vct_pop(input);
	}
	if (vct_getlen(lexer->word) != 0)//if the buffer word is not empty
		extract_token_word(lexer->token_list, lexer->word);
	return (SUCCESS);
}
