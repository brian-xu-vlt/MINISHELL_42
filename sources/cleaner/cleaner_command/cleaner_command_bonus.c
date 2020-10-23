#include "minishell_bonus.h"

bool is_bad_ass_exp(t_cmd *cmd)
{
	ft_printf("IS_BAD_ASS_EXP\n"); //
	return (false);
}

static bool is_wrong_char(t_vector *vct)
{
	size_t i;

	while (vct_getlen(vct) > 0)
	{
		i = 0;
		while (i < NB_DEL)
		{
			if (vct_getfirstchar(vct) == DEL[i])
				return (true);
			i++;
		}
		vct_pop(vct);
	}
	return (false);
}

static size_t verif_assign(t_vector *vct_av, size_t id_equal)
{
	t_vector *vct;

	vct = vct_new();
	vct_cpy(vct, vct_av);
	vct_cutfrom(vct, vct_getlen(vct) - id_equal);
	ft_printf("VCT = %s\n", vct_getstr(vct)); //DEBUG
	if (vct_getlen(vct) == 0)
	{
		vct_del(&vct);
		return (false);
	}
	if (ft_isdigit(vct_getfirstchar(vct)) == TRUE)
	{
		vct_del(&vct);
		return (false);
	}
	if (is_wrong_char(vct) == true)
	{
		vct_del(&vct);
		return (false);
	}
	vct_del(&vct);
	return (true);
}

enum e_cmd get_cmd_type(t_cmd *cmd)
{
	size_t i;
	t_vector *vct_av;
	size_t id_equal;
	size_t is_assign;

	i = 0;
	vct_av = vct_new();
	ft_printf("GET_CMD_TYPE\n"); //
	id_equal = 0;
	is_assign = true;
	while (i < (size_t)cmd->ac)
	{
		vct_addstr(vct_av, cmd->av[i]);
		ft_printf("VCT_AV[%d] = %s\n", i, vct_getstr(vct_av)); //DEBUG
		id_equal = vct_clen(vct_av, ASSIGN);
		if (id_equal != vct_getlen(vct_av))
		{
			is_assign = verif_assign(vct_av, id_equal);
			if (is_assign == false)
			{
				vct_del(&vct_av);
				return (E_COMMAND);
			}
		}
		else if (ft_strequ(vct_getstr(vct_av), STR_EXPORT) == TRUE)
		{
			vct_del(&vct_av);
			return (i == (size_t)cmd->ac - 1 ? E_EXPORT_EXEC : E_EXPORT_NO_EXEC);
		}
		else if (id_equal == vct_getlen(vct_av) && ft_strequ(vct_getstr(vct_av), STR_EXPORT) == FALSE)
		{
			vct_del(&vct_av);
			return (E_COMMAND);
		}
		vct_clear(vct_av);
		i++;
	}
	vct_del(&vct_av);
	return (E_ANY);
}
