#include "minishell_bonus.h"

void	debug_fd_string(char **fd_sting)
{
	size_t	i;

	i = 0;
	while (i < NB_FD)
	{
		ft_printf("fd_string[%d] = %s\n", i, fd_sting[i]);//DEBUG
		i++;
	}
}

void	debug_fd(int *fd)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		ft_printf("fd[%d] = %d\n", i, fd[i]);
		i++;
	}
}

void debug_redir(char **redir, int ac)
{
	int i;

	i = 0;
	ft_printf("AC = %d\n", ac);//DEBUGA
	while (i < ac)
	{
		ft_printf("redir[%d] = %s\n", i, redir[i]);
		i++;
	}
}

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
