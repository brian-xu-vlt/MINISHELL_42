#include "minishell_bonus.h"
/*
	SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGABRT, SIGBUS, SIGFPE, SIGKILL,
	SIGUSR1, SIGSEGV, SIGUSR2, SIGPIPE, SIGALRM, SIGTERM, SIGCHLD, SIGCONT,
	SIGSTOP, SIGTSTP, SIGTTIN, SIGTTOU, SIGURG, SIGXCPU, SIGXFSZ, SIGVTALRM,
	SIGPROF, SIGWINCH, SIGPOLL, SIGSYS 
*/
/*
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
		//"Hangup", "Illegal instruction", "^C", "Broken pipe",
		"Hangup", "Illegal instruction", "\n", "Broken pipe",
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

(void)pid;
		pid = get_env_value_int(get_env_list(GET), "!");
	if (pid != 0)
		kill(pid, sig);
	if ((sig_str = ms_strsignal(sig)) != NOT_FOUND)
		ft_printf("%s ", sig_str);
}
*/

static void	newprompt_at_signal(int sig)
{
	(void)sig;
	ft_putstr_fd("[--^C--]\n", STDOUT_FILENO);
	init_prompt();
}

static void	exit_at_signal(int sig)
{
	(void)sig;
	exit_routine_le("exit");
}

static void	window_at_signal(int sig)
{
	(void)sig;
	update_window_size();
}

static void	send_signal_to_child(int sig)
{
	pid_t		pid;

	pid = 0;
	pid = get_env_value_int(get_env_list(GET), "!");
	ft_printf("{%d}\n", pid);
	if (pid != 0)
		kill(pid, sig);
}

void		signal_manager(int set_mode)
{
	int					i;
	static const int 	sig_nb = 5;
	static const int 	sig_list[sig_nb] = {
		SIGHUP,	SIGINT, SIGQUIT,
		SIGTERM, SIGWINCH
	};
	static void 	(*handlers_mode_normal[sig_nb])(int) = {
		exit_at_signal,	newprompt_at_signal, SIG_IGN,
		exit_at_signal, window_at_signal
	};

	i = 0;
	while (i < sig_nb)
	{
		if (set_mode == SIG_MODE_DEFAULT)
			signal(sig_list[i], SIG_DFL);
		else if (set_mode == SIG_MODE_EXEC)
			signal(sig_list[i], send_signal_to_child);
		else if (set_mode == SIG_MODE_CMD_LINE)
			signal(sig_list[i], handlers_mode_normal[i]);
		i++;
	}
}
