#include "minishell_bonus.h"

static int	pwd_error_option(char *str)
{
	t_vector *option;

	option = vct_new();
	vct_add(option, str[0]);
	vct_add(option, str[1]);
	print_set_errno(0, ERR_PWD_OPT, STR_PWD, vct_getstr(option));
	ft_putstr_fd(ERR_PWD_US, STDERR_FILENO);
	vct_del(&option);
	return (SUCCESS);
}

static int	first_check_pwd(int ac, char *av)
{
	if (ac != 1 && ft_strlen(av) >= 1 && av[0] == '-')
	{
		pwd_error_option(av);
		return (PWD_FAIL);
	}
	return (SUCCESS);
}

int			pwd_builtin(int ac, char **av, char **envp)
{
	char *pwd;
	char *buff;

	errno = SUCCESS;
	pwd = NULL;
	(void)envp;
	if (first_check_pwd(ac, av[1]) == PWD_FAIL)
		return (PWD_FAIL);
	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
	{
		free(buff);
		exit_routine_le(ERR_MALLOC);
	}
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
	{
		ft_putendl_fd(ERR_GET_PWD, STDERR_FILENO);
		free(buff);
		return (PWD_FAIL);
	}
	ft_printf("%s\n", pwd);
	free(buff);
	return (PWD_SUCCESS);
}
