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
	(void)str;
	return (E_IN_FILE);
}

int							create_tab_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	t_state_redir		function_state[] = {in_redir, in_file, in_out};
	enum e_state_redir	state;
	size_t				i;

	state = E_IN_OUT;
	i = 0;
	clean_cmd->tmp_tab_redir = (char **)malloc(sizeof(char *) * cmd->ac);
	if (clean_cmd->tmp_tab_redir == NULL)
		return (FAILURE);//ERROR
	while (i < (size_t)cmd->ac)
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
	return (SUCCESS);
}

int 						process_redirection(t_cmd *cmd,
													t_clean_cmd *clean_cmd)
{
	size_t	i;

	i = 0;
	cmd->redirection = 0;
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	//debug_fd_string(cmd->fd_string);
	cmd->tmp_fd_in = clean_cmd->tmp_fd_in;
	cmd->tmp_fd_out = clean_cmd->tmp_fd_out;
	cmd->tmp_fd_append = clean_cmd->tmp_fd_append;
	cmd->count_redir = clean_cmd->count_redir;
	cmd->tab_redir = (char **)malloc(sizeof(char *) * cmd->count_redir);
	if (cmd->tab_redir == NULL)
		return (FAILURE);//ERROR
	while (i < cmd->count_redir)
	{
		cmd->tab_redir[i] = ft_strdup(clean_cmd->tab_redir[i]);
		i++;
	}
	return (SUCCESS);
}
