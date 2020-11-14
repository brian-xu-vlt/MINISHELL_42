#include "minishell_bonus.h"

static int check_cd_arg(int ac)
{
	if (ac > 2)
	{
		print_set_errno(0, "too many arguments", "cd", NULL);
		return (CD_FAIL);
	}
	return (CD_CONTINUE);
}

static int first_check(char *directory)
{
	DIR *dir;
	
	dir = opendir(directory);
	if (dir == NULL && ft_strnequ(directory, "..", 2) == FALSE && errno != 13)
	{
		print_set_errno(errno, strerror(errno), "cd", directory);
		return (CD_FAIL);
	}
	if (ft_strequ(directory, "..") == FALSE && errno != 13 &&
			closedir(dir) == FAILURE)
	{
		print_set_errno(errno, strerror(errno), "closedir", NULL);
		return (FAILURE);
	}
	return (CD_CONTINUE);
}

static int	handle_pwd(void)
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
	ms_setenv(get_env_list(GET), "PWD", pwd, F_EXPORT | F_OVERWRITE);
	free(buff);
	return (SUCCESS);
}

static int	find_last_root(char *pwd)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (pwd[i] != '\0')
	{
		if (pwd[i] == '/')
			count = i;
		i++;
	}
	return (count);
}

static int	find_last_root_dot(char *pwd)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (pwd[i] != '\0')
	{
		if (ft_strnequ("..", pwd + i, 2) == TRUE)
			count++;
		i++;
	}
	return (count);
}

static void	cut_root(t_vector *new_dir, size_t count_root)
{
	size_t	i;

	i = 0;
	while (i < count_root)
	{
		vct_cutfrom(new_dir, 3);
		i++;
	}
	if (vct_getcharat(new_dir, vct_getlen(new_dir) - 1) == '/')
		vct_cut(new_dir);
}

static void	cut_dir(t_vector *new_dir, size_t count_root)
{
	size_t	i;
	size_t	last_root;

	i = 0;
	while (i < count_root)
	{
		last_root = find_last_root(vct_getstr(new_dir));
		vct_cutfrom(new_dir, vct_getlen(new_dir) - last_root);
		i++;
	}
}

static int handle_permission_denied(char **dir, char *dir_denied)
{
	char *pwd;
	char *buff;
	size_t	count_root;
	t_vector	*new_dir;

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
	vct_addstr(new_dir, pwd);
	vct_add(new_dir, '/');
	vct_addstr(new_dir, dir_denied);
	count_root = find_last_root_dot(vct_getstr(new_dir));
	cut_root(new_dir, count_root);
	cut_dir(new_dir, count_root);
	if (vct_getlen(new_dir) == 0)
		*dir = ft_strdup("/");
	else
		*dir = ft_strdup(vct_getstr(new_dir));
	vct_del(&new_dir);
	free(buff);
	return (SUCCESS);
}

static int process_cd(char *dir)
{
	t_vector *vct_home;
	int			ret_chdir;
	char		*real_dir;
	char		*dir_denied;

	vct_home = get_env_value_vct(get_env_list(GET), "HOME");
	if (vct_home == NULL)
	{
		print_set_errno(0, "HOME not set", "cd", NULL);
		return (CD_FAIL);
	}
	if (dir == NULL && vct_getlen(vct_home) == 0)
	{
		print_set_errno(0, "HOME has no value", "cd", NULL);
		return (CD_FAIL);
	}
	real_dir = ft_strdup(dir == NULL && vct_getlen(vct_home) != 0 ?
				vct_getstr(vct_home) : dir);
	ret_chdir = chdir(real_dir);
	if (ret_chdir == FAILURE && ft_strnequ(real_dir, "..", 2) == TRUE)
	{
		dir_denied = ft_strdup(real_dir);
		free(real_dir);
		handle_permission_denied(&real_dir, dir_denied);
		free(dir_denied);
		ret_chdir = chdir(real_dir);
	}
	if (ret_chdir == FAILURE)
		print_set_errno(errno, strerror(errno), "cd", real_dir);
	free(real_dir);
	if (ret_chdir == SUCCESS)
		ret_chdir = handle_pwd();
	return (ret_chdir == FAILURE ? CD_FAIL : SUCCESS);
}

int cd_builtin(int ac, char **av, char **envp)
{
	int ret_check;

	(void)envp;
	if (check_cd_arg(ac) == CD_FAIL)
		return (CD_FAIL);
	if (ac != 1 && ft_strlen(av[1]) != 0)
	{
		ret_check = first_check(av[1]);
		if (ret_check != CD_CONTINUE)
			return (ret_check == CD_FAIL ? CD_FAIL : FAILURE);
	}
	if (ac != 1 && ft_strlen(av[1]) == 0)
		return (SUCCESS);
	return (process_cd(av[1]));
}
