#include "minishell_bonus.h"

static void	backup_std_fd(int flag)
{
	static int	tmp_fd[NB_FD];
    
	if (flag == STDFD_STORE)
	{  
		tmp_fd[STDIN_FILENO] = ms_dup(STDIN_FILENO);
		tmp_fd[STDOUT_FILENO] = ms_dup(STDOUT_FILENO);
		tmp_fd[STDERR_FILENO] = ms_dup(STDERR_FILENO);
	}                
	else if (flag == STDFD_RESTORE)
	{         
		ms_dup2(tmp_fd[STDIN_FILENO], STDIN_FILENO);
		ms_dup2(tmp_fd[STDOUT_FILENO], STDOUT_FILENO);
		ms_dup2(tmp_fd[STDERR_FILENO], STDERR_FILENO);
		close(tmp_fd[STDIN_FILENO]);
		close(tmp_fd[STDOUT_FILENO]);
		close(tmp_fd[STDERR_FILENO]);
	} 
}                 

static void	close_redirection(t_cmd *cmd)
{
	if (cmd->redirection & F_REDIRECT_IN)
		close(cmd->fd[STDIN_FILENO]);
	if (cmd->redirection & F_REDIRECT_OUT)
		close(cmd->fd[STDOUT_FILENO]);
}

static void	dup_redirection(t_cmd *cmd)
{
	if (cmd->redirection & F_REDIRECT_IN)
		ms_dup2(cmd->fd[STDIN_FILENO], STDIN_FILENO);
	if (cmd->redirection & F_REDIRECT_OUT)
		ms_dup2(cmd->fd[STDOUT_FILENO], STDOUT_FILENO);
}

int			execution_main_process(t_job *job, t_cmd *cmd, int p_in[2], int p_out[2])
{                 
	int			ret;

	if (cmd->ac == 0)
		return (0);     
	if (cmd->redirection & F_REDIRECT_FAILURE)
		return (1);     
	backup_std_fd(STDFD_STORE);
	dup_redirection(cmd);
	ret = 0;
	if (is_solo_builtin(job->nb_cmd, cmd) == TRUE)
		ret = exec_builtin(cmd);
	else
		exec_subshell(job, cmd, p_in, p_out);
	backup_std_fd(STDFD_RESTORE);
	close_redirection(cmd);
	close_pipe_end(p_in[R_END]);
	close_pipe_end(p_in[W_END]);
	return (ret);    
}