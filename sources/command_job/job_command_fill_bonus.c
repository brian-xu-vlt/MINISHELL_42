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
		vct_del(&name);
		return (vct_getstr(tmp_name));
	}
	if (name == NULL)
		name = vct_new();
	vct_addstr(name, str);
	vct_add(name, C_SPACE);
	return (NULL);
}

char	**fill_av(t_cmd *cmd)
{
	cmd->av = ft_split(cmd->name, C_SPACE);
	return (cmd->av);
}

int	fill_ac(char **av)
{
	int	ac;

	ac = 0;
	while (av[ac] != NULL)
		ac++;
	return (ac);
}
