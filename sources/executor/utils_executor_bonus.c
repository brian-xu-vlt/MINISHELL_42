#include "minishell_bonus.h"

int		is_builtin(const t_cmd *command)
{
	int					i;
	static const char	*builtin_names[NB_BUILTIN] = {
	"cd", "echo", "pwd", "exit", "env", "export", "unset", "history", "set" };

	i = 0;
	while (i < NB_BUILTIN)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

pid_t	fork_process(void)
{
	pid_t	pid_ret;

	errno = 0;
	pid_ret = fork();
	while (pid_ret == FAILURE && errno == EAGAIN)
		pid_ret = fork();
	if (pid_ret == FAILURE)
		exit_routine(EXIT_FORK);
	return (pid_ret);
}

int		is_solo_builtin(const size_t nb_cmd, t_cmd *command)
{
	if (nb_cmd == 1 && is_builtin(command) == TRUE)
	{
		command->solo_builtin = true;
		return (true);
	}
	return (false);
	// return (nb_cmd == 1 && is_builtin(command) == TRUE);
}

int		is_last_cmd(const int cmd_index, const int nb_cmd)
{
	return ((cmd_index >= nb_cmd - 1) ? TRUE : FALSE);
}

int		is_valid_job(const t_job *job)
{
	return ((job != NULL && job->cmd_lst != NULL
											&& job->nb_cmd > 0) ? TRUE : FALSE);
}
