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
# include <string.h>
# include <errno.h>
# include <stdbool.h>

/******************************************************************************/
/*******************************_FUNCTION_*************************************/
/******************************************************************************/

int		test(t_vector *input);
int		test_env(t_vector *input);
t_list	*test_lexer(t_vector *input);
int		test_parser(t_list *lexer_list);
t_list	*test_jobs(t_list *lexer_list);

/******************************************************************************/
/*******************************_LEXER_****************************************/
/******************************************************************************/

t_list	*lexer(t_vector *input);
size_t	get_token(char c);
ssize_t	get_double_token(t_vector *input);
void	free_list_token(t_list **token);
int		handle_quote(t_vector *input, t_list **token_list, int ret);
int 	extract_token(t_list **token_list, char *str, size_t type);
void	exit_routine_lexer(t_vector *word, t_vector *vct, t_vector *tmp,
							t_token *token);
int		handle_assign_quote(t_vector *input, t_vector *word);
int		quote_checker(char *str);
bool	is_simplequote(t_vector *input);
typedef	enum e_state	(*t_state)(t_vector *);
bool	is_doublequote(t_vector *input);
bool	is_simplequote(t_vector *input);
bool	is_end(t_vector *input);
int		extract_token_word(t_list **token_list, t_vector *vct);
char	*handle_bracket(char *str, t_list **token_list);
int		get_new_type(t_vector *input);
void	free_list_token(t_list **token);
const char	*get_token_str(const int type);
char	*get_data(int type);

/******************************************************************************/
/*******************************_PARSER_***************************************/
/******************************************************************************/

int		parser_token(t_list *token_list);
int		process_parser(t_list *list, t_valid_token *valid_token);
void		debug(const int type);

/******************************************************************************/
/*******************************_JOB/COMMAND_**********************************/
/******************************************************************************/

t_list	*get_jobs(t_list *token_list);
void	free_list_jobs(t_list **jobs);
void	debug_token_list(t_list *list);
int		next_is_end(t_list **token_list);
bool	is_cmd_sep(t_token *token);
bool	is_job_sep(t_token *token);
int		get_tablen(char **av);
t_cmd	*create_cmd(t_cmd *cmd_model);
void 	add_cmd_to_job(t_job *job, t_cmd *cmd_model);
void	init_cmd_var(t_cmd *cmd, t_list **list);
void	fill_cmd_model(t_cmd *cmd, t_token *token, int type);
char	*debug_get_type(int type);
int		next_is_cmd_sep(t_list *token_list);
char	*fill_name(char *str);
char	**fill_av(t_cmd *cmd);
int		fill_ac(char **av);
void	hub_test(int nb_job, int nb_command, t_cmd *cmd, int nb_test);
int		verif_name(char *good, char *name);
int		verif_ac(int good, int ac);
int		verif_av(char **good, char **av);
int		verif_fd_string(char **good, char **fd_string);
int		verif_condition(int good, int condition);
int		verif_redirection(int good, int redirection);



/******************************************************************************/
/*******************************_ERROR MANAGER_********************************/
/******************************************************************************/

void	print_set_errno(int err_value, char *function_name, char *error_source);

/******************************************************************************/
/*******************************_BUILTINS_*************************************/
/******************************************************************************/

int		env_builtin(int argc, char **argv);
int		export_builtin(int argc, char **argv);
int		unset_builtin(int argc, char **argv);

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

void		print_env(void);
void		get_export_output(void);

t_env_data	*get_env_data(t_env_data *mem);
t_env		*get_env_struct(char *env_name);
t_list		*get_env_node(char *env_name);
t_vector	*get_env_value_vct(char *env_name);

void		parse_env(char *env, char **env_name, t_vector **env_value,
															int *append_flag);
void	parser_debug(t_token *token);
#endif
