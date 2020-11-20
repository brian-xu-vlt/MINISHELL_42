#include "minishell_bonus.h"

static int	is_valid_identifier(const char *av_to_check, const char *builtin)
{
	t_vector			*tmp_av;
	int					ret;


if (av_to_check != NULL && av_to_check[0] == '-')
{
	print_invalid_identifier(builtin, av_to_check);
	return (FALSE);
}
return (TRUE);
////////////////////////unused

	if (av_to_check == NULL)
		return (FALSE);
	tmp_av = vct_new();
	if (tmp_av == NULL)
		exit_routine_le(ERR_MALLOC);
	vct_addstr(tmp_av, (char *)av_to_check);
	ret = is_wrong_ass(tmp_av);
	vct_del(&tmp_av);
	if (ret == TRUE)
	{
		print_invalid_identifier(builtin, av_to_check);
		return (FALSE);
	}
	else
		return (TRUE);
}

int			unset_builtin(int ac, char **av, char **envp)
{
	static const char	*builtin = "unset";
	static const char	*usage = "unset: usage: unset [name ...]\n";
	int					i;
	int					ret;

	ret = BUILTIN_SUCCESS;
	errno = 0;
	export_envp(envp);
	if (ac == 1 || ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	else
	{
		i = 1;
		while (av[i] != NULL)
		{
			if (i < 2 && av[i][0] == '-')
			{
				print_invalid_option(builtin, av[i], usage);
				return (BUILTIN_INVALID_IDENTIFIER);
			}
			if (is_valid_identifier(av[i], builtin) == TRUE)
				unset_env(get_env_list(GET), av[i]);
			else
				ret = BUILTIN_FAILURE;
			i++;
		}
	}
	return (ret);
}
