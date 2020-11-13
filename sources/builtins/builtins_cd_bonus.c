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

static int process_cd(char *dir, t_vector *new_dir, int flag)
{
	t_vector *vct_pwd;

	vct_pwd = get_env_value_vct(get_env_list(GET), "PWD");
	ft_printf("flag = %d\n", flag);//DEBUG
	ft_printf("vct_pwd = %s\n", vct_getstr(vct_pwd));//DEBUG
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
int cd_builtin(int ac, char **av, char **envp)
{
	int ret_closedir;
	t_vector *new_av1;
	int ret_check;

	ft_printf("CD BUILTIN\n"); //DEBUG
	(void)envp;
	if (check_cd_arg(ac) == CD_FAIL)
		return (CD_FAIL);
	if (ac == 1)
	{
		new_av1 = vct_new();
		vct_addstr(new_av1, "\\");
	}
	else
		new_av1 = NULL;
	if (new_av1 == NULL)
	{
		ret_check = first_check(av[1]);
		if (ret_check != CD_CONTINUE)
			return (ret_check == CD_FAIL ? CD_FAIL : FAILURE);
	}
	process_cd(av[1], new_av1, ret_check);
	vct_del(&new_av1);
	return (SUCCESS);
}
