#include "minishell_bonus.h"

static const char	*ms_strsignal(int sig)
{
	int					i;
	static const int 	sig_nb = 15;
	static const int 	sig_list[sig_nb] = {
		SIGALRM, SIGVTALRM, SIGPROF,
		SIGABRT, SIGBUS, SIGSEGV, SIGHUP, SIGQUIT,
		SIGILL, SIGKILL, SIGSTOP, SIGCONT,
		SIGTSTP, SIGTERM, SIGPOLL };
	static const char 	*sig_str[sig_nb] = {
		"Alarm clock","Virtual Alarm clock", "Profiling timer expired",
		"Abort", "Bus Error", "Segmentation Fault", "Hangup", "Quit",
		"Illegal instruction", "Killed", "Stop process", "Continue Process",
		"Stop typed at terminal", "Termination signal", "I/O possible" };
	
	i = 0;
	while (i < sig_nb)
	{
		if (sig_list[i] == sig)
			return (sig_str[i]);
		i++;
	}
	return (NOT_FOUND);
}

static void	display_signal_str(int sig)
{
	const char	*sig_str;

	if ((sig_str = ms_strsignal(sig)) != NOT_FOUND)
		ft_printf("%s ", sig_str);
}

void	manage_subshell_exit_status(const int wstatus)
{
	int			ret;

	ret = 0;
	if (WIFSIGNALED(wstatus) == TRUE)
	{
		ret = WTERMSIG(wstatus);
		display_signal_str(ret);
		if (WCOREDUMP(wstatus) != FALSE)
			ft_printf("(core dumped)");
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
		ret = WSTOPSIG(wstatus);
	else if (WIFEXITED(wstatus) == TRUE)
		ret = WEXITSTATUS(wstatus) - 128;
	ret += (ret != 0) ? 128 : 0;
	ms_setenv_int(get_env_list(GET), "?", ret, F_OVERWRITE);
}
