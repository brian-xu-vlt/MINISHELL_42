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

static int	handle_cd_only(void)
{
	t_vector *vct_home;

	ft_printf("HANDLE_CD_ONLY\n");//DEBUG
	vct_home = get_env_value_vct(get_env_list(GET), "HOME");
	ft_printf("vct_home = %s\n", vct_getstr(vct_home));//DEBUG
	
}

static int process_cd(char *dir)
{
	ft_printf("dir = %s\n", dir);
	if (dir == NULL)
		handle_cd_only();
}

int cd_builtin(int ac, char **av, char **envp)
{
	int ret_check;

	ft_printf("CD BUILTIN\n"); //DEBUG
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
	process_cd(av[1]);
	return (SUCCESS);
}
