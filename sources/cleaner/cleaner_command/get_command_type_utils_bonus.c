#include "minishell_bonus.h"

bool		is_wrong_char(t_vector *vct)
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

bool		is_clean(size_t i, char *tmp_av0, char *av, t_cmd *cmd)
{
	size_t		id_equal;
	t_vector	*vct_av;
	static size_t	i_ass = 0;
	static size_t	i_exp = 0;

	vct_av = vct_new();
	vct_addstr(vct_av, av);
	if (cmd->count_assign != 0 && i_ass < cmd->count_assign && 
			i == cmd->tab_assign[i_ass])
	{
		i_ass++;
		id_equal = vct_clen(vct_av, ASSIGN);
		if (id_equal != vct_getlen(vct_av))
		{
			if ((verif_assign(vct_av, id_equal) == false
					&& i != 0 && is_clean_command(tmp_av0) == false) ||
					(i == 0 && is_only_quote(av) == false) ||
					(is_only_quote(av) == true))
			{
				vct_del(&vct_av);
				return (false);
			}
		}
	}
	if (cmd->count_exp != 0 && i_exp < cmd->count_exp && 
			i == cmd->tab_exp[i_exp])
	{
		i_exp++;
		vct_pop(vct_av);
		if (vct_getlen(vct_av) == 0)
			return (false);
		if (is_wrong_ass(vct_av) == false)
			return (false);
	}
	vct_del(&vct_av);
	return (true);
}

enum e_cmd	export_or_command(t_vector *vct, size_t i, ssize_t id_equal,
							 size_t ac)
{
	if (ft_strequ(vct_getstr(vct), STR_EXPORT) == TRUE)
		return (i == ac - 1 ? E_EXPORT_EXEC : E_EXPORT_NO_EXEC);
	else if (id_equal == FAILURE && ft_strequ(vct_getstr(vct),
													  STR_EXPORT) == FALSE)
		return (E_COMMAND);
	return (E_ANY);
}

size_t		verif_assign(t_vector *vct_av, size_t id_equal)
{
	t_vector *vct;

	vct = vct_new();
	vct_cpy(vct, vct_av);
	vct_cutfrom(vct, vct_getlen(vct) - id_equal);
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
