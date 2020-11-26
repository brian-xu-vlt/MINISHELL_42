#include "minishell_bonus.h"

static bool	verif_expect(t_vector *vct, t_vector *vct_cpy)
{
	size_t		id_equal;

	id_equal = vct_clen(vct, ASSIGN);
	vct_cutfrom(vct, vct_getlen(vct) - id_equal);
	if (ft_isdigit(vct_getfirstchar(vct)) == true ||
			vct_chr(vct, C_PATH) != FAILURE || is_wrong_ass(vct) == false)
	{
		vct_del(&vct);
		vct_del(&vct_cpy);
		return (true);
	}
	return (false);
}

bool		verif_assign_cmd(char *str)
{
	t_vector	*vct;
	ssize_t		nb_assign;
	t_vector	*vct_cpy;

	vct = vct_new();
	vct_cpy = vct_new();
	vct_addstr(vct, str);
	vct_addstr(vct_cpy, vct_getstr(vct));
	nb_assign = vct_nbchar(vct_cpy, S_ASSIGN);
	if (nb_assign > 1)
	{
		vct_del(&vct);
		vct_del(&vct_cpy);
		return (true);
	}
	if (verif_expect(vct, vct_cpy) == true)
		return (true);
	vct_del(&vct);
	vct_del(&vct_cpy);
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

/*static void	debug_tab_assign(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < cmd->count_assign)
	{
		ft_printf("cmd->tab_assign[%d] = %d\n", i, cmd->tab_assign[i]);
		i++;
	}
	ft_printf("\n\n");//DEBUG
}

static void	debug_tab_exp(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < cmd->count_exp)
	{
		ft_printf("cmd->tab_exp[%d] = %d\n", i, cmd->tab_exp[i]);
		i++;
	}
	ft_printf("\n\n");//DEBUG
}*/

static void	how_increment(t_cmd *cmd, size_t *i, size_t *i_assign, size_t *i_exp)
{
	size_t	tmp_i;
	// size_t	i_tab_exp;

	tmp_i = 0;
	while (*i < (size_t)cmd->ac)
	{
		if (ft_strequ(LESS_THAN, cmd->av[*i]) == TRUE ||
				ft_strequ(GREATER_THAN, cmd->av[*i]) == TRUE ||
				ft_strequ(DOUBLE_GREATER, cmd->av[*i]) == TRUE)
		{
			if ((size_t)cmd->count_exp != 0 && *i_exp != (size_t)cmd->count_exp &&
					*i == cmd->tab_exp[*i_exp])
				return ;
			if ((size_t)cmd->count_assign != 0 && *i_assign != (size_t)cmd->count_assign &&
					*i + 1 == cmd->tab_assign[*i_assign])
				*i_assign = *i_assign + 1;
			else if ((size_t)cmd->count_exp != 0 && *i_exp != (size_t)cmd->count_exp &&
					*i + 1 == cmd->tab_exp[*i_exp])
				*i_exp = *i_exp + 1;
			*i = *i + 2;
		}
		else
			return ;
	}
}

static int	set_redir_before(t_cmd *cmd, size_t i)
{
	size_t	start;

	start = 0;
	cmd->tab_redir_before = (char **)malloc(sizeof(char *) * (i + 1));
	if (cmd->tab_redir_before == NULL)
		exit_routine_le(ERR_MALLOC);
	while (start < i)
	{
		cmd->tab_redir_before[start] = ft_strdup(cmd->av[start]);
		free(cmd->av[start]);
		cmd->av[start] = NULL;
		start++;
	}
	cmd->tab_redir_before[start] = NULL;
	cmd->count_redir_before = i;
	if (cmd->count_redir_before == (size_t)cmd->ac)
	{
		ft_free_tab(cmd->ac, cmd->av);
		free(cmd->av);
		cmd->av = NULL;
		return (ONLY_REDIR_BEFORE);
	}
	return (SUCCESS);
}

int			get_cmd(t_cmd *cmd)
{
	size_t	i;
	size_t	i_assign;
	size_t	i_exp;
	int		ret;
	int		flag_exp_before;

	i = 0;
	i_assign = 0;
	i_exp = 0;
	flag_exp_before = false;
	while (i < (size_t)cmd->ac)
	{
		if (cmd->av[i] == NULL)
		{
			i++;
			continue ;
		}
		if (ft_strlen(cmd->av[i]) == 0 && i + 1 != (size_t)cmd->ac)
		{
			i++;
			continue ;
		}
		if (i == 0 && (ft_strequ(LESS_THAN, cmd->av[i]) == TRUE ||
				ft_strequ(GREATER_THAN, cmd->av[i]) == TRUE ||
				ft_strequ(DOUBLE_GREATER, cmd->av[i]) == TRUE))
		{
			flag_exp_before = true;
			if ((i == 0 && cmd->ac == 1) ||
					(cmd->count_exp != 0 && i == cmd->tab_exp[0]))
				return (0);
			how_increment(cmd, &i, &i_assign, &i_exp);
			if (set_redir_before(cmd, i) == ONLY_REDIR_BEFORE)
				return (ONLY_REDIR_BEFORE);
			continue ;
		}
		ret = process_get_cmd(i_assign, i_exp, i, cmd);
		if (ret == FALSE_ASSIGN || ret == FALSE_EXP || ret == TRUE_CMD)
		{
			return (i);
		}
		if (ret == TRUE_ASSIGN)
			i_assign++;
		else if (ret == TRUE_EXP)
			i_exp++;
		i++;
	}
	return (FAILURE);
}
