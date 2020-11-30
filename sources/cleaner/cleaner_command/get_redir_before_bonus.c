#include "minishell_bonus.h"

void	how_increment(t_cmd *cmd, size_t *i)
{
	while (*i < (size_t)cmd->ac)
	{
		if (ft_strequ(LESS_THAN, cmd->av[*i]) == TRUE ||
			ft_strequ(GREATER_THAN, cmd->av[*i]) == TRUE ||
			ft_strequ(DOUBLE_GREATER, cmd->av[*i]) == TRUE)
		{
			if ((size_t)cmd->count_exp != 0 && cmd->i_exp !=
					(size_t)cmd->count_exp && *i == cmd->tab_exp[cmd->i_exp])
				return ;
			if ((size_t)cmd->count_assign != 0 && cmd->i_assign !=
					(size_t)cmd->count_assign &&
				*i + 1 == cmd->tab_assign[cmd->i_assign])
				cmd->i_assign++;
			else if ((size_t)cmd->count_exp != 0 && cmd->i_exp !=
					(size_t)cmd->count_exp &&
						*i + 1 == cmd->tab_exp[cmd->i_exp])
				cmd->i_exp++;
			*i = *i + 2;
		}
		else
			return ;
	}
}

int		set_redir_before(t_cmd *cmd, size_t i)
{
	size_t start;

	start = 0;
	cmd->tab_redir_before = (char **)malloc(sizeof(char *) * (i + 1));
	if (cmd->tab_redir_before == NULL)
		exit_routine(EXIT_MALLOC);
	while (start < i)
	{
		cmd->tab_redir_before[start] = ft_strdup(cmd->av[start]);
		free(cmd->av[start]);
		cmd->av[start] = NULL;
		start++;
	}
	cmd->tab_redir_before[start] = NULL;
	cmd->count_redir_before = i;
	if (cmd->count_redir_before == (size_t)cmd->ac)
	{
		ft_free_tab(cmd->ac, cmd->av);
		free(cmd->av);
		cmd->av = NULL;
		return (ONLY_REDIR_BEFORE);
	}
	return (SUCCESS);
}

void	increment(int ret, t_cmd *cmd)
{
	if (ret == TRUE_ASSIGN)
		cmd->i_assign++;
	else if (ret == TRUE_EXP)
		cmd->i_exp++;
}

bool	check_av(t_cmd *cmd, size_t *i)
{
	if (cmd->av[*i] == NULL)
	{
		*i = *i + 1;
		return (true);
	}
	if (ft_strlen(cmd->av[*i]) == 0 && *i + 1 != (size_t)cmd->ac)
	{
		*i = *i + 1;
		return (true);
	}
	return (false);
}

bool	is_redir_before(t_cmd *cmd, size_t i)
{
	return (i == 0 && (ft_strequ(LESS_THAN, cmd->av[i]) == TRUE ||
				ft_strequ(GREATER_THAN, cmd->av[i]) == TRUE ||
				ft_strequ(DOUBLE_GREATER, cmd->av[i]) == TRUE) ?
				true : false);
}
