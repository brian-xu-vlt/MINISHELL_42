#include "minishell_bonus.h"

static bool	process_bad_ass_any(t_cmd *cmd)
{

}

static bool	process_bad_ass_export(t_cmd *cmd)
{
	size_t	i;
	t_vector 	*vct_av;

	i = 0;
	vct_av = vct_new();
	while (i < (size_t)cmd->count_assign)
	{
		vct_addstr(vct_av, cmd->av[cmd->tab_exp[i]]);
		if (ft_isdigit(vct_getfirstchar(vct_av) == TRUE))
		{
			ft_printf("PROCESS_BAD_ASS_EXPORT FIRST DIGIT\n");
			vct_del(&vct_av);
			return (false);
		}
		if (is_wrong_char_export(vct_av) == true)
		{
			ft_printf("PROCESS_BAD_ASS_EXPORT WRONG CHAR EXPORT\n");
			vct_del(&vct_av);
			return (false);
		}
		vct_clear(vct_av);
		i++;
	}
	vct_del(&vct_av);
	return (true);
}

bool	is_bad_ass(t_cmd *cmd, enum e_cmd cmd_type)
{
	if (cmd_type == E_EXPORT_EXEC || cmd_type == E_EXPORT_NO_EXEC)
	{
		process_bad_ass_export(cmd);
	}
	if (cmd_type == E_ANY)
	{
		process_bad_ass_any(cmd);
	}
	return (true);
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
	size_t 		i;
	t_vector 	*vct_av;
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
