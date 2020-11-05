#include "minishell_bonus.h"

void	export_execution_context_env(const t_cmd *command)
{
	t_list	*env_lst;

	env_lst = get_env_list(GET);
	//insert here : function to assign content of t_cmd->envp
	(void)command;
	// if (command->envp != NULL)
	// 		do export of each envp here
	//	export_env(env_lst, "PATH=/tmp/bin"); 	// TEST
	//	export_env(env_lst, "PATH="); 	// TEST
}
