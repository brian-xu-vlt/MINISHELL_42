#include "minishell_bonus.h"

static int	pwd_error_option(char *str)
{
	t_vector *option;

	option = vct_new();
	vct_add(option, str[0]);
	vct_add(option, str[1]);
	print_set_errno(0, "invalid option", "pwd", vct_getstr(option));
	ft_putstr_fd("pwd: usage: pwd [-LP]\n", STDERR_FILENO);
	vct_del(&option);
	return (SUCCESS);
}

int			pwd_builtin(int ac, char **av, char **envp)
{
	char *pwd;
	char *buff;


	errno = SUCCESS;
	pwd = NULL;
	(void)envp;
	if (ac != 1 && ft_strlen(av[1]) >= 1 && av[1][0] == '-')
	{
		pwd_error_option(av[1]);
		return (PWD_FAIL);
	}
	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
	{
		print_set_errno(errno, ERR_MALLOC, NULL, NULL);
		free(buff);
		exit(FAILURE);
	}
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
	{
		ft_putendl_fd("pwd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory", STDERR_FILENO);
		free(buff);
		return (PWD_FAIL);
	}
	ft_printf("%s\n", pwd);
	free(buff);
	return (PWD_SUCCESS);
}
