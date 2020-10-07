#include "minishell_bonus.h"

char	*fill_name(char *str)
{
	static t_vector *name;
	t_vector	*tmp_name;

	tmp_name = NULL;
	if (str == NULL)
	{	
		tmp_name = vct_new();
		vct_addstr(tmp_name, vct_getstr(name));
		vct_cut(tmp_name);
		name = NULL;
		return (vct_getstr(tmp_name));
	}
	if (name == NULL)
		name = vct_new();
	vct_addstr(name, str);
	vct_add(name, C_SPACE);
	return (NULL);
}
