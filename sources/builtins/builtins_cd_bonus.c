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
	if (dir == NULL)
	{
		print_set_errno(errno, strerror(errno), "cd", directory);
		return (CD_FAIL);
	}
	if (closedir(dir) == FAILURE)
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

static int process_cd(char *dir)
{
	t_vector *vct_home;
	int			ret_chdir;
	char		*real_dir;

	vct_home = get_env_value_vct(get_env_list(GET), "HOME");
	if (dir == NULL && vct_getlen(vct_home) == 0)
		return (SUCCESS);
	real_dir = ft_strdup(dir == NULL && vct_getlen(vct_home) != 0 ?
				vct_getstr(vct_home) : dir);
	ret_chdir = chdir(real_dir);
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
