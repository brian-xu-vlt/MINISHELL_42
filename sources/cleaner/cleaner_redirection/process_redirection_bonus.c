#include "minishell_bonus.h"

static enum e_state_redir	in_out(char *str)
{
	if (ft_strequ(str, LESS_THAN) == TRUE ||
			ft_strequ(str, GREATER_THAN) == TRUE || 
			ft_strequ(str, DOUBLE_GREATER) == TRUE)
		return (E_IN_REDIR);
	return (E_IN_OUT);
}

static enum e_state_redir	in_file(char *str)
{
	if (ft_strequ(str, LESS_THAN) == TRUE ||
			ft_strequ(str, GREATER_THAN) == TRUE || 
			ft_strequ(str, DOUBLE_GREATER) == TRUE)
		return (E_IN_REDIR);
	return (E_IN_OUT);
}

static enum e_state_redir	in_redir(char *str)
{
	return (E_IN_FILE);
}

static int	create_tab_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	t_state_redir		function_state[] = {in_redir, in_file, in_out};
	enum e_state_redir	state;
	size_t				i;

	state = E_IN_OUT;
	i = 0;
	clean_cmd->tmp_tab_redir = (char **)malloc(sizeof(char *) * cmd->ac);
	if (clean_cmd->tmp_tab_redir == NULL)
		return (FAILURE);//ERROR
	while (i < cmd->ac)
	{
		clean_cmd->tmp_tab_redir[i] = NULL;
		ft_printf("state = %d\n", state);//DEBUG

		state = function_state[state](cmd->av[i]);
		if (state == E_IN_REDIR || state == E_IN_FILE)
		{
			clean_cmd->tmp_tab_redir[i] = ft_strdup(cmd->av[i]);
			cmd->av[i] = NULL;
		}
		ft_printf("str = %s\n\n", cmd->av[i]);//DEBUGi
		i++;
	}
	ft_printf("\033[0;32mDEBUG REDIR BEFORE\n\033[0m");//DEBUG
	ft_printf("CMD->AC = %d\n", cmd->ac);//DEBUG
	debug_redir(clean_cmd->tmp_tab_redir, cmd->ac);
	return (SUCCESS);
}

static int	count_av(t_cmd *cmd)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < cmd->ac)
	{
		if (cmd->av[i] != NULL)
			count++;
		i++;
	}
	return (count);
}

static int	count_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < cmd->ac)
	{
		if (clean_cmd->tmp_tab_redir[i] != NULL)
			count++;
		i++;
	}
	return (count);
}

static int	init_av_redir(t_cmd *cmd, t_clean_cmd *clean_cmd, size_t nb_av,
							size_t nb_redir)
{
	clean_cmd->tab_redir = (char **)malloc(sizeof(char *) * nb_redir);
	if (clean_cmd->tab_redir == NULL)
		return (FAILURE);//ERROR
	clean_cmd->tmp_av = (char **)malloc(sizeof(char *) * nb_av);
	if (clean_cmd->tmp_av == NULL)
		return (FAILURE);//ERROR
	return (SUCCESS);
}

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

static int	clean_redir_av(t_cmd *cmd, t_clean_cmd *clean_cmd)
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

int	process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	ft_printf("PROCESS_REDIRECTION\n");//DEBUG
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);

}