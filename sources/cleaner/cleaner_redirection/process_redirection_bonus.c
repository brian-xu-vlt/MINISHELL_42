#include "minishell_bonus.h"

static int	hub_process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
	{	
		ft_free_tab(cmd->ac, clean_cmd->tmp_tab_redir);
		return (FAILURE);
	}
	return (SUCCESS);
}

int							process_redirection(t_cmd *cmd,
													t_clean_cmd *clean_cmd)
{
	size_t	i;

	i = 0;
	cmd->redirection = 0;
	if (hub_process_redirection(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	cmd->tmp_fd_in = clean_cmd->tmp_fd_in;
	cmd->tmp_fd_out = clean_cmd->tmp_fd_out;
	cmd->tmp_fd_append = clean_cmd->tmp_fd_append;
	cmd->count_redir = clean_cmd->count_redir;
	if (cmd->count_redir == 0)
		return (SUCCESS);
	cmd->tab_redir = (char **)malloc(sizeof(char *) * (cmd->count_redir + 1));
	if (cmd->tab_redir == NULL)
		return (FAILURE);
	cmd->tab_redir[cmd->count_redir] = NULL;
	while (i < cmd->count_redir)
	{
		cmd->tab_redir[i] = ft_strdup(clean_cmd->tab_redir[i]);
		i++;
	}
	return (SUCCESS);
}
