#include "minishell_bonus.h"

static void	set_default_env(t_list *env_lst)
{
	handle_pwd(PWD);
	export_env(env_lst, "OLDPWD");
	ms_putenv(env_lst, DEFAULT_EXIT_STATUS);
	if (vct_getstr(get_env_value_vct(env_lst, "PATH")) == NOT_FOUND)
		ms_putenv(env_lst, DEFAULT_PATH_ENV);
	if (vct_getstr(get_env_value_vct(env_lst, "TERM")) == NOT_FOUND)
		ms_putenv(env_lst, DEFAULT_TERM);
}

static void	increment_shlevel(t_list *env_lst)
{
	int			shlvl_int;

	shlvl_int = get_env_value_int(env_lst, "SHLVL");
	if (errno == FAILURE)
		export_env(env_lst, "SHLVL=1");
	else
		ms_setenv_int(env_lst, "SHLVL", shlvl_int + 1, F_OVERWRITE | F_EXPORT);
}

void		init_env(void)
{
	t_list		*env_lst;
	int			index;
	extern char **environ;

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
	set_default_env(env_lst);
	increment_shlevel(env_lst);
}
