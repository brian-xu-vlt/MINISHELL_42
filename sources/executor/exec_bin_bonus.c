#include "minishell_bonus.h"


static void	child_process(const char *binary_full_path, const t_cmd *command)
{
		//execve(binary_full_path, command->av, get_env_data(GET)->envp);
		execve(binary_full_path, command->av, NULL);
}

void		execute_bin(const char *binary_full_path, const t_cmd *command)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = fork();
	if (pid == 0)
		child_process(binary_full_path, command);
	else if (pid == FAILURE)
		return ;
	else
		pid = waitpid(pid, &wstatus, 0);

	ft_printf("\nRETURN == %i\n", wstatus);
}
