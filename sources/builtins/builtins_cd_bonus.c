#include "minishell_bonus.h"

static int check_cd_arg(int ac)
{
	if (ac > 2)
	{
		print_set_errno(0, "too many arguments", STR_CD, NULL);
		return (CD_FAIL);
	}
	return (CD_CONTINUE);
}

static int check_directory(char *directory)
{
	size_t i;
	size_t count_dot;

	i = 2;
	count_dot = 2;
	if (ft_strlen(directory) > 2 && directory[0] == DOT && directory[1] == DOT)
	{
		while (directory[i] != '\0')
		{
			if (count_dot == 2 && directory[i] == DOT)
				return (FAILURE);
			if (count_dot == 2 && directory[i] != DOT)
				count_dot = 0;
			if (directory[i] == DOT)
				count_dot++;
			i++;
		}
	}
	return (SUCCESS);
}

static int first_check(char *directory)
{
	DIR *dir;
	int ret_directory;

	dir = opendir(directory);
	ret_directory = check_directory(directory);
	if (dir == NULL && errno == PERMISSION_DENIED && ret_directory == SUCCESS)
		return (CD_CONTINUE);
	if (dir == NULL)
	{
		if (ret_directory == FAILURE && errno == PERMISSION_DENIED)
			print_set_errno(2, strerror(2), STR_CD, directory);
		else
			print_set_errno(errno, strerror(errno), STR_CD, directory);
		return (CD_FAIL);
	}
	if (closedir(dir) == FAILURE)
	{
		print_set_errno(errno, strerror(errno), "closedir", NULL);
		return (FAILURE);
	}
	return (CD_CONTINUE);
}

static int handle_pwd(int flag)
{
	char *pwd;
	char *buff;

	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
		return (FAILURE);
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
	{
		print_set_errno(errno, "bash: getcwd", NULL, NULL);
		free(buff);
		return (PWD_FAIL);
	}
	if (flag == PWD)
		ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_EXPORT | F_OVERWRITE);
	else if (flag == OLD_PWD)
		ms_setenv(get_env_list(GET), ENV_OLD_PWD, pwd, F_EXPORT | F_OVERWRITE);
	free(buff);
	return (SUCCESS);
}

static int find_last_root(char *pwd)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (pwd[i] != '\0')
	{
		if (pwd[i] == C_ROOT)
			count = i;
		i++;
	}
	return (count);
}

static int find_last_root_dot(char *pwd)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (pwd[i] != '\0')
	{
		if (ft_strnequ(DOTDOT, pwd + i, 2) == TRUE)
			count++;
		i++;
	}
	return (count);
}

static void cut_root(t_vector *new_dir, size_t count_root)
{
	size_t i;

	i = 0;
	while (i < count_root)
	{
		vct_cutfrom(new_dir, 3);
		i++;
	}
	if (vct_getcharat(new_dir, vct_getlen(new_dir) - 1) == C_ROOT)
		vct_cut(new_dir);
}

static void cut_dir(t_vector *new_dir, size_t count_root)
{
	size_t i;
	size_t last_root;

	i = 0;
	while (i < count_root)
	{
		last_root = find_last_root(vct_getstr(new_dir));
		vct_cutfrom(new_dir, vct_getlen(new_dir) - last_root);
		i++;
	}
}

static void transform_new_dir(t_vector *new_dir, char *pwd, char *dir_denied)
{
	size_t count_root;
	t_vector *vct_denied;
	t_vector *real_vct_denied;

	vct_denied = vct_new();
	real_vct_denied = vct_new();
	vct_addstr(vct_denied, dir_denied);
	while (vct_getlen(vct_denied) > 0)
	{
		while (vct_getfirstchar(vct_denied) == C_ROOT &&
			   vct_getcharat(vct_denied, 1) == C_ROOT)
			vct_pop(vct_denied);
		vct_add(real_vct_denied, vct_getfirstchar(vct_denied));
		vct_pop(vct_denied);
	}
	vct_addstr(new_dir, pwd);
	vct_add(new_dir, C_ROOT);
	vct_addstr(new_dir, vct_getstr(real_vct_denied));
	vct_del(&real_vct_denied);
	vct_del(&vct_denied);
	count_root = find_last_root_dot(vct_getstr(new_dir));
	cut_root(new_dir, count_root);
	cut_dir(new_dir, count_root);
}

static int handle_permission_denied(char **dir, char *dir_denied)
{
	char *pwd;
	char *buff;
	t_vector *new_dir;

	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
		return (FAILURE);
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
	{
		print_set_errno(errno, "bash: getcwd", NULL, NULL);
		free(buff);
		return (PWD_FAIL);
	}
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

static int process_chdir(t_vector *vct_home, char *dir)
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
		print_set_errno(errno, strerror(errno), STR_CD, real_dir);
	free(real_dir);
	if (ret_chdir == SUCCESS)
		ret_chdir = handle_pwd(PWD);
	return (ret_chdir);
}

static int	hub_process_chdir(char *dir, t_vector *vct_home)
{
	t_vector	*dir_old_pwd;
	char		*str_old_pwd;
	int ret_chdir;
	int	ret_pwd;

	str_old_pwd = NULL;
	if (ft_strequ(dir, STR_MINUS) == TRUE)
	{
		dir_old_pwd = get_env_value_vct(get_env_list(GET), "OLDPWD");
		str_old_pwd = vct_getstr(dir_old_pwd);
		ft_printf("%s\n", str_old_pwd);
		ret_chdir = process_chdir(vct_home, str_old_pwd);
		return (ret_chdir == FAILURE ? CD_FAIL : SUCCESS);
	}
	ret_pwd = handle_pwd(OLD_PWD);
	if (ret_pwd != SUCCESS)
		return (ret_pwd);
	ret_chdir = process_chdir(vct_home, dir);
	return (ret_chdir);
}

static int process_cd(char *dir)
{
	t_vector *vct_home;
	t_vector *vct_old_pwd;

	vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
	vct_old_pwd = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
	if (vct_home == NULL && dir == NULL)
	{
		print_set_errno(0, "HOME not set", STR_CD, NULL);
		return (CD_FAIL);
	}
	if (vct_old_pwd == NULL && ft_strequ(dir, STR_MINUS) == TRUE)
	{
		handle_pwd(OLD_PWD);
		return (SUCCESS);
	}
	if (dir == NULL && vct_getlen(vct_home) == 0)
	{
		print_set_errno(0, "HOME has no value", STR_CD, NULL);
		return (CD_FAIL);
	}
	return (hub_process_chdir(dir, vct_home) == FAILURE ? CD_FAIL : SUCCESS);
}

int cd_builtin(int ac, char **av, char **envp)
{
	int ret_check;

	(void)envp;
	if (check_cd_arg(ac) == CD_FAIL)
		return (CD_FAIL);
	if (ac != 1 && ft_strlen(av[1]) != 0 && ft_strequ(av[1], STR_MINUS) == FALSE)
	{
		ret_check = first_check(av[1]);
		if (ret_check != CD_CONTINUE)
			return (ret_check == CD_FAIL ? CD_FAIL : FAILURE);
	}
	if (ac != 1 && ft_strlen(av[1]) == 0)
		return (SUCCESS);
	return (process_cd(av[1]));
}
