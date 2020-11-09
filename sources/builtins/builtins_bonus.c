#include "minishell_bonus.h"

// return int mais pas sur, peut etre juste utiliser le errno.

static int pwd_error_option(char *str)
{
	t_vector *option;
	
	option = vct_new();
	vct_add(option, str[0]);
	vct_add(option, str[1]);
	print_set_errno(0, "invalid option", "pwd", vct_getstr(option));
	if (ft_putstr_fd("pwd: usage: pwd [-LP]\n", STDERR_FILENO) == FAILURE)
		return (FAILURE);
	ft_printf("###########################################\n\n"); //DEBUG
	vct_del(&option);
	return (SUCCESS);
}

int pwd_builtin(int ac, char **av, char **envp)
{
	char *pwd;
	char *buff;

	errno = SUCCESS;
	pwd = NULL;
	(void)envp;
	if (ac != 1 && ft_strlen(av[1]) >= 1 && av[1][0] == '-')
	{
		if (pwd_error_option(av[1]) == FAILURE)
			return (FAILURE);
		return (PWD_FAIL);
	}
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
	ft_printf("%s\n", pwd);
	ft_printf("##########################\n\n"); //DEBUG
	free(buff);
	return (PWD_SUCCESS);
}
