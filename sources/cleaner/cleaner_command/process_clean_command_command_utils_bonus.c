#include "minishell_bonus.h"

static int	handle_only_envp(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;

	i = 0;
	cmd->envp = (char **)malloc(sizeof(char *) * cmd->ac);
	if (cmd->envp == NULL)
		return (FAILURE);
	while (i < cmd->ac)
	{
		cmd->envp[i] = ft_strdup(cmd->av[i]);
		i++;
	}
	return (SUCCESS);
}

static int	handle_envp(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	size_t	i;
	size_t	i_envp;

	i = 0;
	i_envp = 0;
	while (i < (size_t)index_cmd)
	{
		if (ft_strlen(cmd->av[i]) != 0)
			clean_cmd->count_assign++;
		i++;
	}
	cmd->envp = (char **)malloc(sizeof(char *) * clean_cmd->count_assign);
	if (cmd->envp == NULL)
		return (FAILURE);
	i = 0;
	cmd->count_assign = clean_cmd->count_assign;
	while (i < (size_t)index_cmd)
	{
		if (ft_strlen(cmd->av[i]) != 0)
		{
			cmd->envp[i_envp] = ft_strdup(cmd->av[i]);
			i_envp++;
		}
		i++;
	}
	return (SUCCESS);
}

int	get_envp_av(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	size_t	i;
	size_t	i_clean;
	bool	no_cmd;

	i = 0;
	i_clean = 0;
	no_cmd = false;
	if (index_cmd > 0)
		if (handle_envp(cmd, clean_cmd, index_cmd) == FAILURE)
			return (FAILURE);
	if (index_cmd == FAILURE)
	{
		no_cmd = true;
		if (handle_only_envp(cmd, clean_cmd) == FAILURE)
			return (FAILURE);
	}
	if (no_cmd == false)
		clean_cmd->ac = cmd->ac - index_cmd;
	else
	{
		i = 0;
		while (i < cmd->ac)
		{
			free(cmd->av[i]);
			i++;
		}
		free(cmd->av);
		cmd->av = NULL;
		cmd->ac = 0;
		return (NO_COMMAND);
	}
	clean_cmd->av = (char **)malloc(sizeof(char *) * clean_cmd->ac);
	if (clean_cmd->av == NULL)
		return (FAILURE);
	i = index_cmd;
	while (i_clean < clean_cmd->ac)
	{
		clean_cmd->av[i_clean] = ft_strdup(cmd->av[i]);
		free(cmd->av[i]);
		i_clean++;
		i++;
	}
	i = 0;
	while (i < (size_t)cmd->ac)
	{
		free(cmd->av[i]);
		i++;
	}
	//free(cmd->av);
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

int	get_cmd(t_cmd *cmd)
{
	size_t	i;
	size_t	i_assign;
	t_vector	*vct;
	size_t	id_equal;
	size_t	i_exp;

	i = 0;
	i_assign = 0;
	vct = vct_new();
	i_exp = 0;
	while (i < (size_t)cmd->ac)
	{
		if (i_assign < (size_t)cmd->count_assign && cmd->count_assign != 0
				&& i == (size_t)cmd->tab_assign[i_assign])
		{
			vct_addstr(vct, cmd->av[i]);
			id_equal = vct_clen(vct, ASSIGN);
			vct_cutfrom(vct, vct_getlen(vct) - id_equal);
			if (is_wrong_ass(vct) == false)
			{
				vct_del(&vct);
				return (i);
			}
			i_assign++;
			vct_clear(vct);
		}
		else if (i_exp < (size_t)cmd->count_exp && cmd->count_exp != 0
					&& i == (size_t)cmd->tab_exp[i_exp])
		{
			vct_addstr(vct, cmd->av[i]);
			vct_pop(vct);
			if (is_wrong_ass(vct) == false)
			{
				vct_del(&vct);
				return (i);
			}
			i_exp++;
			vct_clear(vct);
		}
		else
		{
			vct_del(&vct);
			return (i);
		}
		i++;
	}
	vct_del(&vct);
	return (FAILURE);
}