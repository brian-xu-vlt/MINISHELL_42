/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:37:57 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:37:58 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*ms_strsignal(int sig)
{
	int					i;
	static const int	sig_list[NB_SIG_STR] = {
		SIGABRT, SIGBUS, SIGSEGV, SIGHUP, SIGQUIT,
		SIGILL, SIGKILL, SIGSTOP, SIGCONT,
		SIGTSTP, SIGTERM };
	static const char	*sig_str[NB_SIG_STR] = {
		"Abort", "Bus Error", "Segmentation Fault", "Hangup", "Quit",
		"Illegal instruction", "Killed", "Stop process", "Continue Process",
		"Stop typed at terminal", "Termination signal" };

	i = 0;
	while (i < NB_SIG_STR)
	{
		if (sig_list[i] == sig)
			return (sig_str[i]);
		i++;
	}
	return (NOT_FOUND);
}

void				display_signal_str(int sig)
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
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
		exit_status = WSTOPSIG(wstatus);
	else if (WIFEXITED(wstatus) == TRUE)
		exit_status = WEXITSTATUS(wstatus) - 128;
	exit_status += (exit_status != 0) ? 128 : 0;
	return (exit_status);
}
