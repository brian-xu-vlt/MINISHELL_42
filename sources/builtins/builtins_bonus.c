#include "minishell_bonus.h"

// return int mais pas sur, peut etre juste utiliser le errno.

int	pwd_builtin(void)
{
	char	*pwd;
	char	*buff;

	errno = SUCCESS;
	pwd = NULL;
	buff = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (buff == NULL)
		return (FAILURE);
	pwd = getcwd(buff, PATH_MAX);
	if (pwd == NULL)
	{
		print_set_errno(errno, "bash: getcwd", NULL);
		free(buff);
		return (PWD_FAIL);
	}
	ft_printf("%s\n", pwd);
	free(buff);
	return (PWD_SUCCESS);
}
