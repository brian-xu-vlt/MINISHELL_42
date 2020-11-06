#include "minishell_bonus.h"

static bool	verif_assign_cmd(char *str)
{
	t_vector	*vct;
	size_t		id_equal;

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
	if (vct_getfirstchar(vct) == C_EXPORT)
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
		if (ft_strchr(cmd->av[i], ASSIGN) == NULL)
			return (TRUE_CMD);
		if (verif_assign_cmd(cmd->av[i]) == false)
			return (TRUE_ASSIGN);
		return (FALSE_ASSIGN);
	}
	else if (i_exp < (size_t)cmd->count_exp && cmd->count_exp != 0
				&& i == (size_t)cmd->tab_exp[i_exp])
	{
		if (ft_strchr(cmd->av[i], EXP) == NULL)
			return (TRUE_CMD);
		if (verif_exp_cmd(cmd->av[i]) == false)
			return (TRUE_EXP);
		return (FALSE_EXP);
	}
	return (TRUE_CMD);
}

int			get_cmd(t_cmd *cmd)
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
		if (ret == FALSE_ASSIGN || ret == FALSE_EXP || ret == TRUE_CMD)
			return (i);
		if (ret == TRUE_ASSIGN)
			i_assign++;
		else if (ret == TRUE_EXP)
			i_exp++;
		i++;
	}
	return (FAILURE);
}
