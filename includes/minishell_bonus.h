#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

/******************************************************************************/
/*******************************_INCLUDE_**************************************/
/******************************************************************************/

# include "libft.h"
# include "define_bonus.h"
# include "enum_bonus.h"
# include "lexer_bonus.h"
# include "struct_bonus.h"
# include "parser_bonus.h"
# include <stdio.h> //A ENLEVER POUR PRINTF

/******************************************************************************/
/*******************************_FUNCTION_*************************************/
/******************************************************************************/

t_list	*lexer(t_vector *input);
size_t	get_token(char c);
ssize_t	get_double_token(t_vector *input);
void	free_list(t_list **token);
int		handle_quote(t_vector *input, t_list **token_list, int ret);
int 	extract_token(t_list **token_list, char *str, size_t type);
void	exit_routine_lexer(t_vector *word, t_vector *vct, t_vector *tmp, t_token *token);
t_btree *parser_token(t_list *token_list);

#endif
