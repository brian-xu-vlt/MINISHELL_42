#include "minishell_bonus.h"

void	export_envp_content(const t_cmd *command)
{
	t_list	*env_lst;
	int		i;

	i = 0;
	env_lst = get_env_list(GET);
	while (i < command->count_assign)
	{
		export_env(env_lst, command->envp[i]);
		i++;
	}
}
