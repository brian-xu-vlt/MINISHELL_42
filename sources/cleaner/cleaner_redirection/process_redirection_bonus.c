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

static int	create_tab_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	t_state_redir		function_state[] = {in_redir, in_file, in_out};
	enum e_state_redir	state;
	size_t				i;

	state = E_IN_OUT;
	i = 0;
	while (i < cmd->ac)
	{
		ft_printf("state = %d\n", state);//DEBUG
		state = function_state[state](cmd->av[i]);
		ft_printf("str = %s\n\n", cmd->av[i]);//DEBUG
		i++;
	}


	return (SUCCESS);
}

int	process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	ft_printf("PROCESS_REDIRECTION\n");//DEBUG
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);

}