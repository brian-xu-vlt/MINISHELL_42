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

int	env_builtin(int ac, char **av)
{
	const char	*builtin = "env";

	if (ft_strncmp(av[0], builtin, ft_strlen(builtin) + 1) != 0)
		return (0);
	if (ac == 1)
		print_env();
	else
	{
		print_set_errno(EINVAL, (char *)builtin, av[1]);
		return (FAILURE);
	}	
	return (SUCCESS);
}

int	export_builtin(int ac, char **av)
{
	const char	*builtin = "export";
	int			i;

	if (ft_strncmp(av[0], builtin, ft_strlen(builtin) + 1) != 0)
		return (0);
	if (ac == 1)
		get_export_output();
	else
	{
		i = 1;
		while (i < ac)
		{
			if (ft_isalpha(av[i][0]) == TRUE)
				export_env(av[i]);
			else
				print_set_errno(EINVAL, (char *)builtin, av[i]);
			i++;
		}
	}
	return (SUCCESS);
}

int	unset_builtin(int ac, char **av)
{
	const char	*builtin = "unset";
	int			i;

	if (ac == 1 || ft_strncmp(av[0], builtin, ft_strlen(builtin) + 1) != 0)
		return (0);
	else
	{
		i = 0;
		while (i < ac)
		{
			if (av[i][0] == '-')
				print_set_errno(EINVAL, (char *)builtin, av[i]);
			else
				delete_env(av[i]);
			i++;
		}
	}
	return (SUCCESS);
}
