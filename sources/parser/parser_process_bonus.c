#include "minishell_bonus.h"

void	debug(enum e_token_type to_find, enum e_token_type *actual,
						enum e_token_type valid_token[], size_t i)
{
	char	*tab[17] = {"SEP", "PIPE", "SIMPLE_QUOTE", "QUOTE", "LESS_THAN",
						"GREATER_THAN", "SPACE", "TAB", "DOUBLE_GREATER",
						"OR", "AND", "WORD", "EXP", "ASSIGN", "START", "END",
						"NO_TYPE"};

	printf("valid_token[%s] = %u\n", tab[*actual], to_find);//DEBUG
}

static int	check_token(enum e_token_type to_find, enum e_token_type *actual,
						enum e_token_type valid_token[])
{
	size_t	i;

	i = 0;
	while (valid_token[i] != NO_TYPE)
	{
		if (valid_token[i] == to_find)
		{
			debug(to_find, actual, valid_token, i);//DEBUG
			*actual = to_find;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
} 

void		process_parser(t_list *list, t_valid_token *valid_token)
{
	enum	e_token_type	actual;
	t_token					*token;

	actual = E_START;
	while (list != NULL)
	{
		token = (t_token *)list->content;
		if (check_token(token->type, &actual,
							valid_token[actual].next_token) == FALSE)
		{
			return ;
		}
		list = list->next;
	}
	ft_printf("VALID\n");//DEBUG
}
