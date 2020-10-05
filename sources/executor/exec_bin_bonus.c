#include "minishell_bonus.h"


static void	child_process(const char *binary_full_path, const t_cmd *command)
{
		int	ret;
		
		ret = execve(binary_full_path, command->av, get_env_data(GET)->envp);
		if (ret == FAILURE)
			print_set_errno(ENOENT, command->name, NULL);
		exit(ret);
}

int			execute_bin(const char *binary_full_path, const t_cmd *command)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
//	update_existing_env("?=0");
	pid = fork();
	if (pid == 0)
		child_process(binary_full_path, command);
	else if (pid == FAILURE)
		return (FAILURE);
	else
		pid = waitpid(pid, &wstatus, 0);
	ft_printf("\nRETURN fork == %i\n", wstatus);
	return (wstatus);
}
