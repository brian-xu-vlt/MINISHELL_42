#include "minishell_bonus.h"

void			free_clean_command(t_clean_cmd *clean_cmd)
{
	size_t	i;

	i = 0;
	free(clean_cmd->av);
	/*while (i < clean_cmd->ac)
	{
		free(clean_cmd->av[i]);
	}*/
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
}

void		fill_clean_cmd(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;
	size_t	i_ass;
	size_t	i_av;

	i = 0;
	i_ass = 0;
	i_av = 0;
	while (i < (size_t)cmd->ac)
	{
		ft_printf("I = %d\n", i);//DEBUG
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
	fill_cmd(cmd, clean_cmd);
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

	i = 0;
	i_assign = 0;
	ft_printf("IS_BAD = %d\n", is_bad);
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