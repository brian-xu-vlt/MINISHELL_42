#include "minishell_bonus.h"

bool is_bad_ass(t_cmd *cmd)
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

enum e_cmd process_get_cmd_type(t_vector *vct, size_t i, size_t ac)
{
	size_t id_equal;
	size_t is_assign;
	enum e_cmd is_export_or_assign;

	id_equal = vct_clen(vct, ASSIGN);
	if (id_equal != vct_getlen(vct))
	{
		is_assign = verif_assign(vct, id_equal);
		if (is_assign == false)
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
		cmd_type = process_get_cmd_type(vct_av, i, cmd->ac);
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
