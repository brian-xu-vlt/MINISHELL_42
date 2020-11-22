#include "minishell_bonus.h"

static void	handle_normal(int flag, char *pwd, char *buff)
{
	t_vector *vct_pwd;
	t_vector *vct_old;
	t_vector *vct_home;
	t_vector *tmp;

	get_value(vct_pwd, vct_old, vct_home);
	if (flag == PWD)
		ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
	else if (flag == OLD_PWD && vct_old != NULL)
		ms_setenv(get_env_list(GET), ENV_OLD_PWD, pwd, F_EXPORT | F_OVERWRITE);
	else if (flag == OLD_PWD && vct_pwd != NULL)
		ms_setenv(get_env_list(GET), ENV_OLD_PWD, pwd, F_EXPORT | F_OVERWRITE);
	free(buff);
}

static int	handle_pwd_error(char *buff, char *dir)
{
	free(buff);
	if (dir == NULL || (ft_strlen(dir) != 0 && dir[0] == C_PATH))
	{
		swap_pwd(dir == NULL ? PWD_HOME : PWD_DIR, dir);
		return (SUCCESS);
	}
	if (errno == 2)
		return (2);
	return (FAILURE);
}

int			handle_pwd(int flag, char *dir, char *old_dir)
{
	char	*pwd;
	char	*old;
	char	*buff;
	int		ret;

	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
	{
		free(buff);
		exit_routine_le(ERR_MALLOC);
	}
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
		return (handle_pwd_error(buff, dir));
	if (errno == 13)
	{
		ret = handle_permission_not(dir, pwd, old_dir);
		if (ret == SUCCESS)
			free(buff);
		return (ret);
	}
	handle_normal(flag, pwd, buff);
	return (SUCCESS);
}

int			handle_old_pwd(char *old_dir)
{
	t_vector	*tmp;
	t_vector	*pwd;
	t_vector	*dir_old_pwd;
	t_vector	*vct_home;
	int			ret_chdir;

	tmp = vct_new();
	get_value(pwd, dir_old_pwd, vct_home);
	vct_cpy(tmp, pwd);
	vct_cpy(pwd, dir_old_pwd);
	vct_cpy(dir_old_pwd, tmp);
	vct_del(&tmp);
	ret_chdir = process_chdir(vct_home, vct_getstr(pwd), old_dir,
								vct_getstr(pwd));
	free(old_dir);
	return (ret_chdir == FAILURE ? CD_FAIL : SUCCESS);
}
