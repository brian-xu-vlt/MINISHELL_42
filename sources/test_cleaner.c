#include "minishell_bonus.h"

void	debug_cleaner(t_cmd *cmd)
{
	debug_av(cmd->av, cmd->ac);
	ft_printf("\n");//DEBUG
}
