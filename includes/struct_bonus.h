#ifndef MINISHELL_H
# define MINISHELL_H

/******************************************************************************/
/**********************************_ENV_***************************************/
/******************************************************************************/

typedef struct					s_env_data
{
	char						**envp;
	t_list						*env_lst;
}								t_env_data;

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
}
							t_cmd;

typedef struct					s_job
{
	t_list					*cmd_lst;
	int						ret;
}								t_job;


#endif
