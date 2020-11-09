#include "minishell_bonus.h"

# define	NB_BUILTIN	4 

int		is_builtin(const t_cmd *command)
{
	int					i;
	static const char	*builtin_names[NB_BUILTIN] = {
		"exit",	"env", "export", "unset" };

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
		exit_routine_le(ERR_FORK);
	return (pid_ret);
}

int		is_solo_builtin(const int nb_cmd, const t_cmd *command)
{
	return (ft_strequ(command->name, "exit") == TRUE ||
		(nb_cmd == 1 && is_builtin(command) == TRUE));
		//&& command->redirection == F_NO_REDIRECT));
}

int		is_last_cmd(const size_t i, const size_t nb_cmd)
{
	return ((i >= nb_cmd - 1) ? TRUE : FALSE);
}

int		is_valid_job(const t_job *job)
{
	return ((job != NULL && job->cmd_lst != NULL
											&& job->nb_cmd > 0) ? TRUE : FALSE);
}
