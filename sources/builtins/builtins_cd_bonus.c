#include "minishell_bonus.h"

static void get_value(t_vector *vct_pwd, t_vector *vct_old, t_vector *vct_home)
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

static int handle_permission_not(char *dir, char *pwd, char *old_dir)
{
	t_vector *vct_pwd;
	t_vector *vct_old;
	t_vector *vct_home;
	t_vector *tmp;
	char *old;

	tmp = vct_new();
	get_value(vct_pwd, vct_old, vct_home);
	if (ft_strlen(dir) != 0 && dir[0] != '.' && dir[0] != '/')
	{
		if (ft_strequ(old_dir, STR_MINUS) == FALSE)
			print_set_errno(0, "Permission denied", "cd", dir);
		else
			print_set_errno(0, "Not a directory", "cd", dir);
		ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
		free(pwd);
		vct_del(&tmp);
		return (3);
	}
	set_env(vct_pwd, vct_old);
	vct_del(&tmp);
	return (SUCCESS);
}

static void swap_pwd(int flag, char *dir)
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

static void handle_normal(int flag, char *pwd, char *buff)
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

static int handle_pwd_error(char *buff, char *dir)
{
	free(buff);
	if (dir == NULL || (ft_strlen(dir) != 0 && dir[0] == '/'))
	{
		swap_pwd(dir == NULL ? PWD_HOME : PWD_DIR, dir);
		return (SUCCESS);
	}
	if (errno == 2)
		return (2);
	return (FAILURE);
}

static int handle_pwd(int flag, char *dir, char *old_dir)
{
	char *pwd;
	char *old;
	char *buff;
	int ret;

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

static void handle_chdir_failure(char *dir, char *old_dir, char *real_dir)
{
	if (errno == 13)
	{
		ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(dir, STDERR_FILENO);
		if (ft_strequ(old_dir, STR_MINUS) == TRUE)
		{
			ft_putendl_fd(": Permission denied", STDERR_FILENO);
			swap_pwd(PWD_OLDPWD, dir);
		}
		else
			ft_putendl_fd(": Not a directory", STDERR_FILENO);
	}
	else
		print_set_errno(errno, strerror(errno), STR_CD, real_dir);
}

static int process_chdir(t_vector *vct_home, char *dir, char *old_dir,
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

static int handle_old_pwd(char *old_dir)
{
	t_vector *tmp;
	t_vector *pwd;
	t_vector *dir_old_pwd;
	t_vector *vct_home;
	int ret_chdir;

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

static int hub_process_chdir(char *dir, t_vector *vct_home)
{
	int ret_chdir;
	int ret_pwd;
	char *old_dir;
	t_vector *vct_home;

	old_dir = NULL;
	if (dir != NULL)
		old_dir = ft_strdup(dir);
	if (ft_strequ(dir, STR_MINUS) == TRUE)
		return (handle_old_pwd(old_dir));
	ret_pwd = handle_pwd(OLD_PWD, dir, old_dir);
	if (ret_pwd != SUCCESS)
	{
		free(old_dir);
		return (ret_pwd == 3 ? 1 : ret_pwd);
	}
	ret_chdir = process_chdir(vct_home, dir, NULL, NULL);
	free(old_dir);
	return (ret_chdir);
}

static int process_cd(char *dir)
{
	t_vector *vct_home;
	t_vector *vct_old_pwd;
	int ret_process_chdir;

	vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
	vct_old_pwd = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
	if (process_error(vct_home, dir, vct_old_pwd) == CD_FAIL)
		return (CD_FAIL);
	ret_process_chdir = hub_process_chdir(dir, vct_home);
	if (ret_process_chdir == FAILURE)
		ret_process_chdir = CD_FAIL;
	return (ret_process_chdir);
}

int cd_builtin(int ac, char **av, char **envp)
{
	int ret_check;
	int ret_cd;

	(void)envp;
	if (check_cd_arg(ac) == CD_FAIL)
		return (CD_FAIL);
	if (ac != 1 && ft_strlen(av[1]) != 0 &&
		ft_strequ(av[1], STR_MINUS) == FALSE)
	{
		ret_check = first_check(av[1]);
		if (ret_check != CD_CONTINUE)
			return (ret_check == CD_FAIL ? 1 : FAILURE);
	}
	if (ac != 1 && ft_strlen(av[1]) == 0)
		return (SUCCESS);
	ret_cd = process_cd(av[1]);
	if (ret_cd == 2 && (ac > 1 && ft_strlen(av[1]) != 0 && av[1][0] != '/'))
	{
		ret_cd = 1;
		print_set_errno(0, "No such file or directory", "cd", av[1]);
	}
	return (ret_cd);
}
