#include "minishell_bonus.h"

static int	handle_pwd(int flag, char *dir, char *old_dir)
{
	char *pwd;
	char *old;
	char *buff;
	t_vector	*vct_pwd;
	t_vector	*vct_old;
	t_vector	*vct_home;
	t_vector	*tmp;
	int			ret;

	ret = SUCCESS;
	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
	{
		free(buff);
		exit_routine_le(ERR_MALLOC);
	}
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
	{
		free(buff);
		if (dir == NULL)
		{
			tmp = vct_new();
			vct_pwd = get_env_value_vct(get_env_list(GET), ENV_PWD);
			vct_old = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
			vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
			vct_cpy(tmp, vct_pwd);
			vct_cpy(vct_pwd, vct_home);
			vct_cpy(vct_old, tmp);
			pwd = ft_strdup(vct_getstr(vct_pwd));
			old = ft_strdup(vct_getstr(vct_old));
			ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
			ms_setenv(get_env_list(GET), ENV_OLD_PWD, old, F_EXPORT | F_OVERWRITE);
			free(pwd);
			free(old);
			vct_del(&tmp);
			return (SUCCESS);
		}
		if (ft_strlen(dir) != 0 && dir[0] == '/')
		{
			tmp = vct_new();
			vct_pwd = get_env_value_vct(get_env_list(GET), ENV_PWD);
			vct_old = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
			vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
			vct_cpy(tmp, vct_pwd);
			vct_clear(vct_pwd);
			vct_addstr(vct_pwd, dir);
			vct_cpy(vct_old, tmp);
			pwd = ft_strdup(vct_getstr(vct_pwd));
			old = ft_strdup(vct_getstr(vct_old));
			ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
			ms_setenv(get_env_list(GET), ENV_OLD_PWD, old, F_EXPORT | F_OVERWRITE);
			free(pwd);
			free(old);
			vct_del(&tmp);
			return (SUCCESS);
		}
		if (errno == 2)
			return (2);
		return (FAILURE);
	}
	if (errno == 13)
	{
		tmp = vct_new();
		vct_pwd = get_env_value_vct(get_env_list(GET), ENV_PWD);
		vct_old = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
		vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
		if (ft_strlen(dir) != 0 && dir[0] != '.' && dir[0] != '/')
		{
			//ft_printf("dir = %s\n", dir);//DEBUG
		//	ft_printf("old_dir = %s\n", old_dir);//DEBUG
			//ft_printf("ICI ALORS ?\n");//DEBUG
			if (ft_strequ(old_dir, STR_MINUS) == FALSE)
				print_set_errno(0, "Permission denied", "cd", dir);
			else
				print_set_errno(0, "Not a directory", "cd", dir);
			ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
			free(pwd);
			vct_del(&tmp);
			return (3);
		}
		//ft_printf("errno == 13\n");//DEBUG
		//ft_printf("vct_pwd = %s\n", vct_getstr(vct_pwd));//DEBUG
		//ft_printf("vct_old = %s\n", vct_getstr(vct_old));//DEBUG
		//ft_printf("vct_home = %s\n", vct_getstr(vct_home));//DEBUG
		pwd = ft_strdup(vct_getstr(vct_pwd));
		old = ft_strdup(vct_getstr(vct_old));
		ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
		ms_setenv(get_env_list(GET), ENV_OLD_PWD, old, F_EXPORT | F_OVERWRITE);
		free(pwd);
		free(old);
		free(buff);
		vct_del(&tmp);
		return (SUCCESS);
	}
	vct_pwd = get_env_value_vct(get_env_list(GET), ENV_PWD);
	vct_old = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
	vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
	//ft_printf("vct_pwd = %s\n", vct_getstr(vct_pwd));//DEBUG
	//ft_printf("vct_old = %s\n", vct_getstr(vct_old));//DEBUG
	//ft_printf("vct_home = %s\n", vct_getstr(vct_home));//DEBUG
	if (flag == PWD)
		ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
	else if (flag == OLD_PWD && vct_old != NULL)
		ms_setenv(get_env_list(GET), ENV_OLD_PWD, pwd, F_EXPORT | F_OVERWRITE);
	else if (flag == OLD_PWD && vct_pwd != NULL)
		ms_setenv(get_env_list(GET), ENV_OLD_PWD, pwd, F_EXPORT | F_OVERWRITE);
	free(buff);
	return (SUCCESS);
}

static int	process_chdir(t_vector *vct_home, char *dir, char *old_dir, char *dir_old_pwd)
{
	char	*real_dir;
	char	*dir_denied;
	int		ret_chdir;
	t_vector	*vct_pwd;
	t_vector	*vct_old;
	t_vector	*vct_now_home;
	t_vector	*tmp;

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
	{
		//ft_printf("errno = %d\n", errno);//DEBUG
		if (errno == 13)
		{
			ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(dir, STDERR_FILENO);
			if (ft_strequ(old_dir, STR_MINUS) == TRUE)
			{
				ft_putendl_fd(": Permission denied", STDERR_FILENO);
				tmp = vct_new();
				vct_pwd = get_env_value_vct(get_env_list(GET), ENV_PWD);
				vct_old = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
				vct_now_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
				vct_cpy(tmp, vct_pwd);
				vct_cpy(vct_pwd, vct_old);
				vct_cpy(vct_old, tmp);
				vct_del(&tmp);
			//	ft_printf("vct_pwd = %s\n", vct_getstr(vct_pwd));//DEBUG
			//	ft_printf("vct_old = %s\n", vct_getstr(vct_old));//DEBUG
			//	ft_printf("vct_now_home = %s\n", vct_getstr(vct_now_home));//DEBUG
			}
			else
			{
			//	ft_printf("TU VAS LA?\n");//DEBUG
				ft_putendl_fd(": Not a directory", STDERR_FILENO);
			}
		}
		else
			print_set_errno(errno, strerror(errno), STR_CD, real_dir);
	}
	if (old_dir != NULL && ret_chdir != FAILURE &&
			ft_strequ(old_dir, STR_MINUS) == TRUE)
		ft_printf("%s\n", dir_old_pwd);
	free(real_dir);
	if (ret_chdir == SUCCESS)
	{
		//ft_printf("TU RENTRES PAR LA ?\n");//DEBUG
		ret_chdir = handle_pwd(PWD, dir, NULL);
	}
	return (ret_chdir);
}

static int	hub_process_chdir(char *dir, t_vector *vct_home)
{
	t_vector	*dir_old_pwd;
	char		*str_old_pwd;
	int			ret_chdir;
	int			ret_pwd;
	t_vector	*pwd;
	t_vector	*tmp;
	char		*str_pwd;
	char 		*old_dir;

	str_old_pwd = NULL;
	dir_old_pwd = NULL;
	old_dir = NULL;
	if (dir != NULL)
		old_dir = ft_strdup(dir);
	//ft_printf("old_dir FIRST = %s\n", old_dir);//DEBUG
	if (ft_strequ(dir, STR_MINUS) == TRUE)
	{
		tmp = vct_new();
		pwd = get_env_value_vct(get_env_list(GET), "PWD");
		dir_old_pwd = get_env_value_vct(get_env_list(GET), "OLDPWD");
		vct_cpy(tmp, pwd);
		//ft_printf("tmp = %s\n", vct_getstr(tmp));//DEBUG
		vct_cpy(pwd, dir_old_pwd);
		vct_cpy(dir_old_pwd, tmp);
		str_old_pwd = vct_getstr(dir_old_pwd);
		str_pwd = vct_getstr(pwd);
		//ft_printf("old_pwd = %s\n", str_old_pwd);//DEBUG
		//ft_printf("pwd = %s\n", str_pwd);//DEBUG
	//	ft_printf("PRINT CD -------------------\n");//DEBUG
		vct_del(&tmp);
		ret_chdir = process_chdir(vct_home, str_pwd, old_dir, str_pwd);
		free(old_dir);
		return (ret_chdir == FAILURE ? CD_FAIL : SUCCESS);
	}
	//ft_printf("TU RENTRES PAR ICI DU COUP ?\n");//DEBUG
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

static int	process_cd(char *dir)
{
	t_vector *vct_home;
	t_vector *vct_old_pwd;
	int			ret_process_chdir;

	vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
	vct_old_pwd = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
	//ft_printf("dir = %s\n", dir);//DEBUG
	//ft_printf("vct_home = %s\n", vct_getstr(vct_home));//DEBUG
	if (process_error(vct_home, dir, vct_old_pwd) == CD_FAIL)
		return (CD_FAIL);
	ret_process_chdir = hub_process_chdir(dir, vct_home);
	if (ret_process_chdir == FAILURE)
		ret_process_chdir = CD_FAIL;
	return (ret_process_chdir);
}

int			cd_builtin(int ac, char **av, char **envp)
{
	int			ret_check;
	int			ret_cd;

//	ft_printf("cd\n");//DEBUG
	(void)envp;
//	if (ac > 1)
//		ft_printf("av[1] = %s\n", av[1]);//DEBUG
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
