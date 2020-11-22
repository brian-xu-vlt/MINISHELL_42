#include "minishell_bonus.h"

void free_clean_command(t_clean_cmd *clean_cmd, int flag)
{
	size_t i;

	i = 0;
	if (flag == ALL_FREE || flag == MALLOC)
	{
		if (clean_cmd->av != NULL)
		{
			ft_free_tab(clean_cmd->av, clean_cmd->ac);
			free(clean_cmd->av);
		}
		if (clean_cmd->tab_redir != NULL)
		{
			ft_free_tab(clean_cmd->tab_redir, clean_cmd->count_redir);
			free(clean_cmd->tab_redir);
		}
		free(clean_cmd->tmp_tab_redir);
		free(clean_cmd->tmp_av);
	}
	free(clean_cmd);
	if (flag == MALLOC || flag == NOT_ALL_FREE)
		exit_routine_le(ERR_MALLOC);
}

t_clean_cmd *init_clean_command(void)
{
	t_clean_cmd *clean_cmd;

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
	clean_cmd->index_cmd = 0;
	return (clean_cmd);
}

int	count_clean_exp(char **av, size_t size)
{
	size_t	i;
	size_t	clean_exp;

	i = 0;
	clean_exp = 0;
	while (i < size)
	{
		if (ft_strchr(av[i], EXP) != NULL)
			clean_exp++;
		i++;
	}
	return (clean_exp);
}
