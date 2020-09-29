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

/******************************************************************************/
/*******************************_FUNCTION_*************************************/
/******************************************************************************/

int		test(t_vector *input);
int		test_env(t_vector *input);

t_list	*lexer(t_vector *input);
size_t	get_token(char c);
ssize_t	get_double_token(t_vector *input);
void	free_list(t_list **token);
int		handle_quote(t_vector *input, t_list **token_list, int ret);
int 	extract_token(t_list **token_list, char *str, size_t type);
void	exit_routine_lexer(t_vector *word, t_vector *vct, t_vector *tmp, t_token *token);
int		parser_token(t_list *token_list);
int		process_parser(t_list *list, t_valid_token *valid_token);

/******************************************************************************/
/*******************************_ENV_MANAGER_**********************************/
/******************************************************************************/

# define	ALL				NULL
# define	NOT_FOUND		NULL

void		free_envp(void);
void		del_env_elem(void *elem_content);
void		free_btree_node(t_btree *node);
void		delete_env(char *env_name);

void		store_internal_var(char *env);
void		update_envp(void);
void		export_env(char *env);
void		init_env(char **env);

void		print_env(char *env_name);
void		get_export_output(void);

t_env_data	*get_env_data(t_env_data *mem);
t_env		*get_env_struct(char *env_name);
t_list		*get_env_node(char *env_name);
t_vector	*get_env_value_vct(char *env_name);

void		parse_env(char *env, char **env_name, t_vector **env_value,
															int *append_flag);
#endif
