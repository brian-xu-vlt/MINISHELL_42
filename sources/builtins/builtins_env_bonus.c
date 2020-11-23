#include "minishell_bonus.h"

void print_invalid_identifier(const char *function_name,
							  const char *error_source)
{
	static const char *error_str = "not a valid identifier";
	t_vector *tmp_err_src;
	tmp_err_src = vct_new();
	if (tmp_err_src == NULL)
		exit_routine_le(ERR_MALLOC);
	vct_add(tmp_err_src, '`');
	vct_addstr(tmp_err_src, (char *)error_source);
	vct_add(tmp_err_src, '\'');
	print_set_errno(EINVAL, error_str, function_name, vct_getstr(tmp_err_src));
	vct_del(&tmp_err_src);
}

static bool	process_valid_identifier(t_vector *vct, char *av_to_check)
{
	char	c_first;

	while (vct_getlen(vct) > 0)
	{
		c_first = vct_getfirstchar(vct);
		if (ft_isalnum(c_first) == false && c_first != C_EXP &&
				c_first != LOW_LINE)
		{
			print_invalid_identifier(STR_UNSET, av_to_check);
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
	t_vector *vct;
	char c_first;
	char c_last;

	vct = vct_new();
	vct_addstr(vct, av_to_check);
	c_first = vct_getfirstchar(vct);
	c_last = vct_getcharat(vct, vct_getlen(vct) - 1);
	if (c_last == C_EXP || ft_isdigit(c_first) == true)
	{
		print_invalid_identifier(STR_UNSET, av_to_check);
		vct_del(&vct);
		return (false);
	}
	return (process_valid_identifier(vct, av_to_check));
}

static void print_envp(char **envp)
{
	int i;

	i = 0;
	while (envp != NULL && envp[i] != NULL)
		ft_printf("%s\n", envp[i++]);
}

int env_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "env";
	const char	*usage = "Try 'env --help' for more information.\n";

	print_envp(envp);
	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		print_env(get_env_list(GET));
	else
	{
		print_invalid_option(builtin, av[1], usage);
		return (BUILTIN_ENV_FAILURE);
	}
	return (SUCCESS);
}
