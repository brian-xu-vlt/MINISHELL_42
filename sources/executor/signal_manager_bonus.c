#include "minishell_bonus.h"

static void	sig_handler_int(int sig)
{
	ft_printf("sig_handler_int with signal %d\n", sig);
}

void		signal_manager(int mode)
{
	int					i;
	static const int 	sig_nb = 2;
	static const int 	sig_list[sig_nb] = {
		SIGINT, SIGQUIT
	};
	static void 	(*handler_mode_exec[sig_nb])(int) = {
		sig_handler_int, sig_handler_int
	};
	static void 	(*handler_mode_line_editor[sig_nb])(int) = {
		sig_handler_int, sig_handler_int
	};

	i = 0;
	while (i < sig_nb)
	{
		if (mode == SIG_MODE_NORMAL)
			signal(sig_list[i], SIG_DFL);
		else if (mode == SIG_MODE_LINE_EDITOR)
			signal(sig_list[i], handler_mode_line_editor[i]);
		else if (mode == SIG_MODE_EXEC)
			signal(sig_list[i], handler_mode_exec[i]);
		i++;
	}
}
