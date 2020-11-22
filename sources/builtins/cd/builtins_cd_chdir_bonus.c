#include "minishell_bonus.h"

int handle_permission_not(char *dir, char *pwd, char *old_dir)
{
	t_vector *vct_pwd;
	t_vector *vct_old;
	t_vector *vct_home;
	t_vector *tmp;
	char *old;

	tmp = vct_new();
	get_value(vct_pwd, vct_old, vct_home);
	if (ft_strlen(dir) != 0 && dir[0] != DOT && dir[0] != C_PATH)
	{
		if (ft_strequ(old_dir, STR_MINUS) == FALSE)
			print_set_errno(0, ERR_PERMISSION, STR_CD, dir);
		else
			print_set_errno(0, ERR_NOT_DIR, STR_CD, dir);
		ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
		free(pwd);
		vct_del(&tmp);
		return (3);
	}
	set_env(vct_pwd, vct_old);
	vct_del(&tmp);
	return (SUCCESS);
}

static void handle_chdir_failure(char *dir, char *old_dir, char *real_dir)
{
	if (errno == 13)
	{
		ft_putstr_fd(CD_BUILT, STDERR_FILENO);
		ft_putstr_fd(dir, STDERR_FILENO);
		if (ft_strequ(old_dir, STR_MINUS) == TRUE)
		{
			ft_putendl_fd(ERR_PERMISSION_SPACE, STDERR_FILENO);
			swap_pwd(PWD_OLDPWD, dir);
		}
		else
			ft_putendl_fd(ERR_NOT_DIR_SPACE, STDERR_FILENO);
	}
	else
		print_set_errno(errno, strerror(errno), STR_CD, real_dir);
}

int			handle_permission_denied(char **dir, char *dir_denied)
{
	char		*pwd;
	char		*buff;
	t_vector	*new_dir;

	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
		exit_routine_le(ERR_MALLOC);
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
		exit_routine_le(ERR_MALLOC);
	new_dir = vct_new();
	transform_new_dir(new_dir, pwd, dir_denied);
	if (vct_getlen(new_dir) == 0)
		*dir = ft_strdup(STR_ROOT);
	else
		*dir = ft_strdup(vct_getstr(new_dir));
	vct_del(&new_dir);
	free(buff);
	return (SUCCESS);
}

int process_chdir(t_vector *vct_home, char *dir, char *old_dir,
						 char *dir_old_pwd)
{
	char *real_dir;
	char *dir_denied;
	int ret_chdir;

	real_dir = ft_strdup(dir == NULL && vct_getlen(vct_home) != 0 ?
					vct_getstr(vct_home) : dir);
	ret_chdir = chdir(real_dir);
	if (ret_chdir == FAILURE && ft_strnequ(real_dir, DOTDOT, 2) == TRUE)
	{
		dir_denied = ft_strdup(real_dir);
		free(real_dir);
		handle_permission_denied(&real_dir, dir_denied);
		free(dir_denied);
		ret_chdir = chdir(real_dir);
	}
	if (ret_chdir == FAILURE)
		handle_chdir_failure(dir, old_dir, real_dir);
	if (old_dir != NULL && ret_chdir != FAILURE &&
		ft_strequ(old_dir, STR_MINUS) == TRUE)
		ft_printf("%s\n", dir_old_pwd);
	free(real_dir);
	if (ret_chdir == SUCCESS)
		ret_chdir = handle_pwd(PWD, dir, NULL);
	return (ret_chdir);
}
