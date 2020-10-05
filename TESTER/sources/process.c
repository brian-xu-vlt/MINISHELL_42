#include "tester.h"

size_t	g_nb_grammar_type = 0;
size_t	g_nb_data_type = 0;
size_t	g_nb_grammar_true_type = 0;
char	**g_grammar = NULL;
enum	e_token_type *g_data_type = NULL;


bool	is_data_type(enum e_token_type type)
{
	for (enum e_token_type i = 0; i < g_nb_data_type; i++)
	{
		if (type == g_data_type[i])
			return (true);
	}
	return (false);
}

void	add_to_list(t_list **head, enum e_token_type type, char *data)
{
	t_token *token;
	t_list	*node = NULL;

	token = (t_token *)malloc(sizeof(t_token));
	assert(token != NULL);
	token->type = type;
	token->data = NULL;
	if (is_data_type(type) == true)
	{
		token->data = ft_strdup(data);
		assert(token->data != NULL);
	}
	node = ft_lstnew(token);
	assert(node != NULL);
	ft_lstadd_back(head, node);
}

t_list *get_expected_list(char *expected)
{
	t_vector			*expected_vct;
	t_vector			*split = NULL;
	t_list				*expected_list = NULL;
	enum e_token_type	i;
	int				expected_word = 0;

	expected_vct = vct_new();
	vct_addstr(expected_vct, expected);
	assert(expected != NULL && expected_vct != NULL);
	while ((split = vct_split(expected_vct, TYPE_DELIMITER, NO_SEP)) != NULL)
	{
		if (expected_word != 0)
		{
			add_to_list(&expected_list, expected_word, vct_getstr(split));
			expected_word = 0;
		}
		else
		{
			for (i = 0; i < g_nb_grammar_type; i++)
			{
				if (ft_strequ("$", vct_getstr(split)) == true)
				{
					expected_word = E_EXP;
					break ;
				}
				else if (ft_strequ("=", vct_getstr(split)) == true)
				{
					expected_word = E_ASSIGN;
					break ;
				}
				else if (ft_strequ("WORD", vct_getstr(split)) == true)
				{
					expected_word = E_WORD;
					break ;
				}
				else if (ft_strequ(g_grammar[i], vct_getstr(split)) == true)
				{
					add_to_list(&expected_list, i, vct_getstr(split));
					break ;
				}
			}
		}
		vct_del(&split);
	}
	vct_del(&expected_vct);
	return (expected_list);
}

void	del(void *data)
{
	t_token *token = (t_token *)data;
	ft_strdel(&token->data);
	free(token);
}

bool	are_token_list_equal(t_list *expected, t_list *list)
{
	t_token	*token1;
	t_token	*token2;

	while (expected != NULL || list != NULL)
	{
		if (list == NULL || expected == NULL)
			return (false);
		token1 = list->content;
		token2 = expected->content;
		if (token1 == NULL || token2 == NULL
				|| token1->type != token2->type
				|| (token1->data == NULL && token2->data != NULL)
				|| (token1->data != NULL && token2->data == NULL)
				|| (token1->data != NULL && token2->data != NULL
					&& ft_strequ(token1->data, token2->data) == false))
		{
			return (false);
		}
		expected = expected->next;
		list = list->next;
	}
	return (true);
}

t_list	*process_lexer(t_lex lex, t_vector *input)
{
	if (lex == NULL)
		return (NULL);
	return (lex(input));
}

int		tester(char *input, char *expected)
{
	t_vector	*input_vct;
	t_list		*token_list = NULL;
	t_list		*expected_list = NULL;
	bool		ret;

	input_vct = vct_new();
	vct_addstr(input_vct, input);
	if (g_grammar == NULL)
		initialize_grammar();
	assert(input != NULL && input_vct != NULL);
	expected_list = get_expected_list(expected);
	token_list = process_lexer(g_lexer, input_vct);
	vct_del(&input_vct);
	ret = are_token_list_equal(expected_list, token_list);
	if (ret == false)
		print_error(input, expected_list, token_list);
	ft_lstdel(&expected_list, del);
	ft_lstdel(&token_list, del);
	return (ret == false ? FAILURE : SUCCESS);
}
