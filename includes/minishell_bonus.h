#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

#ifndef BONUS_FLAG
# define	BONUS_FLAG		FALSE
#endif

/******************************************************************************/
/*******************************_INCLUDE_**************************************/
/******************************************************************************/

# include "libft.h"
# include <stdio.h> //A ENLEVER POUR PRINTF
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <dirent.h>
# include "define_bonus.h"
# include "enum_bonus.h"
# include "lexer_bonus.h"
# include "line_editor_bonus.h"
# include "struct_bonus.h"
# include "parser_bonus.h"

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

t_list					*lexer(t_vector *input);
size_t					get_token(char c);
ssize_t					get_double_token(t_vector *input);
void					free_list_token(t_list **token);
int 					extract_token(t_list **token_list, char *str,
										size_t type);
void					exit_routine_lexer(t_vector *word, t_vector *vct,
											t_vector *tmp, t_token *token);
int						handle_assign_quote(t_vector *in, t_vector *word);
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
int 					handle_ret_lexer(int ret_process_lexer,
											t_list *token_list, t_vector *word,
											int flag);
t_list					*get_job(t_list *job);
int						no_word(t_list **token_list, t_vector *word,
									size_t type);
bool					stop_assign_char(char c);
bool					stop_assign_str(t_vector *input);
int						is_newline_error(bool dquote_state, bool quote_state,
											t_vector *input);
int 					backsl_quote(bool quote_state, bool dquote_state,
										t_vector *input, t_vector *word);
int 					handle_quote(char c, bool quote_state, bool dquote_state,
										t_vector *input);
int 					backslash(char c, t_vector *word, t_vector *input,
									char next_c);
bool 					parse_backslash(t_vector *input, t_vector *word, bool
									is_quoting);
void					pop_input_word(t_vector *input, t_vector *word);

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
int		fill_cmd_model(t_cmd *cmd, t_token *token, int type);
char	*debug_get_type(int type);
int		next_is_cmd_sep(t_list *token_list);
int		fill_name(t_token *token, t_cmd *cmd);
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
void	init_all(t_cmd *cmd);

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
typedef	enum e_state_redir			(*t_state_redir)(char *str, enum e_token_type type);
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
char								*get_env_value_str(char *var);
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
ssize_t								end_exp(char *str);
int 								process_clean_quote(t_vector *input,
															t_vector *output);
int 								handle_backslash_double(char c,
															t_vector *input);
int 								handle_backslash_nothing(t_vector *input,
															t_vector *output,
																char c);
int 								is_backslash(char c, char next_c,
													t_vector *input);
bool 								is_exp_sep(char c);
bool								verif_assign_cmd(char *str);
void								exit_routine_cleaner(t_cmd *cmd,
														t_clean_cmd *clean_cmd);
char								*clean_quote(char *arg, int *ret);
bool 								is_redir_before(t_cmd *cmd, size_t i);
bool 								check_av(t_cmd *cmd, size_t *i);
void 								increment(int ret, t_cmd *cmd);
int 								set_redir_before(t_cmd *cmd, size_t i);
void 								how_increment(t_cmd *cmd, size_t *i);
int 								parse_double_quote(t_vector *input,
										t_vector *output);
int 								is_export(char c, t_vector *input,
										t_vector *output);
void 								pop_output_input(int ret, char c,
										t_vector *input, t_vector *output);
void 								handle_pop(size_t index, t_vector *output);
void 								pop_input(t_vector *input, t_vector *output);
void 								pop_input_output(char c, t_vector *input,
										t_vector *output);
void 								parse_expansion(t_vector *input,
										t_vector *output);
int 								process_pop(size_t index, t_vector *input,
										t_vector *output);

/******************************************************************************/
/*******************************_EXECUTION_************************************/
/******************************************************************************/

#define BUILTIN_FAILURE		1
#define R_END				0
#define W_END				1

void	process_open_file(t_cmd *cmd, int flag);
void	export_envp(char **envp);
void	assign_envp_content(const t_cmd *command);
int		exec_builtin(t_cmd *command);
int		exec_binary(const t_cmd *command);
void	signal_manager(int set_mode);
int		execution_main_process(t_job *job, t_cmd *command,
													int p_in[2], int p_out[2]);

void	exec_subshell(t_job *job, t_cmd *cmd, int p_in[2], int p_out[2]);
void	executor(t_job *job);
char	*locate_binary_file(const char *bin_name);
int		is_path(const char *bin_name);


int		is_valid_job(const t_job *job);
int		is_last_cmd(const int cmd_index, const int nb_cmd);
int		is_solo_builtin(const size_t nb_cmd, t_cmd *command);
int		manage_subshell_exit_status(const int wstatus);
int		ms_dup(int old_fd);
int		ms_dup2(int old_fd, int new_fd);
int		ms_pipe(int pipe_fd[2]);
void	close_pipe_end(int pipe_to_close);
pid_t	fork_process(void);
void	dup_pipes(t_cmd *command, int p_in[2], int p_out[2]);
int		is_builtin(const t_cmd *command);

void	display_signal_str(int sig);
/******************************************************************************/
/*******************************_GENERAL_UTILES_*******************************/
/******************************************************************************/

t_data		*get_data_struct(t_data *mem);
t_vector	*safe_vct_new(void);
int			safe_vct_cpy(t_vector *dest, t_vector *src);
int			safe_vct_add(t_vector *vct, char c);
int			safe_vct_addstr(t_vector *vct, char *str);
int			safe_vct_addcharat(t_vector *vct, size_t index, char c);
void		free_char_arr(char **arr);

/******************************************************************************/
/*******************************_ERROR MANAGER_********************************/
/******************************************************************************/

void	print_set_errno(int errno_value, const char *err_str,
						const char *function_name, const char *error_source);
void	print_invalid_identifier(const char *function_name,
													const char *error_source);
void	print_invalid_option(const char *function_name,
								const char *error_source, const char *usage);

/******************************************************************************/
/*******************************_BUILTINS_*************************************/
/******************************************************************************/

int		set_builtin(int ac, char **av, char **envp);
int		history_builtin(int ac, char **av, char **envp);
int		exit_builtin(int ac, char **av, char **envp);
int		env_builtin(int argc, char **argv, char **envp);
bool	is_valid_export_identifier(char *id_to_test);
int		export_builtin(int argc, char **argv, char **envp);
int		unset_builtin(int argc, char **argv, char **envp);
int		pwd_builtin(int ac, char **av, char **envp);
int		echo_builtin(int ac, char **av, char **envp);
int		handle_pwd(char *dir);
int 	cd_builtin(int ac, char **av, char **envp);
char 	*handle_permission_denied(char *dir_denied);
int 	check_cd_arg(int ac);
int 	first_check(char *directory);
void 	transform_new_dir(t_vector *new_dir, char *pwd, char *dir_denied);
int		check_arg(t_vector *vct_av, char c, char *av, int ac);
bool	is_long(t_vector *av, char c);
bool	parse_vct(t_vector *vct_av);
size_t	pop_arg(t_vector *av, int flag);
void	cut_arg(t_vector *vct_av, size_t len_before, size_t count_num,
						t_vector *av);
bool	is_numeric(t_vector *av);
int		process_error(t_vector *vct_home, char *dir, t_vector *vct_old_pwd);
int		print_error(t_vector *vct_av, char *av, char c, int flag);
void	handle_exit_value(t_vector *vct_av, t_vector *vct_av_cpy, char c);
int 	handle_old_pwd(char *old_dir);
int 	handle_permission_not(char *dir, char *pwd, char *old_dir);
void 	swap_pwd(int flag, char *dir);
void 	get_value(t_vector **vct_pwd, t_vector **vct_old, t_vector **vct_home);
void 	free_clean_command(t_clean_cmd *clean_cmd, int flag);
void	set_env(t_vector *vct_pwd, t_vector *vct_old);
void	exit_error(t_vector *vct_av, char *av, char c, int flag);
void 	set_old_pwd(char *dir, char *pwd, int flag);

/******************************************************************************/
/*******************************_ENV_MANAGER_**********************************/
/******************************************************************************/

# define	ALL				NULL
# define	NOT_FOUND		NULL

# define	F_NOFLAG		0
# define	F_EXPORT		(1 << 0)
# define	F_OVERWRITE		(1 << 1)
# define	F_SPECIAL		(1 << 2)

void		free_env_list(t_list *env_lst);

void		del_env_elem(void *elem_content);
void		free_btree_node(t_btree *node);
void		unset_env(t_list *env_lst, const char *env_name);

void		store_env(t_list *env_lst, const char *env, int flags);
void		ms_setenv(t_list *env_lst, const char *env_name,
											const char *env_value, int flags);
void		ms_setenv_int(t_list *env_lst, const char *env_name, int value,
												int flags);
void		ms_putenv(t_list *env_lst, const char *env);
char		**get_envp(t_list *env_lst);
void		export_env(t_list *env_lst, const char *env);
void		init_env(void);

void		print_env(t_list *env_lst);
void		add_to_btree(t_btree **tree, t_env *env);
void		print_export_output(t_list *env_lst, int flag);

t_list		*get_env_list(t_list *mem);
t_env		*get_env_struct(t_list *env_lst, const char *env_name);
t_list		*get_env_node(t_list *env_lst, const char *env_name);
t_vector	*get_env_value_vct(t_list *env_lst, const char *env_name);
int			get_env_value_int(t_list *env_lst, const char *env_name);

void		parse_env(const char *env, char **env_name, char **env_value,
																int *overwrite);
void		parser_debug(t_token *token);

/******************************************************************************/
/*******************************_ENV_MANAGER_**********************************/
/******************************************************************************/


void		exit_routine(int err_code);
void		exit_routine_line_edition(t_le *le, int err_code);
void		exit_routine_env(void);

#endif
