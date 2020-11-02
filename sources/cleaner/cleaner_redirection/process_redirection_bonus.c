#include "minishell_bonus.h"

int process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;

	i = 0;
	cmd->redirection = 0;
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	debug_fd_string(cmd->fd_string);
	cmd->tmp_fd_in = clean_cmd->tmp_fd_in;	
	cmd->tmp_fd_out = clean_cmd->tmp_fd_out;
	cmd->tmp_fd_append = clean_cmd->tmp_fd_append;	
	cmd->count_redir= clean_cmd->count_redir;
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
