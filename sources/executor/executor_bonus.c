#include "minishell_bonus.h"
#define R_END		0
#define W_END		1

static int		exec_bin(const t_cmd *command)
{
	int		ret_value;

	ret_value = -1;
	ret_value = execute_bin(command->name, command);
	if (ret_value != 0 || errno != 0)
		ret_value = 128 + ret_value;
	return (ret_value);
}

void			executor(const t_job *job)
{
	size_t	i;
	int		ret_value;
	t_list	*cmd_cursor;
	int			p_in[2] = {-1, -1};
	int			p_out[2] = {-1, -1};
//	pid_t	pid;
//	int		wstatus;
	
	if (job == NULL || job->cmd_lst == NULL)
		return ;
	i = 0;
	cmd_cursor = job->cmd_lst;
	while (i < job->nb_cmd && cmd_cursor->content != NULL)
	{
		system("ls -la /proc/$$/fd");
		if (i < job->nb_cmd - 1)
			pipe(p_out);
		ret_value = 0;
		if (is_builtin(cmd_cursor->content) == TRUE)
			ret_value = exec_builtin(cmd_cursor->content);
		else
			ret_value = exec_bin(cmd_cursor->content);
		close(p_in[R_END]);	
		close(p_in[W_END]);	
		if (i < job->nb_cmd - 1)
		{
			p_in[R_END] = p_out[R_END];
			p_in[W_END] = p_out[W_END];
		}
		else
		{
			close(p_out[R_END]);
			close(p_out[W_END]);
			p_out[R_END] = -1;
			p_out[W_END] = -1;
		}
		cmd_cursor = cmd_cursor->next;
		i++;
	}
//	while ((pid = wait(&wstatus)) > -1);
	ms_setenv_int(get_env_list(GET), "?", ret_value, F_OVERWRITE | F_EXPORT); //  ATTENTION ///////// remove F_EXPORT flag
	ft_printf("\n(executor) $? == %d\n", get_env_value_int(get_env_list(GET), "?")); // DEBUG
}
