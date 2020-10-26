#include "minishell_bonus.h"

bool is_wrong_ass(t_vector *vct)
{
	if (ft_isdigit(vct_getfirstchar(vct)) == TRUE)
		return (false);
	if (is_wrong_char(vct) == true)
		return (false);
	return (true);
}

bool process_wrong_ass(t_cmd *cmd, t_vector *vct, size_t i_ass)
{
	size_t id_equal;

	vct_addstr(vct, cmd->av[cmd->tab_assign[i_ass]]);
	id_equal = vct_clen(vct, ASSIGN);
	vct_cutfrom(vct, vct_getlen(vct) - id_equal);
	if (is_wrong_ass(vct) == false)
		return (false);
	return (true);
}