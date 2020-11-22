#include "minishell_bonus.h"

static size_t	process_clean(size_t size, char **dest, char **src)
{
	size_t fake_av;
	size_t real_av;

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
	return (real_av);
}

static int		free_av(size_t ac, int i_dup, char **tmp_av)
{
	size_t	real_av;
	size_t	i;

	real_av = 0;
	i = 0;
	while (real_av < ac)
	{
		if (i == i_dup)
			break ;
		if (tmp_av[real_av] != NULL)
		{
			free(tmp_av[real_av]);
			i++;
		}
		real_av++;
	}
	return (FAILURE);
}

static int		clean_av(t_cmd *cmd, t_clean_cmd *clean_cmd, size_t nb_av)
{
	size_t real_av;
	size_t i_dup;
	size_t i;

	i = 0;
	real_av = 0;
	i_dup = process_clean((size_t)cmd->ac, clean_cmd->tmp_av, cmd->av);
	free(cmd->av);
	cmd->av = (char **)malloc(sizeof(char *) * (nb_av + 1));
	if (cmd->av == NULL)
		return (free_av(cmd->ac, i_dup, clean_cmd->tmp_av));
	cmd->av[nb_av] = NULL;
	cmd->ac = nb_av;
	while (real_av < nb_av)
	{
		cmd->av[real_av] = ft_strdup(clean_cmd->tmp_av[real_av]);
		free(clean_cmd->tmp_av[real_av]);
		real_av++;
	}
	return (SUCCESS);
}

static void		clean_redir(t_clean_cmd *clean_cmd, size_t nb_redir)
{
	process_clean((size_t)clean_cmd->ac, clean_cmd->tab_redir,
					clean_cmd->tmp_tab_redir);
	clean_cmd->count_redir = nb_redir;
}

int				clean_redir_av(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t nb_av;
	size_t nb_redir;

	nb_av = count_av(cmd);
	nb_redir = count_redir(cmd, clean_cmd);
	if (init_av_redir(clean_cmd, nb_av, nb_redir) == FAILURE)
		return (FAILURE);
	if (clean_av(cmd, clean_cmd, nb_av) == FAILURE)
		return (FAILURE);
	clean_redir(clean_cmd, nb_redir);
	return (SUCCESS);
}
