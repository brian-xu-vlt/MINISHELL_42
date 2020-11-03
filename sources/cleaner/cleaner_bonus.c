#include "minishell_bonus.h"

void		free_clean_command(t_clean_cmd *clean_cmd, int flag)
{
	size_t	i;

	i = 0;
	if (flag == ALL_FREE)
	{
		while (i < clean_cmd->ac)
		{
			free(clean_cmd->av[i]);
			i++;
		}
		free(clean_cmd->av);
		i = 0;
		while (i < clean_cmd->count_redir)
		{
			free(clean_cmd->tab_redir[i]);
			i++;
		}
		free(clean_cmd->tab_redir);
		free(clean_cmd->tmp_tab_redir);
		free(clean_cmd->tmp_av);
	}
	free(clean_cmd);
}

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

int			process_clean_command(t_cmd *cmd)
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
	{
		free_clean_command(clean_cmd, ALL_FREE);
		return (FAILURE);
	}
	if (ret_cmd != NO_COMMAND)
		process_redirection(cmd, clean_cmd);
	free_clean_command(clean_cmd, ALL_FREE);
	return (SUCCESS);
}

void		clean_quote(t_cmd *cmd)
{
	size_t	i;
	char	*tmp_av0;

	i = 0;
	tmp_av0 = ft_strdup(cmd->av[0]);
	while (i < (size_t)cmd->ac)
	{
		if (is_clean(i, tmp_av0, cmd->av[i], cmd) == true)
			process_clean_command_quote(cmd, i);
		i++;
	}
	free(tmp_av0);
}

int			cleaner(t_cmd *cmd)
{
	int	ret_cmd;

	clean_quote(cmd);
	ret_cmd = process_clean_command(cmd);
	return (ret_cmd);
}