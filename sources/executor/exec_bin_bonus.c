#include "minishell_bonus.h"

	
void	exec_bin(const char *binary_full_path, const t_cmd *command)
{
	execve(binary_full_path, command->av, get_env_data(GET)->envp);
	return ;
/*
	pid_t	pid;
	pid = fork();

	if (pid != FAILURE && pid != 0)
		execve(binary_full_path, command->av, get_env_data(GET)->envp);
	else
		wait ;
*/
}
