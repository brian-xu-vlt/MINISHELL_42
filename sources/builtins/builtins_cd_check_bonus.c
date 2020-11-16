#include "minishell_bonus.h"

int			check_cd_arg(int ac)
{
	if (ac > 2)
	{
		ft_printf("CD  FAIL\n");//DEBUG
		print_set_errno(0, "too many arguments", STR_CD, NULL);
		return (CD_FAIL);
	}
	return (CD_CONTINUE);
}

static int	check_directory(char *directory)
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

int			first_check(char *directory)
{
	DIR *dir;
	int ret_directory;

	ft_printf("OPEN DIR\n");//DEBUG
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

int			handle_permission_denied(char **dir, char *dir_denied)
{
	char		*pwd;
	char		*buff;
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
	transform_new_dir(new_dir, pwd, dir_denied);
	if (vct_getlen(new_dir) == 0)
		*dir = ft_strdup(STR_ROOT);
	else
		*dir = ft_strdup(vct_getstr(new_dir));
	vct_del(&new_dir);
	free(buff);
	return (SUCCESS);
}
