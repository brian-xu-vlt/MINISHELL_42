#include "minishell_bonus.h"

/*void		debug(enum e_token_type to_find, enum e_token_type *current,
						enum e_token_type valid_token[], size_t i)
{
	char	*tab[17] = {"SEP", "PIPE", "SIMPLE_QUOTE", "QUOTE", "LESS_THAN",
						"GREATER_THAN", "SPACE", "TAB", "DOUBLE_GREATER",
						"OR", "AND", "WORD", "EXP", "ASSIGN", "START", "END",
						"NO_TYPE"};

	printf("valid_token[%s] = %u\n", tab[*current], to_find);//DEBUG
}*/

static int	check_token(enum e_token_type to_find, enum e_token_type *current,
						enum e_token_type valid_token[])
{
	size_t	i;

	i = 0;
	while (valid_token[i] != NO_TYPE)
	{
		if (valid_token[i] == to_find)
		{
			//debug(to_find, current, valid_token, i);//DEBUG
			*current = to_find;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int			process_parser(t_list *list, t_valid_token *valid_token)
{
	enum e_token_type	current;
	t_token				*token;

	current = E_START;
	while (list != NULL)
	{
		token = (t_token *)list->content;
		if (check_token(token->type, &current,
							valid_token[current].next_token) == FALSE)
		{
			return (FALSE); //MESSAGE D'ERREUR
		}
		list = list->next;
	}
	return (TRUE);//DEBUG
}
