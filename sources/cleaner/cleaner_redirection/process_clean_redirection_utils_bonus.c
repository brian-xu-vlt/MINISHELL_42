#include "minishell_bonus.h"

int	count_av(t_cmd *cmd)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < (size_t)cmd->ac)
	{
		if (cmd->av[i] != NULL)
			count++;
		i++;
	}
	return (count);
}

int	count_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < (size_t)cmd->ac)
	{
		if (clean_cmd->tmp_tab_redir[i] != NULL)
			count++;
		i++;
	}
	return (count);
}

int	init_av_redir(t_clean_cmd *clean_cmd, size_t nb_av, size_t nb_redir)
{
	clean_cmd->tab_redir = (char **)malloc(sizeof(char *) * nb_redir);
	if (clean_cmd->tab_redir == NULL)
		return (FAILURE);//ERROR
	clean_cmd->tmp_av = (char **)malloc(sizeof(char *) * nb_av);
	if (clean_cmd->tmp_av == NULL)
		return (FAILURE);//ERROR
	return (SUCCESS);
}