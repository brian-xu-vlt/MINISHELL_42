/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:03:06 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 19:03:07 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct				s_env
{
	char					*env_name;
	t_vector				*env_value;
	int						export_flag;
}							t_env;

typedef struct				s_lexer
{
	t_list					*token_list;
	ssize_t					type;
	t_vector				*word;
}							t_lexer;

typedef struct				s_token
{
	char					*data;
	enum e_token_type		type;
}							t_token;

typedef struct				s_valid_token
{
	enum e_token_type		*next_token;
}							t_valid_token;

typedef struct				s_draft
{
	t_vector				*name;
}							t_draft;

typedef struct				s_cmd
{
	char					*name;
	char					**av;
	enum e_token_type		*type;
	int						ac;
	int						fd[NB_FD];
	int						fd_before[NB_FD];
	char					*fd_string[NB_FD];
	enum e_condition_type	condition;
	int						redirection;
	int						redirection_before;
	int						count_assign;
	int						count_exp;
	size_t					*tab_assign;
	size_t					*tab_exp;
	char					**envp;
	size_t					count_redir;
	size_t					count_redir_before;
	int						tmp_fd_in;
	int						tmp_fd_out;
	int						tmp_fd_append;
	char					**tab_redir;
	char					**tab_redir_before;
	size_t					i_assign;
	size_t					i_exp;
	bool					err_exit;
	bool					solo_builtin;
}							t_cmd;

typedef struct				s_clean_cmd
{
	size_t					count_assign;
	size_t					ac;
	size_t					index_export;
	size_t					index_redir;
	size_t					count_redir;
	size_t					count_other;
	char					**tmp_tab_redir;
	char					**tab_redir;
	char					**tmp_av;
	char					**av;
	int						tmp_fd_in;
	int						tmp_fd_out;
	int						tmp_fd_append;
	int						index_cmd;
}							t_clean_cmd;

typedef struct				s_job
{
	t_list					*cmd_lst;
	size_t					nb_cmd;
	pid_t					last_pid;
}							t_job;

typedef struct				s_data
{
	t_le					*line_editor_data;
	t_list					*current_jobs;
	t_vector				*cmd_line;
	t_list					*lexer_list;
}							t_data;

#endif
