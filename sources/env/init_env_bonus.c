#include "minishell_bonus.h"

static void	handle_only_pwd(void)
{
	char *pwd;

	pwd = getcwd(NULL, PATH_MAX);
	ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_OVERWRITE | F_EXPORT);
	free(pwd);
}

static void	set_default_env(t_list *env_lst)
{
	handle_only_pwd();
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

static int	is_special_environ(char *environ)
{
	char		*env_name;
	char		*env_value;
	int			overwrite;
	int			ret;

	if (ft_strnstr(environ, "+=", ft_strlen(environ)) != NOT_FOUND)
		return (true);
	parse_env(environ, &env_name, &env_value, &overwrite);
	ret = is_valid_export_identifier(env_name);
	free(env_name);
	if (env_value != NULL)
		free(env_value);
	if (ret == false)
		return (true);
	else if (ft_isalpha(*environ) == false)
		return (true);
	return (false);
}

static t_list *init_env_list(void)
{
	t_list		*env_lst;

	env_lst = ft_lstnew(NULL);
	if (env_lst == NULL)
		exit_routine(ERR_MALLOC);
	get_env_list(env_lst);
	return (env_lst);
}

void		init_env(void)
{
	t_list		*env_lst;
	int			index;
	extern char **environ;

	if (environ == NULL)
		exit_routine_le(ERR_ENV);
	env_lst = init_env_list;
	index = 0;
	while (environ[index] != NULL)
	{
		if (is_special_environ(environ[index]) == true)
			ms_setenv(env_lst, environ[index], NULL, F_SPECIAL);
		else
			export_env(env_lst, environ[index]);
		index++;
	}
	set_default_env(env_lst);
	increment_shlevel(env_lst);
}
