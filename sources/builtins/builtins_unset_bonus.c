#include "minishell_bonus.h"

static bool process_valid_identifier(t_vector *vct, char *av_to_check)
{
    char    			c_first;

    while (vct != NULL && vct_getlen(vct) > 0)
    {
        c_first = vct_getfirstchar(vct);
        if (ft_isalnum(c_first) == false && c_first != C_EXP &&
                c_first != LOW_LINE)
        {
            print_invalid_identifier("unset", av_to_check);
            vct_del(&vct);
            return (false);
        }
        vct_pop(vct);
    }
    vct_del(&vct);
    return (true);
}

static bool is_valid_identifier(char *av_to_check)
{
    t_vector			*vct;
    char 				c_first;
    char 				c_last;

    vct = vct_new();
    if (vct == NULL)
        exit_routine(EXIT_MALLOC);
    if (vct_addstr(vct, av_to_check) == FAILURE)
        exit_routine(EXIT_MALLOC);
    c_first = vct_getfirstchar(vct);
    c_last = vct_getcharat(vct, vct_getlen(vct) - 1);
    if (c_last == C_EXP || ft_isdigit(c_first) == true)
    {
        print_invalid_identifier("unset", av_to_check);
        vct_del(&vct);
        return (false);
    }
    return (process_valid_identifier(vct, av_to_check));
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
			if (is_valid_identifier(av[i]) == TRUE)
				unset_env(get_env_list(GET), av[i]);
			else
				ret = BUILTIN_FAILURE;
			i++;
		}
	}
	return (ret);
}
