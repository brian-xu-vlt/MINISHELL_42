
#include "minishell_bonus.h"

int	clean_cmd_av(t_cmd *cmd, t_clean_cmd *clean_cmd, bool no_cmd,
					int index_cmd)
{
	size_t	i;

	if (no_cmd == false)
		clean_cmd->ac = cmd->ac - index_cmd;
	else
	{
		i = 0;
		while (i < (size_t)cmd->ac)
		{
			free(cmd->av[i]);
			i++;
		}
		free(cmd->av);
		cmd->av = NULL;
		cmd->ac = 0;
		return (NO_COMMAND);
	}
	return (SUCCESS);
}

int	fill_clean_cmd(int index_cmd, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i_clean;
	size_t	i;

	clean_cmd->av = (char **)malloc(sizeof(char *) * clean_cmd->ac);
	if (clean_cmd->av == NULL)
		return (FAILURE);
	i = index_cmd;
	i_clean = 0;
	while (i_clean < clean_cmd->ac)
	{
		clean_cmd->av[i_clean] = ft_strdup(cmd->av[i]);
		free(cmd->av[i]);
		i_clean++;
		i++;
	}
	free(cmd->av);
	return (SUCCESS);
}

int	fill_cmd(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;

	cmd->ac = clean_cmd->ac;
	cmd->av = (char **)malloc(sizeof(char *) * cmd->ac);
	if (cmd->av == NULL)
		return (FAILURE);
	i = 0;
	while (i < (size_t)cmd->ac)
	{
		cmd->av[i] = ft_strdup(clean_cmd->av[i]);
		i++;
	}
	return (SUCCESS);
}
