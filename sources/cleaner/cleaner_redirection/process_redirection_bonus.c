#include "minishell_bonus.h"

static int	process_less(char *str)
{
	extern int	errno;
	int			fd;

	ft_printf("PROCESS_LESS\n");
	errno = SUCCESS;
	fd = open(str, O_RDONLY | O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR |
				S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		ft_printf("errno is = %s (errno = %d)\n", strerror(errno), errno);
		return (FAILURE);
	}
	ft_printf("errno is = %s (errno = %d)\n", strerror(errno), errno);
	return (SUCCESS);
}

static int	process_greater(char *str)
{
	extern int	errno;
	int			fd;

	ft_printf("PROCESS_GREATER\n");
	errno = SUCCESS;
	fd = open(str, O_RDONLY | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP |
				S_IROTH);
	if (fd < 0)
	{
		ft_printf("errno is = %s (errno = %d)\n", strerror(errno), errno);
		return (FAILURE);
	}
	ft_printf("errno is = %s (errno = %d)\n", strerror(errno), errno);
	return (SUCCESS);
}

static int	process_double_greater(char *str)
{
	extern int	errno;
	int			fd;

	ft_printf("PROCESS_DOUBLE_GREATER\n");
	errno = SUCCESS;
	fd = open(str, O_RDONLY | O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR |
				S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		ft_printf("errno is = %s (errno = %d)\n", strerror(errno), errno);
		return (FAILURE);
	}
	ft_printf("errno is = %s (errno = %d)\n", strerror(errno), errno);
	return (SUCCESS);
}

static int	process_open_file(t_clean_cmd *clean_cmd)
{
	size_t	i;
	int		ret_file;

	ft_printf("\n\ncount_redir = %d\n", clean_cmd->count_redir);//DEBUG
	i = 0;
	ret_file = SUCCESS;
	while (i < clean_cmd->count_redir)
	{
		if (ft_strequ(clean_cmd->tab_redir[i], DOUBLE_GREATER) == TRUE)
			ret_file = process_double_greater(clean_cmd->tab_redir[i + 1]);
		else if (ft_strequ(clean_cmd->tab_redir[i], GREATER_THAN) == TRUE)
			ret_file = process_greater(clean_cmd->tab_redir[i + 1]);
		else if (ft_strequ(clean_cmd->tab_redir[i], LESS_THAN) == TRUE)
			ret_file = process_less(clean_cmd->tab_redir[i + 1]);
		if (ret_file == FAILURE)
		{
			ft_printf("RET_FILE == FAILURE");
			return (FAILURE);
		}
		i += 2;
	}
	return (SUCCESS);
}

int	process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (process_open_file(clean_cmd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}