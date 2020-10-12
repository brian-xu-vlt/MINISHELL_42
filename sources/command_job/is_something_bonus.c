#include "minishell_bonus.h"

bool	is_job_sep(t_token *token)
{
	return (token->type == E_OR || token->type == E_AND
				|| token->type == E_SEPARATOR ? true : false);
}

bool	is_cmd_sep(t_token *token)
{
	return (is_job_sep(token) || token->type == E_PIPE);
}

int	is_add_cmd(t_token *token, t_list *token_list, t_cmd *cmd,
		t_job *job)
{
	int	ret;

	ret = is_end_cmd(token, &token_list, cmd, job);
	if (ret != true)
	{
		if (ret == FAILURE)
			return (FAILURE);
		if (process_add_command(token, cmd, token_list, job) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	is_end_cmd(t_token *token, t_list **token_list, t_cmd *cmd, t_job *job)
{
	if (is_cmd_sep(token) == true
			|| next_is_end(token_list) == true)
	{
		if (next_is_end(token_list) == true)
			fill_cmd_model(cmd, token, get_command(token->type));
		fill_cmd_model(cmd, token, RESIZE);
		if (add_cmd_to_job(job, cmd) == FAILURE)
			return (FAILURE);
		init_cmd_var(cmd, token_list);
		return (true);
	}
	return (false);
}

int	is_cmd(t_token *token, t_cmd *cmd, int add_command)
{
	if (token->type == E_LESS_THAN || token->type == E_GREATER_THAN
			|| token->type == E_DOUBLE_GREATER)
		fill_cmd_model(cmd, token, token->type == E_DOUBLE_GREATER ? 
				E_CMD_DOUBLE_REDIRECTION : E_CMD_SIMPLE_REDIRECTION);
	else
		fill_cmd_model(cmd, token, E_CMD_AV);
	if (add_command == TRUE)
		return (true);
	return ((token->type == E_LESS_THAN || token->type == E_GREATER_THAN
				|| token->type == E_DOUBLE_GREATER) ? true : false);
}
