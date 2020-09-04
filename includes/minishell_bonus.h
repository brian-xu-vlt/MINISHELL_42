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
# include <stdio.h> //A ENLEVER POUR PRINTF

/******************************************************************************/
/*******************************_FUNCTION_*************************************/
/******************************************************************************/

int		ft_lexer(t_vector *input, t_lexer *lexer);
void	exit_routine(t_token *token, t_list *node);
size_t	get_token(char c);
ssize_t	get_double_token(t_vector *input);

#endif
