#include "minishell_bonus.h"
/*
	SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGABRT, SIGBUS, SIGFPE, SIGKILL,
	SIGUSR1, SIGSEGV, SIGUSR2, SIGPIPE, SIGALRM, SIGTERM, SIGCHLD, SIGCONT,
	SIGSTOP, SIGTSTP, SIGTTIN, SIGTTOU, SIGURG, SIGXCPU, SIGXFSZ, SIGVTALRM,
	SIGPROF, SIGWINCH, SIGPOLL, SIGSYS 
*/

static const char	*ms_strsignal(int sig)
{
	int					i;
	static const int 	sig_nb = 13;
	static const int 	sig_list[sig_nb] = {
		SIGABRT, SIGBUS, SIGSEGV, SIGCHLD,
		SIGHUP, SIGILL, SIGINT, SIGPIPE,
		SIGQUIT, SIGSTOP, SIGCONT, SIGTSTP,
		SIGTERM
	};
	static const char 	*sig_str[sig_nb] = {
		"Abort", "Bus Error", "Segmentation Fault", "Child status has changed",
		//"Hangup", "Illegal instruction", "Interrupt ^C", "Broken pipe",
		"Hangup", "Illegal instruction", "", "Broken pipe",
		"Quit", "Stop process", "Continue Process", "Stop typed at terminal",
		"Termination signal"
	};
	
	i = 0;
	while (i < sig_nb)
	{
		if (sig_list[i] == sig)
			return (sig_str[i]);
		i++;
	}
	return (NOT_FOUND);
}

static void	display_signal(int sig)
{
	pid_t		pid;
	const char	*sig_str;

	pid = get_env_value_int(get_env_list(GET), "!");
	if (pid != 0)
		kill(pid, sig);
	if ((sig_str = ms_strsignal(sig)) != NOT_FOUND)
		ft_printf("%s ", sig_str);
}

void		signal_manager(int set_mode)
{
	int					i;
	static const int 	sig_nb = 3;
	static const int 	sig_list[sig_nb] = {
		SIGINT, SIGQUIT, SIGCHLD
	};
	static void 	(*handler_mode_exec[sig_nb])(int) = {
		display_signal, display_signal, SIG_DFL
	};
	static void 	(*handler_mode_line_editor[sig_nb])(int) = {
		display_signal, SIG_IGN, display_signal
	};

	i = 0;
	while (i < sig_nb)
	{
		if (set_mode == SIG_MODE_NORMAL)
			signal(sig_list[i], SIG_DFL);
		else if (set_mode == SIG_MODE_LINE_EDITOR)
			signal(sig_list[i], handler_mode_line_editor[i]);
		else if (set_mode == SIG_MODE_EXEC)
			signal(sig_list[i], handler_mode_exec[i]);
		i++;
	}
}