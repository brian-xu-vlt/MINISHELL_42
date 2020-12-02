#include "minishell.h"

int			history_builtin(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	ft_dprintf(STDERR_FILENO, "History Builtin is available with line edition"
"only...\n");
	return (BUILTIN_SUCCESS);
}
