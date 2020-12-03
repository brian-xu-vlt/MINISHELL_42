#include "minishell.h"

t_list	*test_lexer(t_vector *input)
{
	t_list		*lexer_list;
	t_data		*data;

	lexer_list = lexer(input);
	if (lexer_list == NULL)
	{
		free_list_token(&lexer_list);
		return (NULL);
	}
	data = get_data_struct(GET);
	if (data != NULL)
		data->lexer_list = lexer_list;
	return (lexer_list);
}
