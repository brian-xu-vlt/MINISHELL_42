#include "minishell_bonus.h"

static int	handle_only_envp(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	cmd->envp = (char **)malloc(sizeof(char *) * cmd->ac);
	if (cmd->envp == NULL)
		return (FAILURE);
	while (i < (size_t)cmd->ac)
	{
		cmd->envp[i] = ft_strdup(cmd->av[i]);
		ft_strdel(&cmd->av[i]);
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
			ft_strdel(&cmd->av[i]);
			i_envp++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	clean_av(t_cmd *cmd, t_clean_cmd *clean_cmd, bool no_cmd,
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

static int	handle_get_envp(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	bool	no_cmd;
	int		ret_cmd;

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
	ret_cmd = clean_av(cmd, clean_cmd, no_cmd, index_cmd);
	if (ret_cmd == NO_COMMAND)
		return (ret_cmd);
	return (SUCCESS);
}

static int	fill_clean_cmd(int index_cmd, t_cmd *cmd, t_clean_cmd *clean_cmd)
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

static int	fill_cmd(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;

	cmd->ac = clean_cmd->ac;
	ft_printf("AC = %d\n", cmd->ac);//DEBUG
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

int	get_envp_av(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	int		ret_envp;
	int		ret_clean_cmd;
	int		ret_cmd;

	ret_envp = handle_get_envp(cmd, clean_cmd, index_cmd);
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

static bool	verif_assign_cmd(char *str)
{
	t_vector	*vct;
	size_t	id_equal;

	vct = vct_new();
	vct_addstr(vct, str);
	id_equal = vct_clen(vct, ASSIGN);
	vct_cutfrom(vct, vct_getlen(vct) - id_equal);
	if (is_wrong_ass(vct) == false)
	{
		vct_del(&vct);
		return (true);
	}
	vct_del(&vct);
	return (false);
}

static bool	verif_exp_cmd(char *str)
{
	t_vector	*vct;

	vct = vct_new();
	vct_addstr(vct, str);
	vct_pop(vct);
	if (is_wrong_ass(vct) == false)
	{
		vct_del(&vct);
		return (true);
	}
	vct_del(&vct);
	return (false);
}

static int	process_get_cmd(size_t i_assign, size_t i_exp, size_t i, t_cmd *cmd)
{
	if (i_assign < (size_t)cmd->count_assign && cmd->count_assign != 0
			&& i == (size_t)cmd->tab_assign[i_assign])
	{
		if (verif_assign_cmd(cmd->av[i]) == true)
			return (TRUE_ASSIGN);
		i_assign++;
	}
	else if (i_exp < (size_t)cmd->count_exp && cmd->count_exp != 0
				&& i == (size_t)cmd->tab_exp[i_exp])
	{
		if (verif_exp_cmd(cmd->av[i]) == true)
			return (TRUE_EXP);
		i_exp++;
	}
	else
		return (TRUE_CMD);
	return (FALSE);
}

int	get_cmd(t_cmd *cmd)
{
	size_t	i;
	size_t	i_assign;
	size_t	i_exp;
	int		ret;

	i = 0;
	i_assign = 0;
	i_exp = 0;
	while (i < (size_t)cmd->ac)
	{
		ret = process_get_cmd(i_assign, i_exp, i, cmd);
		if (ret != FALSE)
			return (i);
		if (ret == TRUE_ASSIGN)
			i_assign++;
		else if (ret == TRUE_EXP)
			i_exp++;
		i++;
	}
	return (FAILURE);
}