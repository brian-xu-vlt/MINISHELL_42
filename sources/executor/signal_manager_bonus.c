#include "minishell_bonus.h"

static void	newprompt_at_signal(int sig)
{
	(void)sig;
	if (DEBUG_MODE != TRUE)
		ft_putstr_fd("^C\n", STDOUT_FILENO);
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
	init_prompt();
	ms_setenv_int(get_env_list(GET), "?", 130, F_OVERWRITE);
}

static void	no_bonus_quit_handler(int sig)
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
	(void)sig;
		ft_putstr_fd("----------------\n", STDOUT_FILENO);
	exit_routine_le("exit");
}

static void	window_at_signal(int sig)
{
	(void)sig;
	update_window_size();
}

void		signal_manager(int set_mode)
{
	int					i;
	static const int	sig_list[NB_SIG] = {
		SIGHUP, SIGINT, SIGQUIT,
		SIGTERM, SIGWINCH	};
	static void			(*handlers_mode_cmd_line[NB_SIG])(int) = {
		exit_at_signal, newprompt_at_signal, SIG_IGN,
		exit_at_signal, window_at_signal };
	static void			(*handlers_mode_cmd_line_no_bonus[NB_SIG])(int) = {
		exit_at_signal, newprompt_at_signal, no_bonus_quit_handler,
		exit_at_signal, window_at_signal };

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
