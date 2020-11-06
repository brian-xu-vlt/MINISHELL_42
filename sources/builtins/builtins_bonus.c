#include "minishell_bonus.h"

// return int mais pas sur, peut etre juste utiliser le errno.

int	pwd_builtin(int ac, char **av, char **envp)
{
	char	*pwd;
	char	*buff;

	errno = SUCCESS;
	pwd = NULL;
	if (ac != 1)
	{
		ft_printf("av[1] = %s\n", av[1]);//DEBUG
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
	free(buff);
	return (PWD_SUCCESS);
}
