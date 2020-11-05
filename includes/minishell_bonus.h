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
# include <fcntl.h>
# include <limits.h>

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

t_list					*lexer(t_vector *input);
size_t					get_token(char c);
ssize_t					get_double_token(t_vector *input);
void					free_list_token(t_list **token);
int 					extract_token(t_list **token_list, char *str,
										size_t type);
void					exit_routine_lexer(t_vector *word, t_vector *vct,
											t_vector *tmp, t_token *token);
int						handle_assign_quote(t_vector *input, t_vector *word);
int						quote_checker(char *str);
bool					is_simplequote(t_vector *input);
typedef	enum e_state	(*t_state)(t_vector *);
bool					is_doublequote(t_vector *input);
bool					is_end(t_vector *input);
int						extract_token_word(t_list **token_list, t_vector *vct);
char					*handle_bracket(char *str, t_list **token_list);
void					free_list_token(t_list **token);
const char				*get_token_str(const int type);
char					*get_data(int type);
void					free_token(t_list *node, t_token *token);

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
int 	add_cmd_to_job(t_job *job, t_cmd *cmd_model);
void	init_cmd_var(t_cmd *cmd, t_list **list);
int		fill_cmd_model(t_cmd *cmd, t_token *token, int type);
char	*debug_get_type(int type);
int		next_is_cmd_sep(t_list *token_list);
int		fill_name(char *str, t_cmd *cmd);
int		fill_ac(char **av);
int		verif_name(char *good, char *name);
int		verif_ac(int good, int ac);
int		verif_av(char **good, char **av, int ac);
int		verif_fd_string(char **good, char **fd_string);
int		verif_condition(int good, int condition);
int		verif_redirection(int good, int redirection);
void	free_list_job(t_list **job);
int		hub_test(int nb_job, int nb_command, t_cmd *cmd, int nb_test);
int		count_ac(t_list **list);
int		get_command(int type);
int		process_end_cmd(t_list *token_list, t_cmd *cmd, t_job *job);
int		process_add_command(t_token *token, t_cmd *cmd, t_list *token_list,
			t_job *job);
int		is_cmd(t_token *token, t_cmd *cmd, int add_command);
int		is_end_cmd(t_token *token, t_list **token_list, t_cmd *cmd, t_job *job);
int		is_add_cmd(t_token *token, t_list *token_list, t_cmd *cmd,
			t_job *job);
t_job	*init_job(void);
int		add_job_to_list(t_job *job, t_list **jobs, t_list *token_list,
			t_list **head);
int		count_assign(t_list **list);
int		count_exp(t_list **list);
int		fill_assign(int flag, int count_ac, t_cmd *cmd);
int		fill_exp(int flag, int count_ac, t_cmd *cmd);
void	create_cmd_fd_string(t_cmd *cmd, t_cmd *cmd_model);
int		resize_cmd(t_cmd *cmd, int count);
int		fill_data_cmd(t_token *token, t_cmd *cmd, int count);
void	debug_jobs(t_list *job_list);
void	process_between_both(char *str, t_vector *vct_good);

/******************************************************************************/
/*******************************_CLEANER_**************************************/
/******************************************************************************/

int									cleaner(t_cmd *cmd);
void								debug_cleaner(t_cmd *cmd);
void								debug_av(char **av, int ac);
char								*clean_quote_no_exp(char *str);
char 								*clean_quote_exp(char *str);
typedef	enum e_state_quote_no_exp	(*t_state_quote_no_exp)(char);
char								*exp_value(char *str);
char								*between_nothing(char *str);
char								*between_simple(char *str);
char								*between_double(char *str);
char								*between_both(char *str);
bool								is_del(char c);
size_t								end_exp(char *str);
size_t								handle_exp(size_t i, t_vector *vct_good,
												char *str);
size_t								end_quote(char *str, size_t i,
												enum e_between quote);
void								handle_simple(char *str, size_t i,
													size_t end_simple,
													t_vector *vct_good);
void								process_between_simple(char *str,
															t_vector *vct_good);
void								process_between_double(char *str,
															t_vector *vct_good);
void								handle_double(char *str, size_t i,
													size_t end_simple,
													t_vector *vct_good);
size_t 								verif_assign(t_vector *vct_av,
													size_t id_equal);
bool 								is_wrong_char(t_vector *vct);
bool 								is_wrong_ass(t_vector *vct);
int									process_redirection(t_cmd *cmd,
													t_clean_cmd *clean_cmd);
typedef	enum e_state_redir			(*t_state_redir)(char *);
void 								debug_redir(char **redir, int ac);
int									create_tab_redir(t_cmd *cmd,
														t_clean_cmd *clean_cmd);
int									clean_redir_av(t_cmd *cmd,
													t_clean_cmd *clean_cmd);
int									init_av_redir(t_clean_cmd *clean_cmd,
													size_t nb_av,
													size_t nb_redir);
int									count_redir(t_cmd *cmd,
													t_clean_cmd *clean_cmd);
int									count_av(t_cmd *cmd);
void								debug_fd(int *fd);
void								debug_fd_string(char **fd_sting);
t_clean_cmd							*init_clean_command(void);
int									get_cmd(t_cmd *cmd);
int									get_envp_av(t_cmd *cmd,
													t_clean_cmd *clean_cmd,
													int index_cmd);
int									clean_cmd_av(t_cmd *cmd,
													t_clean_cmd *clean_cmd,
													bool no_cmd, int index_cmd);
int									fill_clean_cmd(int index_cmd, t_cmd *cmd,
												t_clean_cmd *clean_cmd);
int									fill_cmd(t_cmd *cmd, t_clean_cmd *clean_cmd);
void								fill_envp(t_cmd *cmd, int index_cmd);
int									count_new_ac(char **av, size_t size);
int									count_clean_exp(char **av, size_t size);
int									*fill_tab_clean_exp(int *tab_clean_exp,
															char **av,
															size_t size,
															int clean_exp);
int 								hub_cleaner(t_list *job_list);

	/******************************************************************************/
	/*******************************_ERROR MANAGER_********************************/
	/******************************************************************************/

	void print_set_errno(int err_value, char *function_name, char *error_source);

	/******************************************************************************/
	/*******************************_BUILTINS_*************************************/
	/******************************************************************************/

	int env_builtin(int argc, char **argv);
	int export_builtin(int argc, char **argv);
	int unset_builtin(int argc, char **argv);
	int	pwd_builtin(void);

	/******************************************************************************/
	/*******************************_ENV_MANAGER_**********************************/
	/******************************************************************************/

# define	ALL				NULL
# define	NOT_FOUND		NULL

void		free_envp(char **envp);
void		del_env_elem(void *elem_content);
void		free_btree_node(t_btree *node);
void		delete_env(char *env_name);

void		store_internal_var(char *env);
char		**get_envp(void);
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
void		parser_debug(t_token *token);
#endif
