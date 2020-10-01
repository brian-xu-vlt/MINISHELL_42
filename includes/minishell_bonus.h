#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

#ifndef BONUS_FLAG
# define	BONUS_FLAG		FALSE
#endif

/******************************************************************************/
/*******************************_INCLUDE_**************************************/
/******************************************************************************/

# include "libft.h"
# include "define_bonus.h"
# include "enum_bonus.h"
# include "lexer_bonus.h"
# include "struct_bonus.h"
# include "parser_bonus.h"
# include "line_editor_bonus.h"
# include <stdio.h> //A ENLEVER POUR PRINTF
# include <stdbool.h>

/******************************************************************************/
/*******************************_FUNCTION_*************************************/
/******************************************************************************/

t_list	*test_lexer(t_vector *input);
int		test_jobs(t_list *lexer_list);
int		test_parser(t_list *lexer_list);

t_list	*lexer(t_vector *input);
size_t	get_token(char c);
ssize_t	get_double_token(t_vector *input);
void	free_list_token(t_list **token);
int		handle_quote(t_vector *input, t_list **token_list, int ret);
int 	extract_token(t_list **token_list, char *str, size_t type);
void	exit_routine_lexer(t_vector *word, t_vector *vct, t_vector *tmp,
							t_token *token);
int		parser_token(t_list *token_list);
int		process_parser(t_list *list, t_valid_token *valid_token);
t_list	*get_jobs(t_list *token_list);
void	free_list_jobs(t_list **jobs);
int		handle_assign_quote(t_vector *input, t_vector *word, t_list **token_list);
int		quote_checker(char *str);
bool	is_simplequote(t_vector *input);
typedef	enum e_state	(*t_state)(t_vector *);
bool	is_doublequote(t_vector *input);
bool	is_simplequote(t_vector *input);
bool	is_end(t_vector *input);
int		extract_token_word(t_list **token_list, t_vector *vct);
void	debug(int type); //A ENLEVER

#endif
