#include "tester.h"

void	print_list(t_list *list)
{
	t_token *token;

	for (;list != NULL; list = list->next)
	{
		token = list->content;
		if (token != NULL)
		{
			if (is_data_type(token->type) == true)
				ft_dprintf(STDERR_FILENO, "[ %s = '%s' ]%s", g_grammar[token->type],
						token->data , (list->next == NULL) ? "\n" : " -> ");
			else
				ft_dprintf(STDERR_FILENO, "[ %s ]%s", g_grammar[token->type],
						(list->next == NULL) ? "\n" : " -> ");
		}
	}
}

void	print_error(char *input, t_list *expected, t_list *list)
{
	ft_dprintf(STDERR_FILENO, "\n\nINPUT = [%s]\n\nExpected :\n", input);
	print_list(expected);
	ft_dprintf(STDERR_FILENO, "\nCurrent :\n");
	print_list(list);
}
