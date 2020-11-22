#include "minishell_bonus.h"

static int	is_redirection(int ret_cmd, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	if (ret_cmd != NO_COMMAND)
	{
		if (process_redirection(cmd, clean_cmd) == FAILURE)
		{
			free_clean_command(clean_cmd, MALLOC);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int process_clean_command(t_cmd *cmd)
{
	t_clean_cmd *clean_cmd;
	int index_cmd;
	int ret_cmd;

	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE);
		return (FAILURE);
	}
	index_cmd = get_cmd(cmd);
	ret_cmd = get_envp_av(cmd, clean_cmd, index_cmd);
	if (ret_cmd == FAILURE)
	{
		free_clean_command(clean_cmd, MALLOC);
		return (FAILURE);
	}
	if (is_redirection(ret_cmd, cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	cmd->name = (cmd->ac != 0 ? cmd->av[0] : NULL);
	free_clean_command(clean_cmd, ALL_FREE);
	return (SUCCESS);
}

char *clean_quote(char *arg)
{
	t_vector *input;
	t_vector *output;
	char *transform_arg;

	input = vct_new();
	output = vct_new();
	vct_addstr(input, arg);
	transform_arg = NULL;
	if (process_clean_quote(input, output) == FAILURE)
	{
		vct_del(&input);
		vct_del(&output);
		return (NULL);
	}
	free(arg);
	if (output != NULL)
		transform_arg = vct_strdup(output);
	vct_del(&input);
	vct_del(&output);
	return (transform_arg);
}

int cleaner(t_cmd *cmd)
{
	int ret_cmd;
	size_t i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		cmd->av[i] = clean_quote(cmd->av[i]);
		if (cmd->av[i] == NULL)
		{
			free(cmd->av[i]);
			return (BACKSL_ERROR);
		}
		i++;
	}
	ret_cmd = process_clean_command(cmd);
	return (ret_cmd);
}
