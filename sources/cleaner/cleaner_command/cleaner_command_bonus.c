#include "minishell_bonus.h"

int	clean_av_len(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;
	size_t	i_clean;
	size_t	count_zero;
	bool	is_export;

	i = 0;
	count_zero = 0;
	is_export = false;
	ft_printf("clean_cmd->ac = %d\n", clean_cmd->ac);//DEBUG
	ft_printf("cmd->Ac = %d\n", cmd->ac);//DEBUG
	while (i < cmd->ac)
	{
		ft_printf("i = %d\n", i);//DEBUG
		if (ft_strequ(STR_EXPORT, cmd->av[i]) == TRUE)
			is_export = true;
		if (ft_strlen(cmd->av[i]) == 0 && is_export == false)
			count_zero++;
		i++;
	}
	if (count_zero == 0)
		return (SUCCESS);
	clean_cmd->ac = cmd->ac - count_zero;
	clean_cmd->av = (char **)malloc(sizeof(char *) * cmd->ac - count_zero);
	if (clean_cmd->av == NULL)
		return (FAILURE);
	i = 0;
	i_clean = 0;
	is_export = false;
	while (i < cmd->ac)
	{
		if (ft_strequ(STR_EXPORT, cmd->av[i]) == TRUE)
			is_export = true;
		if (is_export == false && (ft_strlen(cmd->av[i]) == 0))
		{
			i++;
			continue ;
		}
		clean_cmd->av[i_clean] = ft_strdup(cmd->av[i]);
		i_clean++;
		i++;
	}
	i = 0;
	while (i < cmd->ac)
	{
		free(cmd->av[i]);
		i++;
	}
	free(cmd->av);
	cmd->ac = cmd->ac - count_zero;
	cmd->av = (char **)malloc(sizeof(char *) * cmd->ac);
	if (cmd->av == NULL)
		return (FAILURE);
	i = 0;
	while (i < cmd->ac)
	{
		cmd->av[i] = ft_strdup(clean_cmd->av[i]);
		i++;
	}
	return (SUCCESS);
}

bool		is_bad_ass(t_cmd *cmd)
{
	size_t		i;
	t_vector	*vct_av;
	size_t		i_ass;

	i = 0;
	vct_av = vct_new();
	i_ass = 0;
	while (i < (size_t)cmd->count_assign + 1)
	{
		if (i == (size_t)cmd->tab_assign[i_ass])
		{
			if (process_wrong_ass(cmd, vct_av, i_ass) == false)
			{
				vct_del(&vct_av);
				return (true);
			}
			vct_clear(vct_av);
			if (i_ass + 1 != (size_t)cmd->count_assign)
				i_ass++;
		}
		i++;
	}
	vct_del(&vct_av);
	return (false);
}

enum e_cmd process_get_cmd_type(t_vector *vct, size_t i, size_t ac, t_cmd *cmd)
{
	ssize_t id_equal;
	size_t is_assign;
	enum e_cmd is_export_or_assign;

	id_equal = FAILURE;
	if (cmd->count_assign != 0 && i == cmd->tab_assign[0])
	{
		id_equal = vct_clen(vct, ASSIGN);
		if (id_equal != vct_getlen(vct))
		{
			is_assign = verif_assign(vct, id_equal);
			if (is_assign == false)
				return (E_COMMAND);
		}
	}
	if (cmd->count_exp != 0 && i == cmd->tab_exp[0])
	{
		vct_pop(vct);
		if (vct_getlen(vct) == 0)
			return (E_COMMAND);
		if (is_wrong_ass(vct) == false)
			return (E_COMMAND);
	}
	is_export_or_assign = export_or_command(vct, i, id_equal, ac);
	if (is_export_or_assign != E_ANY)
		return (is_export_or_assign);
	return (E_ANY);
}

enum e_cmd get_cmd_type(t_cmd *cmd)
{
	size_t		i;
	t_vector	*vct_av;
	enum e_cmd	cmd_type;

	i = 0;
	vct_av = vct_new();
	while (i < (size_t)cmd->ac)
	{
		vct_addstr(vct_av, cmd->av[i]);
		if (vct_getlen(vct_av) == 0)
			cmd_type = E_ANY;
		else
			cmd_type = process_get_cmd_type(vct_av, i, cmd->ac, cmd);
		if (cmd_type != E_ANY)
		{
			vct_del(&vct_av);
			return (cmd_type);
		}
		vct_clear(vct_av);
		i++;
	}
	vct_del(&vct_av);
	return (E_ANY);
}
