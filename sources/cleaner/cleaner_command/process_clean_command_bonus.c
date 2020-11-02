#include "minishell_bonus.h"

t_clean_cmd	*init_clean_command()
{
	t_clean_cmd	*clean_cmd;
	
	clean_cmd = (t_clean_cmd *)malloc(sizeof(t_clean_cmd));
	if (clean_cmd == NULL)
		return (NULL);
	clean_cmd->count_assign = 0;
	clean_cmd->ac = 0;
	clean_cmd->index_export = 0;
	clean_cmd->av = NULL;
	clean_cmd->index_redir = 0;
	clean_cmd->count_redir = 0;
	clean_cmd->tab_redir = NULL;
	clean_cmd->tmp_tab_redir = NULL;
	clean_cmd->tmp_av = NULL;
	clean_cmd->tmp_fd_in = 0;
	clean_cmd->count_other = 0;
	clean_cmd->tmp_fd_out = 1;
	clean_cmd->tmp_fd_append = 1;
	return (clean_cmd);
}

static int			process_command_command(t_cmd *cmd)
{
	t_clean_cmd *clean_cmd;
	int			index_cmd;
	int			ret_cmd;

	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE);
		return (FAILURE);
	}
	index_cmd = get_cmd(cmd);
	iter_clean_quote(cmd, (size_t)cmd->ac);
	ret_cmd = get_envp_av(cmd, clean_cmd, index_cmd);
	if (ret_cmd == FAILURE)
		return (FAILURE);
	if (ret_cmd != NO_COMMAND)
		process_redirection(cmd, clean_cmd);
	return(SUCCESS);
}

int 				process_clean_command(t_cmd *cmd)
{
		return (process_command_command(cmd));
}