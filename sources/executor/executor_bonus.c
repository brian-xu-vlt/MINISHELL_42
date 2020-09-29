#include "minishell_bonus.h"

void	executor(t_cmd *command)
{
	write(STDERR_FILENO, "\n", 1);
	if (command == NULL)
		exit_routine_le(ERR_MALLOC);
	execve(command->name, command->av, get_env_data(GET)->envp);
}
