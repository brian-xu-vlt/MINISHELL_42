#include "minishell_bonus.h"

static void	echo_loop(char **av)
{
	while (*av != NULL)
	{
		ft_putstr_fd(*av, STDOUT_FILENO);
		av++;
		if (*av != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
}

int			echo_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "echo";
	const char	*option = "-n";
	int			new_line_flag;

	(void)envp;
	new_line_flag = TRUE;
	if (av != NULL && ft_strequ(*av, (char *)builtin) == TRUE && ac >= 2)
	{
		av++;
		if (ac >= 2 && ft_strequ(*av, (char *)option) == TRUE)
		{
			new_line_flag = FALSE;
			av++;
		}
		echo_loop(av);
	}
	if (new_line_flag == TRUE)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
