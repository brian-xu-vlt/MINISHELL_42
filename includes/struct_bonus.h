#ifndef MINISHELL_H
# define MINISHELL_H

/******************************************************************************/
/**********************************_ENV_***************************************/
/******************************************************************************/

typedef struct					s_env
{
	char						*env_name;
	t_vector					*env_value;
	int							export_flag;
}								t_env;

/******************************************************************************/
/*******************************_LEXER_****************************************/
/******************************************************************************/

typedef struct s_lexer
{
	t_list		*token_list;
	ssize_t		type;
	t_vector	*word;
}				t_lexer;

typedef struct s_token
{
	char				*data;
	enum e_token_type	type;
}				t_token;

/******************************************************************************/
/*******************************_PARSER_***************************************/
/******************************************************************************/

typedef struct					s_valid_token
{
	enum e_token_type			*next_token;
}								t_valid_token;

/******************************************************************************/
/*******************************_JOB/COMMAND_**********************************/
/******************************************************************************/

typedef struct				s_draft
{
	t_vector				*name;
}							t_draft;

typedef struct				s_cmd
{
	char					*name;
	char					**av;
	int						ac;
	int						fd[NB_FD];
	char					*fd_string[NB_FD];
	enum e_condition_type	condition;
	int						redirection;
	int						ret;
	int						count_assign;
	int						count_exp;
	size_t					*tab_assign;
	size_t					*tab_exp;
	char					**envp;
	size_t					count_redir;
	int						tmp_fd_in;
	int						tmp_fd_out;
	int						tmp_fd_append;
	char					**tab_redir;
}
							t_cmd;

typedef struct				s_clean_cmd
{
	size_t	count_assign;
	size_t	ac;
	size_t	index_export;
	size_t	index_redir;
	size_t	count_redir;
	size_t	count_other;
	char	**tmp_tab_redir;
	char	**tab_redir;
	char	**tmp_av;
	char	**av;
	int		tmp_fd_in;
	int		tmp_fd_out;
	int		tmp_fd_append;
}
							t_clean_cmd;

typedef struct					s_job
{
	t_list					*cmd_lst;
	size_t					nb_cmd;
}								t_job;


#endif
