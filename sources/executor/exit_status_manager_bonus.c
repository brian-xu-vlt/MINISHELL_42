#include "minishell_bonus.h"

static const char	*ms_strsignal(int sig)
{
	int					i;
	static const int	sig_list[NB_SIG_STR] = {
		SIGALRM, SIGVTALRM, SIGPROF,
		SIGABRT, SIGBUS, SIGSEGV, SIGHUP, SIGQUIT,
		SIGILL, SIGKILL, SIGSTOP, SIGCONT,
		SIGTSTP, SIGTERM, SIGPOLL };
	static const char	*sig_str[NB_SIG_STR] = {
		"Alarm clock", "Virtual Alarm clock", "Profiling timer expired",
		"Abort", "Bus Error", "Segmentation Fault", "Hangup", "Quit",
		"Illegal instruction", "Killed", "Stop process", "Continue Process",
		"Stop typed at terminal", "Termination signal", "I/O possible" };

	i = 0;
	while (i < NB_SIG_STR)
	{
		if (sig_list[i] == sig)
			return (sig_str[i]);
		i++;
	}
	return (NOT_FOUND);
}

static void			display_signal_str(int sig)
{
	const char			*sig_str;

	if ((sig_str = ms_strsignal(sig)) != NOT_FOUND)
		ft_printf("%s ", sig_str);
}

int					manage_subshell_exit_status(const int wstatus)
{
	int					exit_status;

	exit_status = 0;
	if (WIFSIGNALED(wstatus) == TRUE)
	{
		exit_status = WTERMSIG(wstatus);
		display_signal_str(exit_status);
		if (WCOREDUMP(wstatus) != FALSE)
			ft_printf("(core dumped)");
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
		exit_status = WSTOPSIG(wstatus);
	else if (WIFEXITED(wstatus) == TRUE)
		exit_status = WEXITSTATUS(wstatus) - 128;
	exit_status += (exit_status != 0) ? 128 : 0;
	return (exit_status);
}
