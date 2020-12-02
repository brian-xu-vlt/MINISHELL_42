/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:38:50 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:38:51 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	newprompt_at_signal(int sig)
{
	(void)sig;
	if (DEBUG_MODE != TRUE)
		ft_putstr_fd("^C\n", STDOUT_FILENO);
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
	ft_dprintf(STDERR_FILENO, "%s\n", PROMPT_SIMPLE);
	ms_setenv_int(get_env_list(GET), "?", 130, F_OVERWRITE);
}

static void	quiet_signal(int sig)
{
	(void)sig;
	ft_putchar_fd('\b', STDOUT_FILENO);
	ft_putchar_fd('\b', STDOUT_FILENO);
	ft_putchar_fd(127, STDOUT_FILENO);
	ft_putchar_fd(127, STDOUT_FILENO);
	ft_putchar_fd('\b', STDOUT_FILENO);
	ft_putchar_fd('\b', STDOUT_FILENO);
}

static void	exit_at_signal(int sig)
{
	display_signal_str(sig);
	exit_routine(EXIT_NORMAL);
}

static void	window_at_signal(int sig)
{
	(void)sig;
}

void		signal_manager(int set_mode)
{
	int					i;
	static const int	sig_list[NB_SIG] = {
		SIGHUP, SIGINT, SIGQUIT,
		SIGTERM, SIGWINCH, SIGTSTP };
	static void			(*handlers_mode_cmd_line[NB_SIG])(int) = {
		exit_at_signal, newprompt_at_signal, SIG_IGN,
		exit_at_signal, window_at_signal, quiet_signal};
	static void			(*handlers_mode_cmd_line_no_bonus[NB_SIG])(int) = {
		exit_at_signal, newprompt_at_signal, quiet_signal,
		exit_at_signal, window_at_signal, quiet_signal};

	i = 0;
	while (i < NB_SIG)
	{
		if (set_mode == SIG_MODE_DEFAULT)
			signal(sig_list[i], SIG_DFL);
		else if (set_mode == SIG_MODE_CMD_LINE_NO_BONUS)
			signal(sig_list[i], handlers_mode_cmd_line_no_bonus[i]);
		else if (set_mode == SIG_MODE_EXEC)
			signal(sig_list[i], SIG_IGN);
		else if (set_mode == SIG_MODE_CMD_LINE)
			signal(sig_list[i], handlers_mode_cmd_line[i]);
		i++;
	}
}
