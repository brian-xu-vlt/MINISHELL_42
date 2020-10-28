#include "minishell_bonus.h"

void		free_clean_command(t_clean_cmd *clean_cmd, int flag)
{
	size_t	i;

	i = 0;
	if (flag == ALL_FREE)
	{
		free(clean_cmd->av);
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

static int		fill_cmd(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		free(cmd->av[i]);
		i++;
	}
	free(cmd->av);
	i = 0;
	cmd->av = (char **)malloc(sizeof(char *) * clean_cmd->ac);
	if (cmd->av == NULL)
		return (FAILURE);//ERROR
	while (i < clean_cmd->ac)
	{
		cmd->av[i] = clean_cmd->av[i];
		i++;
	}
	cmd->ac = clean_cmd->ac;
	cmd->count_assign = clean_cmd->count_assign;
	return (SUCCESS);
}

int		fill_clean_cmd(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;
	size_t	i_ass;
	size_t	i_av;

	i = 0;
	i_ass = 0;
	i_av = 0;
	while (i < (size_t)cmd->ac)
	{
		if (i < clean_cmd->count_assign)
		{
			cmd->envp[i_ass] = ft_strdup(cmd->av[i]);
			i_ass++;
		}
		if (i >= clean_cmd->count_assign)
		{
			clean_cmd->av[i_av] = ft_strdup(cmd->av[i]);
			i_av++;
		}
		i++;
	}
	if (fill_cmd(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	init_tab_assign_ac(t_clean_cmd *clean_cmd, t_cmd *cmd)
{
	clean_cmd->av = (char **)malloc(sizeof(char *) * clean_cmd->ac);
	if (clean_cmd->av == NULL)
		return (FAILURE);//ERROR
	cmd->envp = (char **)malloc(sizeof(char *) * clean_cmd->count_assign);
	if (cmd->envp == NULL)
		return (FAILURE);//ERROR
}

void	count_ac_assign(t_cmd *cmd, t_clean_cmd *clean_cmd, bool is_bad)
{
	size_t	i;
	size_t	i_assign;
	size_t	is_redir;

	i = 0;
	i_assign = 0;
	ft_printf("IS_BAD = %d\n", is_bad);
	is_redir == false;
	while (i < (size_t)cmd->ac)
	{
		if (cmd->count_assign != 0 && ft_strequ(cmd->av[i], STR_EXPORT) == FALSE
			&& i == cmd->tab_assign[i_assign])
		{
			clean_cmd->count_assign++;
			i_assign++;
		}
		else if (ft_strequ(cmd->av[i], STR_EXPORT) == TRUE)
		{
			clean_cmd->index_export = i;
			return ;
		}
		i++;
	}
}