#include "minishell_bonus.h"

void get_value(t_vector *vct_pwd, t_vector *vct_old, t_vector *vct_home)
{
	vct_pwd = get_env_value_vct(get_env_list(GET), ENV_PWD);
	vct_old = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
	vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
}

static void set_env(t_vector *vct_pwd, t_vector *vct_old)
{
	char *pwd;
	char *old;

	pwd = ft_strdup(vct_getstr(vct_pwd));
	old = ft_strdup(vct_getstr(vct_old));
	ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
	ms_setenv(get_env_list(GET), ENV_OLD_PWD, old, F_EXPORT | F_OVERWRITE);
	free(pwd);
	free(old);
}

void swap_pwd(int flag, char *dir)
{
	t_vector *vct_pwd;
	t_vector *vct_old;
	t_vector *vct_home;
	t_vector *tmp;

	tmp = vct_new();
	get_value(vct_pwd, vct_old, vct_home);
	if (flag == PWD_HOME || flag == PWD_OLDPWD)
	{
		vct_cpy(tmp, vct_pwd);
		vct_cpy(vct_pwd, (flag == PWD_HOME ? vct_home : vct_old));
		vct_cpy(vct_old, tmp);
	}
	else if (flag == PWD_DIR)
	{
		vct_cpy(tmp, vct_pwd);
		vct_clear(vct_pwd);
		vct_addstr(vct_pwd, dir);
		vct_cpy(vct_old, tmp);
	}
	set_env(vct_pwd, vct_old);
	if (flag == PWD_HOME || flag == PWD_DIR)
		set_env(vct_pwd, vct_old);
	vct_del(&tmp);
}
