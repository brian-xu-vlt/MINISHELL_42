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
	const char *builtin = "env";

	print_envp(envp);
	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		print_env(get_env_list(GET));
	else
	{
		print_set_errno(EINVAL, NULL, builtin, av[1]);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void export_loop(int ac, char **av, const char *builtin)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (verif_assign_cmd(av[i]) == false)
			export_env(get_env_list(GET), av[i]);
		else
			print_set_errno(EINVAL, NULL, builtin, av[i]);
		i++;
	}
}

static void export_envp(char **envp)
{
	int i;

	i = 0;
	if (envp == NULL)
		return;
	while (envp != NULL && envp[i] != NULL)
		export_env(get_env_list(GET), envp[i++]);
}

int export_builtin(int ac, char **av, char **envp)
{
	const char *builtin = "export";

	errno = 0;
	if (ft_strequ(av[0], (char *)builtin) == TRUE && ac > 1)
	{
		if (av[1][0] == '-')
		{
			print_set_errno(0, ERR_INVALID_OPTION, builtin, av[1]);
			ft_printf("export: usage: export [name[=value] ...]\n");
			return (2);
		}
		else
			export_loop(ac, av, builtin);
		//if (errno == EINVAL)
		//return (1);
	}
	if (ft_strequ(av[0], (char *)builtin) == TRUE && ac == 1)
		print_export_output(get_env_list(GET));
	export_envp(envp);
	return (SUCCESS);
}

int unset_builtin(int ac, char **av, char **envp)
{
	const char *builtin = "unset";
	int i;

	(void)envp;
	if (ac == 1 || ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	else
	{
		i = 1;
		while (i < ac)
		{
			if (is_valid_identifier(av[i]) == FALSE)
			{
				i++;
				continue;
			}
			else if (ft_isalpha(*av[i]) == TRUE)
				unset_env(get_env_list(GET), av[i]);
			i++;
		}
	}
	return (SUCCESS);
}
