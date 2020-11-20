#include "minishell_bonus.h"

void	assign_envp_content(const t_cmd *command)
{
	t_list	*env_lst;
	int		i;

	i = 0;
	env_lst = get_env_list(GET);
	while (i < command->count_assign)
	{
		ms_putenv(env_lst, command->envp[i]);
		i++;
	}
}
