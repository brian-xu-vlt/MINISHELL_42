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

	vct_av = vct_new();
	vct_addstr(vct_av, av);
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
	vct_del(&vct_av);
	return (true);
}

enum e_cmd export_or_command(t_vector *vct, size_t i, size_t id_equal,
							 size_t ac)
{
	if (ft_strequ(vct_getstr(vct), STR_EXPORT) == TRUE)
		return (i == ac - 1 ? E_EXPORT_EXEC : E_EXPORT_NO_EXEC);
	else if (id_equal == vct_getlen(vct) && ft_strequ(vct_getstr(vct),
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
		ft_printf("IS_DIGIT == FALSE\n");//DEBUG
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
