#include "minishell_bonus.h"

void	exit_routine(t_token *token, t_list *node)
{
	free(token);
	free(node);
	exit(1);
}
