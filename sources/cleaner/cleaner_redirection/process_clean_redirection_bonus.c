#include "minishell_bonus.h"

static void process_clean(size_t size, char **dest, char **src)
{
	size_t	fake_av;
	size_t	real_av;

	fake_av = 0;
	real_av = 0;
	
	while (fake_av < size)
	{
		if (src[fake_av] != NULL)
		{
			dest[real_av] = ft_strdup(src[fake_av]);
			free(src[fake_av]);
			real_av++;	
		}	
		fake_av++;
	}
}

static int	clean_av(t_cmd *cmd, t_clean_cmd *clean_cmd, size_t nb_av)
{
	size_t	real_av;
	
	process_clean((size_t)cmd->ac, clean_cmd->tmp_av, cmd->av);
	free(cmd->av);
	cmd->av = (char **)malloc(sizeof(char *) * nb_av);
	if (cmd->av == NULL)
		return (FAILURE);//ERROR
	real_av = 0;
	cmd->ac = nb_av;
	while (real_av < nb_av)
	{
		cmd->av[real_av] = ft_strdup(clean_cmd->tmp_av[real_av]);
		free(clean_cmd->tmp_av[real_av]);
		real_av++;
	}
	return (SUCCESS);
}

static void	clean_redir(t_cmd *cmd, t_clean_cmd *clean_cmd, size_t nb_redir)
{
	process_clean((size_t)clean_cmd->ac, clean_cmd->tab_redir,
					clean_cmd->tmp_tab_redir);
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
	if (init_av_redir(cmd, clean_cmd, nb_av, nb_redir) == FAILURE)
		return (FAILURE);
	clean_av(cmd, clean_cmd, nb_av);
	clean_redir(cmd, clean_cmd, nb_redir);
	return (SUCCESS);
}