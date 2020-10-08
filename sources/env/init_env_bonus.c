#include "minishell_bonus.h"

static void	set_default_env(void)
{
	if (vct_getstr(get_env_value_vct("PATH")) == NOT_FOUND)
		ms_putenv(DEFAULT_PATH_ENV);	
}

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

extern char **environ;

void		init_env(void)
{
	t_env_data	*env_data;
	int			index;

	env_data = (t_env_data *)ft_calloc(1, sizeof(t_env_data));
	get_env_data(env_data);
	if (environ == NULL)
		return ;
	index = 0;
	while (environ[index] != NULL)
	{
		if (ft_isalpha(environ[index][0]) == TRUE)
			export_env(environ[index]);
		index++;
	}
	increment_shlevel();
	set_default_env();
}

/*

invalid names:
- contain '-'
- first char is numeric

env: show exported var WITH VALUE
export: show exported var with AND without value + sorted alphabeticly


- export test="42" valid, so need to stripoff quotes

toto=42'0'
toto='0'
toto'0'


*/
