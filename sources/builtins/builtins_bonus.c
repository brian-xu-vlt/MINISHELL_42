#include "minishell_bonus.h"

// return int mais pas sur, peut etre juste utiliser le errno.

int	pwd_builtin(int ac, char **av, char **envp)
{
	char	*pwd;
	char	*buff;
	t_vector	*option;

	errno = SUCCESS;
	pwd = NULL;
	(void)envp;
	if (ac != 1 && ft_strlen(av[1]) != 1)
	{
		if (ft_strlen(av[1]) > 1 && av[1][0] == '-')
		{
			option = vct_new();
			vct_add(option, av[1][0]);
			vct_add(option, av[1][1]);
			ft_printf("PRINT_SET_ERRNO\n");//DEBUG
			print_set_errno(0,"invalid option","pwd", vct_getstr(option));
			ft_putstr_fd("pwd: usage: pwd [-LP]\n", STDERR_FILENO);
			ft_printf("###########################################\n\n");//DEBUG
			vct_del(&option);
			return (PWD_FAIL);
		}
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
	ft_printf("MINE PWD\n");//DEBUG
	ft_printf("%s\n", pwd);
	ft_printf("##########################\n\n");//DEBUG
	free(buff);
	return (PWD_SUCCESS);
}
