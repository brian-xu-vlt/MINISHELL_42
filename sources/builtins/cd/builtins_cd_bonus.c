#include "minishell_bonus.h"

static int	hub_process_chdir(char *dir, t_vector *vct_home)
{
	int			ret_chdir;
	int			ret_pwd;
	char		*old_dir;
	t_vector	*vct_home;

	old_dir = NULL;
	if (dir != NULL)
		old_dir = ft_strdup(dir);
	if (ft_strequ(dir, STR_MINUS) == TRUE)
		return (handle_old_pwd(old_dir));
	ret_pwd = handle_pwd(OLD_PWD, dir, old_dir);
	if (ret_pwd != SUCCESS)
	{
		free(old_dir);
		return (ret_pwd == 3 ? TRUE : ret_pwd);
	}
	ret_chdir = process_chdir(vct_home, dir, NULL, NULL);
	free(old_dir);
	return (ret_chdir);
}

static int	process_cd(char *dir)
{
	t_vector	*vct_home;
	t_vector	*vct_old_pwd;
	int			ret_process_chdir;

	vct_home = get_env_value_vct(get_env_list(GET), ENV_HOME);
	vct_old_pwd = get_env_value_vct(get_env_list(GET), ENV_OLD_PWD);
	if (process_error(vct_home, dir, vct_old_pwd) == CD_FAIL)
		return (CD_FAIL);
	ret_process_chdir = hub_process_chdir(dir, vct_home);
	if (ret_process_chdir == FAILURE)
		ret_process_chdir = CD_FAIL;
	return (ret_process_chdir);
}

int			cd_builtin(int ac, char **av, char **envp)
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
			return (ret_check == CD_FAIL ? TRUE : FAILURE);
	}
	if (ac != 1 && ft_strlen(av[1]) == 0)
		return (SUCCESS);
	ret_cd = process_cd(av[1]);
	if (ret_cd == 2 && (ac > 1 && ft_strlen(av[1]) != 0 && av[1][0] != C_PATH))
	{
		ret_cd = TRUE;
		print_set_errno(0, ERR_NO_FILE, STR_CD, av[1]);
	}
	return (ret_cd);
}
