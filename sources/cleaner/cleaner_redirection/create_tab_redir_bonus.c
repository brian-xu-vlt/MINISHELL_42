#include "minishell_bonus.h"

static enum e_state_redir	in_out(char *str, enum e_token_type type)
{
	if ((type != E_LESS_THAN && type != E_GREATER_THAN &&
			type != E_DOUBLE_GREATER))
		return (E_IN_OUT);
	if ((ft_strequ(str, LESS_THAN) == TRUE ||
			ft_strequ(str, GREATER_THAN) == TRUE ||
			ft_strequ(str, DOUBLE_GREATER) == TRUE) && type != E_EXP)
		return (E_IN_REDIR);
	return (E_IN_OUT);
}

static enum e_state_redir	in_file(char *str, enum e_token_type type)
{
	if ((type != E_LESS_THAN && type != E_GREATER_THAN &&
			type != E_DOUBLE_GREATER))
		return (E_IN_OUT);
	if ((ft_strequ(str, LESS_THAN) == TRUE ||
			ft_strequ(str, GREATER_THAN) == TRUE ||
			ft_strequ(str, DOUBLE_GREATER) == TRUE) && type != E_EXP)
		return (E_IN_REDIR);
	return (E_IN_OUT);
}

static enum e_state_redir	in_redir(char *str, enum e_token_type type)
{
	(void)str;
	(void)type;
	return (E_IN_FILE);
}

int							create_tab_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	static t_state_redir	function_state[] = {in_redir, in_file, in_out};
	enum e_state_redir		state;
	size_t					i;

	state = E_IN_OUT;
	i = 0;
	clean_cmd->tmp_tab_redir = (char **)malloc(sizeof(char *) * cmd->ac);
	if (clean_cmd->tmp_tab_redir == NULL)
		return (FAILURE);
	while (i < (size_t)cmd->ac)
	{
		clean_cmd->tmp_tab_redir[i] = NULL;
		state = function_state[state](cmd->av[i],
					cmd->type[clean_cmd->index_cmd]);
		if (state == E_IN_REDIR || state == E_IN_FILE)
		{
			if (cmd->av[i] != NULL)
				clean_cmd->tmp_tab_redir[i] = ft_strdup(cmd->av[i]);
			if (cmd->av[i] == NULL)
				clean_cmd->tmp_tab_redir[i] = NULL;
			free(cmd->av[i]);
			cmd->av[i] = NULL;
		}
		clean_cmd->index_cmd++;
		i++;
	}
	return (SUCCESS);
}
