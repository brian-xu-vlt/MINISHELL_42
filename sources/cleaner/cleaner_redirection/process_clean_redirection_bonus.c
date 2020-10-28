#include "minishell_bonus.h"

static int	clean_av(t_cmd *cmd, t_clean_cmd *clean_cmd, size_t nb_av)
{
	size_t	fake_av;
	size_t	real_av;

	fake_av = 0;
	real_av = 0;
	while (fake_av < cmd->ac)
	{
		if (cmd->av[fake_av] != NULL)
		{
			clean_cmd->tmp_av[real_av] = ft_strdup(cmd->av[fake_av]);
			real_av++;	
		}	
		fake_av++;
	}
	free(cmd->av);
	cmd->av = (char **)malloc(sizeof(char *) * nb_av);
	if (cmd->av == NULL)
		return (FAILURE);//ERROR
	real_av = 0;
	cmd->ac = nb_av;
	while (real_av < nb_av)
	{
		cmd->av[real_av] = ft_strdup(clean_cmd->tmp_av[real_av]);
		real_av++;
	}
	return (SUCCESS);
}

static void	clean_redir(t_cmd *cmd, t_clean_cmd *clean_cmd, size_t nb_redir)
{
	size_t	fake_av;
	size_t	real_av;

	fake_av = 0;
	real_av = 0;
	while (fake_av < clean_cmd->ac)
	{
		if (clean_cmd->tmp_tab_redir[fake_av] != NULL)
		{
			clean_cmd->tab_redir[real_av] =
						ft_strdup(clean_cmd->tmp_tab_redir[fake_av]);
			real_av++;	
		}	
		fake_av++;
	}
	clean_cmd->count_redir = nb_redir;
	ft_printf("\033[0;32mDEBUG REDIR FINAL\n\033[0m");//DEBUG
	debug_redir(clean_cmd->tab_redir, clean_cmd->count_redir);
}

int	clean_redir_av(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	nb_av;
	size_t	nb_redir;

	nb_av = count_av(cmd);
	nb_redir = count_redir(cmd, clean_cmd);
	ft_printf("nb_av = %d\n", nb_av);//DEBUG
	ft_printf("nb_redir = %d\n", nb_redir);//DEBUG
	if (init_av_redir(cmd, clean_cmd, nb_av, nb_redir) == FAILURE)
		return (FAILURE);
	clean_av(cmd, clean_cmd, nb_av);
	clean_redir(cmd, clean_cmd, nb_redir);
	return (SUCCESS);
}