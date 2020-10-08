#include "minishell_bonus.h"


static void	child_process(const char *binary_full_path, const t_cmd *command)
{
	int	ret;
	
	ret = execve(binary_full_path, command->av, get_env_data(GET)->envp);
	if (ret == FAILURE)
		print_set_errno(ENOENT, command->name, NULL);
	exit(ret);
}

static void	manage_exit_status(int wstatus, pid_t pid)
{
	if (WIFEXITED(wstatus) == TRUE)
		ft_printf("\nEverything is OK : exit status == %i\n", WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus) == TRUE)
		ft_printf("\nGot a signal : %i and core file was created == %d\n", WTERMSIG(wstatus), WCOREDUMP(wstatus));
	else if (WIFSTOPPED(wstatus) == TRUE)
		ft_printf("\nGot a STOPED by pid %d\n", WSTOPSIG(wstatus));
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
		pid = waitpid(pid, &wstatus, WUNTRACED);
	manage_exit_status(wstatus, pid);
	return (wstatus);
}
