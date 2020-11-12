#include "minishell_bonus.h"

void		parser_debug(t_token *token)
{
	if (token->data != NULL)
		printf("type = %-*s | data [%s]\n", 8,
			get_token_str(token->type), token->data);
	else
		printf("type = %-*s\n", 8, get_token_str(token->type));
}

static int	check_token(t_token *token, enum e_token_type *current,
						enum e_token_type valid_token[])
{
	size_t					i;
	const enum e_token_type to_find = token->type;
	int						ret;

	i = 0;
	ret = FALSE;
	if (*current == E_END)
		ret = TRUE;
	else
	{
		while (valid_token[i] != NO_TYPE)
		{
			if (valid_token[i] == to_find)
			{
				*current = to_find;
				ret = TRUE;
				break ;
			}
			i++;
		}
	}
	//if (ret == TRUE)
		//parser_debug(token);
	return (ret);
}

int			process_parser(t_list *list, t_valid_token *valid_token)
{
	enum e_token_type	current;
	t_token				*token;

	current = E_START;
	while (list != NULL)
	{
		token = (t_token *)list->content;
		if (check_token(token, &current,
							valid_token[current].next_token) == FALSE)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `",
							STDERR_FILENO);
			ft_putstr_fd((char *)get_token_str(token->type), STDERR_FILENO);
			ft_putendl_fd("'", STDERR_FILENO);
			return (FALSE);
		}
		list = list->next;
	}
	return (TRUE);//DEBUG
}
