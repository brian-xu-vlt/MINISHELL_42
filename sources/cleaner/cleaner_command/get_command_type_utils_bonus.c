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

static bool	is_clean_assign(t_vector *vct_av, size_t i, char *tmp_av0,
								char *av)
{
	size_t		id_equal;

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
	return (true);
}

bool		is_clean(size_t i, char *tmp_av0, char *av, t_cmd *cmd)
{
	t_vector	*vct_av;
	static size_t	i_ass = 0;
	static size_t	i_exp = 0;

	vct_av = vct_new();
	vct_addstr(vct_av, av);
	if (cmd->count_assign != 0 && i_ass < (size_t)cmd->count_assign && 
			i == cmd->tab_assign[i_ass])
	{
		i_ass++;
		if (is_clean_assign(vct_av, i, tmp_av0, av) == false)
			return (false);
	}
	if (cmd->count_exp != 0 && i_exp < (size_t)cmd->count_exp && 
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
