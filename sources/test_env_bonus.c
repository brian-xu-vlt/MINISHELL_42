#include "minishell_bonus.h"

static void	debug_export(t_vector *input)
{
	char 	**av;
	int		ac;

	av = ft_split(vct_getstr(input), ' ');
	ac = 0;
	while (av[ac] != NULL)
		ac++;
	export_builtin(ac, av);
	ac = 0;
	while (av[ac] != NULL)
		free(av[ac++]);
	free(av);
}

static void	debug_print_env(t_vector *input)
{
	char	*str;

	str = vct_getstr(input);
	str += ft_strlen("print") + 1;
	ft_putstr_fd(vct_getstr(get_env_value_vct(str)), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

static void	debug_store_env(t_vector *input)
{
	char	*str;

	str = vct_getstr(input);
	str += ft_strlen("store") + 1;
	ms_putenv(str);
}

static void	debug_unset(t_vector *input)
{
	char 	**av;
	int		ac;

	av = ft_split(vct_getstr(input), ' ');
	ac = 0;
	while (av[ac] != NULL)
		ac++;
	unset_builtin(ac, av);
	ac = 0;
	while (av[ac] != NULL)
		free(av[ac++]);
	free(av);
}

static void	debug_env(t_vector *input)
{
	char 	**av;
	int		ac;

	av = ft_split(vct_getstr(input), ' ');
	ac = 0;
	while (av[ac] != NULL)
		ac++;
	env_builtin(ac, av);
	ac = 0;
	while (av[ac] != NULL)
		free(av[ac++]);
	free(av);
}

int	test_env(t_vector *input)
{
	//REMOVE REMOVE REMOVE
	dprintf(STDERR_FILENO, "\n%s\n", vct_getstr(input)); //do a printf wrapper OR debug function  //REMOVE REMOVE REMOVE
	
	if (ft_strncmp(vct_getstr(input), "store", 5) == 0)
		debug_store_env(input);
	else if (ft_strncmp(vct_getstr(input), "print", 5) == 0)
		debug_print_env(input);
	else if (ft_strncmp(vct_getstr(input), "export", 6) == 0)
		debug_export(input);
	else if (ft_strncmp(vct_getstr(input), "env", 3) == 0)
		debug_env(input);
	else if (ft_strncmp(vct_getstr(input), "unset", 5) == 0)
		debug_unset(input);
	return (SUCCESS);
}


/*	implement internal variables :
 *	_ : last av[] of the last command
 *
 *	parsing:
 *	echo $456 -> $(4 = null) 56 | de 0 a 9
 *	$# -> 0 for minishell, but not null !
 *	
 *	PWD / OLDPWD: update when calling `cd`
 *
 * 	$? -> demande dans le sujet ! 
 *
 * 	$$ -> pid, pas implementable sans fonction interdite ?...
 *
 */
