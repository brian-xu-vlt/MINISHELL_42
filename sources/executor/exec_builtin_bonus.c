#include "minishell_bonus.h"

# define	NB_BUILTIN	4 

int			exec_builtin(t_cmd *command, int p_in[2], int p_out[2])
{
	int					i;
	int					ret_value;
	static const char	*builtin_names[NB_BUILTIN] = {
		"exit", "env", "export", "unset" };
	static int			(*builtin[NB_BUILTIN])(int, char **, char **) = {
		exit_builtin, env_builtin, export_builtin, unset_builtin };
	int tmp_fd[NB_FD] = {UNSET, UNSET, UNSET};

	i = 0;
	ret_value = 0;

	if (command->ac > 0)
	{
		tmp_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
		tmp_fd[STDIN_FILENO] = dup(STDIN_FILENO);
		if (command->redirection & F_REDIRECT_FAILURE)
			return (1);
		if (command->redirection & F_REDIRECT_IN)
			dup2(command->fd[STDIN_FILENO], STDIN_FILENO);
		if (command->redirection & F_REDIRECT_OUT)
			dup2(command->fd[STDOUT_FILENO], STDOUT_FILENO);
		(void)p_in;
		(void)p_out;

		while (i < NB_BUILTIN)
		{
			if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			{
				ret_value = (builtin[i])(command->ac, command->av, command->envp);
				break ;
			}
			i++;
		}
		if (command->redirection & F_REDIRECT_IN)
			close(command->fd[STDIN_FILENO]);
		if (command->redirection & F_REDIRECT_OUT)
			close(command->fd[STDOUT_FILENO]);
		dup2(tmp_fd[STDIN_FILENO], STDIN_FILENO);
		dup2(tmp_fd[STDOUT_FILENO], STDOUT_FILENO);
		return (ret_value);
	}
	return (0);
}