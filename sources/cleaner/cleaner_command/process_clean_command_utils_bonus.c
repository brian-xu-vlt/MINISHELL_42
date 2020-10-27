#include "minishell_bonus.h"

void	count_ac_assign(t_cmd *cmd, t_clean_cmd *clean_cmd, bool is_bad)
{
	size_t	i;
	size_t	i_assign;

	i = 0;
	i_assign = 0;
	ft_printf("IS_BAD = %d\n", is_bad);
	while (i < cmd->ac)
	{
		if (cmd->count_assign != 0 && ft_strequ(cmd->av[i], STR_EXPORT) == FALSE
			&& i == cmd->tab_assign[i_assign])
		{
			clean_cmd->count_assign++;
			i_assign++;
		}
		else if (ft_strequ(cmd->av[i], STR_EXPORT) == TRUE)
			return ;
		i++;
	}
}