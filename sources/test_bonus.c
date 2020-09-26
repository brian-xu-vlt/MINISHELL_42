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

void	print_envp(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_putstr_fd(envp[i++], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}

void	free_envp(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
		free(envp[i++]);
	free(envp);
}

int	test(t_vector *input)
{
	char	**envp;

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
	if (ft_strncmp(vct_getstr(input), "envp", 5) == 0)
	{
		envp = get_envp();
		print_envp(envp);
		free_envp(envp);
		envp = NULL;
	}
	return (SUCCESS);
}

