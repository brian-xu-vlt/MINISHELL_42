#include "minishell_bonus.h"

static int	handle_only_envp(t_cmd *cmd)
{
	size_t	i;
	size_t	new_ac;
	size_t	i_envp;

	i = 0;
	new_ac = 0;
	while (i < cmd->ac)
	{
		if (ft_strlen(cmd->av[i]) != 0)
			new_ac++;
		i++;
	}
	cmd->envp = (char **)malloc(sizeof(char *) * new_ac);
	if (cmd->envp == NULL)
		return (FAILURE);
	i = 0;
	i_envp = 0;
	while (i < (size_t)cmd->ac)
	{
		if (ft_strlen(cmd->av[i]) != 0)
		{
			cmd->envp[i_envp] = ft_strdup(cmd->av[i]);
			i_envp++;
		}
		ft_strdel(&cmd->av[i]);
		i++;
	}
	cmd->count_assign = new_ac;
	return (SUCCESS);
}

static void	fill_envp(t_cmd *cmd, int index_cmd)
{
	size_t	i;
	size_t	i_envp;

	i_envp = 0;
	i = 0;
	while (i < (size_t)index_cmd)
	{
		if (ft_strlen(cmd->av[i]) != 0)
		{
			cmd->envp[i_envp] = ft_strdup(cmd->av[i]);
			ft_strdel(&cmd->av[i]);
			i_envp++;
		}
		i++;
	}
}

static int	handle_envp(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)index_cmd)
	{
		if (ft_strlen(cmd->av[i]) != 0)
			clean_cmd->count_assign++;
		i++;
	}
	ft_printf("clean_cmd->count_assign = %d\n", clean_cmd->count_assign);//DEBUF
	cmd->envp = (char **)malloc(sizeof(char *) * clean_cmd->count_assign);
	if (cmd->envp == NULL)
		return (FAILURE);
	i = 0;
	cmd->count_assign = clean_cmd->count_assign;
	fill_envp(cmd, index_cmd);
	return (SUCCESS);
}

static int	handle_get_envp(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	bool	no_cmd;
	int		ret_cmd;
	ft_printf("index cmd = %d\n", index_cmd);//DEBUG
	no_cmd = false;
	if (index_cmd > 0)
		if (handle_envp(cmd, clean_cmd, index_cmd) == FAILURE)
			return (FAILURE);
	if (index_cmd == FAILURE)
	{
		no_cmd = true;
		if (handle_only_envp(cmd) == FAILURE)
			return (FAILURE);
	}
	if (index_cmd == 0)
		cmd->count_assign = 0;
	ret_cmd = clean_cmd_av(cmd, clean_cmd, no_cmd, index_cmd);
	if (ret_cmd == NO_COMMAND)
		return (ret_cmd);
	return (SUCCESS);
}

int			get_envp_av(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	int		ret_envp;
	int		ret_clean_cmd;
	int		ret_cmd;

	ret_envp = handle_get_envp(cmd, clean_cmd, index_cmd);
	ft_printf("ret_envp = %d\n", ret_envp);//DEBUG
	if (ret_envp != SUCCESS)
		return (ret_envp);
	ret_clean_cmd = fill_clean_cmd(index_cmd, cmd, clean_cmd);
	if (ret_clean_cmd == FAILURE)
		return (FAILURE);
	ret_cmd = fill_cmd(cmd, clean_cmd);
	if (ret_cmd == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
