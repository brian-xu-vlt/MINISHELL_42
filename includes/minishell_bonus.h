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
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>

/******************************************************************************/
/*******************************_FUNCTION_*************************************/
/******************************************************************************/

int		test(t_vector *input);
int		test_env(t_vector *input);
int		test_executor(t_list *jobs);


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

void	debug_jobs(t_list *job_list);
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
void	fill_cmd_model(t_cmd *cmd, t_token *token, int type);
char	*debug_get_type(int type);
int		next_is_cmd_sep(t_list *token_list);
void	fill_name(char *str, t_cmd *cmd);
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
t_job	*init_job();
int		add_job_to_list(t_job *job, t_list **jobs, t_list *token_list,
			t_list **head);

/******************************************************************************/
/*******************************_EXECUTION_************************************/
/******************************************************************************/

#define BUILTIN_FAILURE		1
#define R_END				0
#define W_END				1

char	**get_all_path_directories(void);
char	*get_exec_path(char *dir, const char *name);
void	export_execution_context_env(const t_cmd *command);
int		exec_builtin(const t_cmd *command);
int		exec_binary(const t_cmd *command);
void	signal_manager(int set_mode);
void	executor(const t_job *job);
char	*locate_binary_file(const char *bin_name);
int		is_absolute_path(const char *bin_name);


int		is_solo_builtin(const int nb_cmd, const t_cmd *command);
void	manage_subshell_exit_status(const int wstatus);
void	do_pipe(int pipe_fd[2]);
void	close_pipe_end(int pipe_to_close);
pid_t	fork_process(void);
void	dup_pipes(const t_cmd *command, int p_in[2], int p_out[2]);
int		is_builtin(const t_cmd *command);
/******************************************************************************/
/*******************************_GENERAL_UTILES_*******************************/
/******************************************************************************/

void	free_char_arr(char **arr);

/******************************************************************************/
/*******************************_ERROR MANAGER_********************************/
/******************************************************************************/

void	print_set_errno(int errno_value, const char *err_str,
						const char *function_name, const char *error_source);

/******************************************************************************/
/*******************************_BUILTINS_*************************************/
/******************************************************************************/

int		exit_builtin(int ac, char **av, char **envp);
int		env_builtin(int argc, char **argv, char **envp);
int		export_builtin(int argc, char **argv, char **envp);
int		unset_builtin(int argc, char **argv, char **envp);

/******************************************************************************/
/*******************************_ENV_MANAGER_**********************************/
/******************************************************************************/

# define	ALL				NULL
# define	NOT_FOUND		NULL

# define	F_NOFLAG		0
# define	F_EXPORT		(1 << 0)
# define	F_OVERWRITE		(1 << 1)

void		free_env_list(t_list *env_lst);

void		del_env_elem(void *elem_content);
void		free_btree_node(t_btree *node);
void		unset_env(t_list *env_lst, const char *env_name);

void		ms_setenv(t_list *env_lst, const char *env_name,
											const char *env_value, int flags);
void		ms_setenv_int(t_list *env_lst, const char *env_name, int value,
												int flags);
void		ms_putenv(t_list *env_lst, const char *env);
char		**get_envp(t_list *env_lst);
void		export_env(t_list *env_lst, const char *env);
void		init_env(void);

void		print_env(t_list *env_lst);
void		print_export_output(t_list *env_lst);

t_list		*duplicate_env_lst(t_list *env_lst);
t_list		*get_env_list(t_list *mem);
t_env		*get_env_struct(t_list *env_lst, const char *env_name);
t_list		*get_env_node(t_list *env_lst, const char *env_name);
t_vector	*get_env_value_vct(t_list *env_lst, const char *env_name);
int			get_env_value_int(t_list *env_lst, const char *env_name);

void		parse_env(const char *env, char **env_name, char **env_value,
																int *overwrite);
void		parser_debug(t_token *token);
#endif
