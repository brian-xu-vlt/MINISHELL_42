#include "minishell_bonus.h"

int			process_error(t_vector *vct_home, char *dir, t_vector *vct_old_pwd)
{
	if (vct_home == NULL && dir == NULL)
	{
		print_set_errno(0, HOME_SET, STR_CD, NULL);
		return (CD_FAIL);
	}
	if (ft_strequ(STR_MINUS, dir) == TRUE && vct_getstr(vct_old_pwd) == NULL)
	{
		print_set_errno(0, OLDPWD_SET, STR_CD, NULL);
		return (CD_FAIL);
	}
	if (vct_getlen(vct_old_pwd) == 0 && ft_strequ(dir, STR_MINUS) == TRUE)
	{
		print_set_errno(0, OLDPWD_VALUE, STR_CD, NULL);
		return (CD_FAIL);
	}
	if (dir == NULL && vct_getlen(vct_home) == 0)
	{
		print_set_errno(0, HOME_VALUE, STR_CD, NULL);
		return (CD_FAIL);
	}
	return (SUCCESS);
}

int			check_cd_arg(int ac)
{
	if (ac > 2)
	{
		print_set_errno(0, ERR_ARG, STR_CD, NULL);
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

static int	error_message(char *directory, int flag, int ret_directory)
{
	if (flag == INVALID_OPTION)
	{
		print_set_errno(0, ERR_OPT, STR_CD, directory);
		ft_putendl_fd(ERR_USAGE, STDERR_FILENO);
	}
	if (flag == DIR_NULL)
	{
		if (ret_directory == FAILURE && errno == PERMISSION_DENIED)
			print_set_errno(2, strerror(2), STR_CD, directory);
		else
			print_set_errno(errno, strerror(errno), STR_CD, directory);
	}
	return (CD_FAIL);
}

int			first_check(char *directory)
{
	DIR *dir;
	int ret_directory;

	if (ft_strlen(directory) > 1 && directory[0] == C_MINUS)
		return (error_message(directory, INVALID_OPTION, ret_directory));
	dir = opendir(directory);
	ret_directory = check_directory(directory);
	if (dir == NULL && errno == PERMISSION_DENIED && ret_directory == SUCCESS)
		return (CD_CONTINUE);
	if (dir == NULL)
		return (error_message(directory, DIR_NULL, ret_directory));
	if (closedir(dir) == FAILURE)
	{
		print_set_errno(errno, strerror(errno), ERR_CLOSE, NULL);
		exit(FAILURE);
	}
	return (CD_CONTINUE);
}

