#include "minishell_bonus.h"

static enum e_state_redir	in_out(char *str)
{
	if (ft_strequ(str, LESS_THAN) == TRUE ||
			ft_strequ(str, GREATER_THAN) == TRUE || 
			ft_strequ(str, DOUBLE_GREATER) == TRUE)
		return (E_IN_REDIR);
	return (E_IN_OUT);
}

static enum e_state_redir	in_file(char *str)
{
	if (ft_strequ(str, LESS_THAN) == TRUE ||
			ft_strequ(str, GREATER_THAN) == TRUE || 
			ft_strequ(str, DOUBLE_GREATER) == TRUE)
		return (E_IN_REDIR);
	return (E_IN_OUT);
}

static enum e_state_redir	in_redir(char *str)
{
	return (E_IN_FILE);
}

int	create_tab_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	t_state_redir		function_state[] = {in_redir, in_file, in_out};
	enum e_state_redir	state;
	size_t				i;

	state = E_IN_OUT;
	i = 0;
	clean_cmd->tmp_tab_redir = (char **)malloc(sizeof(char *) * cmd->ac);
	if (clean_cmd->tmp_tab_redir == NULL)
		return (FAILURE);//ERROR
	while (i < cmd->ac)
	{
		clean_cmd->tmp_tab_redir[i] = NULL;

		state = function_state[state](cmd->av[i]);
		if (state == E_IN_REDIR || state == E_IN_FILE)
		{
			clean_cmd->tmp_tab_redir[i] = ft_strdup(cmd->av[i]);
			free(cmd->av[i]);
			cmd->av[i] = NULL;
		}
		i++;
	}
	ft_printf("\033[0;32mDEBUG REDIR BEFORE\n\033[0m");//DEBUG
	debug_redir(clean_cmd->tmp_tab_redir, cmd->ac);
	return (SUCCESS);
}