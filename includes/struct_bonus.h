#ifndef MINISHELL_H
# define MINISHELL_H

/******************************************************************************/
/*******************************_LEXER_****************************************/
/******************************************************************************/

typedef struct s_lexer
{
	t_list		*token_list;
	ssize_t		type;
	t_vector	*word;
}				t_lexer;

typedef struct s_token
{
	char				*data;
	enum e_token_type	type;
}				t_token;

#endif
