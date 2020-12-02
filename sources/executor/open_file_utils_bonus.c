#include "minishell_bonus.h"

void	print_file_error(char **str, size_t i, size_t size)
{
	ft_dprintf(STDERR_FILENO, "Minishell: ");
	while (i < size)
	{
		if (i + 1 < size)
			ft_dprintf(STDERR_FILENO, "%s ", str[i]);
		else if (i + 1 == size)
			ft_dprintf(STDERR_FILENO, "%s", str[i]);
		i++;
	}
	ft_dprintf(STDERR_FILENO, ": no file mentioned\n");
}

int		set_size(t_cmd *cmd, int flag)
{
	if (cmd != NULL)
	{
		if (flag == BEFORE)
			return (cmd->count_redir_before);
		else if (flag == AFTER)
			return (cmd->count_redir);
	}
	return (0);
}
