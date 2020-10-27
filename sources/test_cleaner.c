#include "minishell_bonus.h"

static void debug_env(char **envp, int ac)
{
	int i;

	i = 0;
	while (i < ac)
	{
		ft_printf("envp[%d] = %s\n", i, envp[i]);
		i++;
	}
}

void	debug_cleaner(t_cmd *cmd)
{
	ft_printf("\n");//DEBUG
	ft_printf("\033[0;32mDEBUG AV FINAL\n\033[0m");//DEBUG
	debug_av(cmd->av, cmd->ac);
	ft_printf("\n");//DEBUG
	ft_printf("\033[0;32mDEBUG ENV FINAL\n\033[0m");//DEBUG
	debug_env(cmd->envp, cmd->count_assign);
	ft_printf("\n");//DEBUG
}
