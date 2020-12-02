#ifndef CLEANER_BONUS_H
# define CLEANER_BONUS_H

# include "minishell_bonus.h"

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
typedef	enum e_state_redir			(*t_state_redir)(char *str,
														enum e_token_type type);
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
int									fill_cmd(t_cmd *cmd,
														t_clean_cmd *clean_cmd);
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
void 								pop_input(t_vector *input,
															t_vector *output);
void 								pop_input_output(char c, t_vector *input,
										t_vector *output);
void 								parse_expansion(t_vector *input,
										t_vector *output);
int 								process_pop(size_t index, t_vector *input,
										t_vector *output);

#endif
