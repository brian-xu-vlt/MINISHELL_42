#include "minishell_bonus.h"

int	process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	ft_printf("PROCESS_REDIRECTION\n");//DEBUG
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}