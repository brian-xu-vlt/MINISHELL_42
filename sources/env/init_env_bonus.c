#include "minishell_bonus.h"

static void	set_default_env(t_list *env_lst)
{
	if (vct_getstr(get_env_value_vct(env_lst, "PATH")) == NOT_FOUND)
		ms_putenv(env_lst, DEFAULT_PATH_ENV);
}

/*
static void	increment_shlevel(void)
{
	t_vector	*shlvl;
	char		*new_lvl;
	int			shlvl_int;

	shlvl = get_env_value_vct("SHLVL");
	if (shlvl != NULL)
	{
		shlvl_int = ft_atoi(vct_getstr(shlvl));
		shlvl_int++;
		new_lvl = ft_itoa(shlvl_int);
		vct_clear(shlvl);
		vct_addstr(shlvl, new_lvl);
		free(new_lvl);
	}
	else
		export_env("SHLVL=1");
}
*/

extern char **environ;      // move to minishell header !!

void		init_env(void)
{
	t_list		*env_lst;
	int			index;

	if (environ == NULL)
		exit_routine_le(ERR_ENV);
	env_lst = (t_list *)ft_calloc(1, sizeof(t_list));
	if (env_lst == NULL)
		exit_routine_le(ERR_MALLOC);
	get_env_list(env_lst);
	index = 0;
	while (environ[index] != NULL)
	{
		if (ft_isalpha(environ[index][0]) == TRUE)
			export_env(env_lst, environ[index]);
		index++;
	}
	//increment_shlevel();
	set_default_env(env_lst);
}
