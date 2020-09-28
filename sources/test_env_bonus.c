#include "minishell_bonus.h"

static void	debug_print_env(t_vector *input)
{
	char	*str;

	str = vct_getstr(input);
	str += ft_strlen("print") + 1;
	print_env(str);
}

static void	debug_export_env(t_vector *input)
{
	char	*str;

	str = vct_getstr(input);
	str += ft_strlen("export") + 1;
	if (*str == '\0')
		get_export_output();
	else
		export_env(str);
}

static void	debug_store_env(t_vector *input)
{
	char	*str;

	str = vct_getstr(input);
	str += ft_strlen("store") + 1;
	store_internal_var(str);
}

void	print_envp(void)
{
	char	**envp;
	int		i;

	i = 0;
	envp = get_env_data(GET)->envp;
	if (envp == NULL)
		exit_routine_le(ERR_ENVP);
	while (envp[i] != NULL)
	{
		ft_putstr_fd(envp[i++], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}

int	test_env(t_vector *input)
{
	ft_printf("\n%s\n", vct_getstr(input));
	if (ft_strncmp(vct_getstr(input), "1", 2) == 0)
		print_env(ALL);	
	if (ft_strncmp(vct_getstr(input), "2", 2) == 0)
		print_env("TERM");
	if (ft_strncmp(vct_getstr(input), "store", 5) == 0)
		debug_store_env(input);	
	if (ft_strncmp(vct_getstr(input), "export", 6) == 0)
		debug_export_env(input);	
	if (ft_strncmp(vct_getstr(input), "print", 5) == 0)
		debug_print_env(input);	
	if (ft_strncmp(vct_getstr(input), "env", 4) == 0)
		print_envp();
	if (ft_strncmp(vct_getstr(input), "./Minishell", 12) == 0)
	{
		return (SUCCESS);
	/*		envp = get_envp();
		char *argv[2];
		argv[0] = ft_strdup("./Minishell");
		argv[1] = NULL;
		execve("./Minishell", argv, envp);
		free(argv[0]);
		free(argv[1]);
		//free_envp(envp);
		envp = NULL;
*/	}
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
