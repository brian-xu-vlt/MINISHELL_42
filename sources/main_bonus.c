#include "minishell_bonus.h"

static int			is_new_line(t_vector *rest, t_vector *vct)
{
	t_vector	*tmp;

	if (vct_chr(rest, '\n') != FAILURE)
	{
		tmp = vct_splitchr(rest, '\n');
		vct_cat(vct, tmp);
		vct_del(&tmp);
		return (TRUE);
	}
	return (FALSE);
}

static ssize_t		vct_readline_local(t_vector *vct, const int fd)
{
	ssize_t			ret;
	static t_vector	*rest = NULL;
	char			buff[BUFFER_SIZE];

	if (vct == NULL || fd < 0)
	{
		vct_del(&rest);
		return (fd == CLEANUP ? IS_EOF : FAILURE);
	}
	rest = rest == NULL ? vct_new() : rest;
	ft_bzero(vct->str, vct->size);
	vct->len = 0;
	if (is_new_line(rest, vct) == TRUE)
		return (IS_LINE);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (ft_strlen(buff) == 0)
			return (IS_LINE);
		if (vct_addmem(rest, buff, (size_t)ret) == FAILURE)
			return (FAILURE);
		if (is_new_line(rest, vct) == TRUE)
			return (IS_LINE);
	}
	if (ret != FAILURE && rest->len != 0)
		vct_cat(vct, rest);
	vct_del(&rest);
	return (IS_EOF);
}

static int	read_loop(t_vector *cmd_line)
{
	int		read_ret;

	read_ret = 0;
	print_prompt();
	close(STDERR_FILENO);
	errno = 0;
	if ((read_ret = vct_readline_local(cmd_line, 0)) == FAILURE)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine_le(ERR_NO_MESSAGE);
	}
	return (read_ret);
}


static void	usage(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: Minishell does not take any argument\n");
		exit (FAILURE);
	}
}

static t_list	*process_minishell(t_vector *cmd_line)
{
	t_list		*lexer_list;
	t_list		*jobs;
	int			ret_parser;

	lexer_list = NULL;
	jobs = NULL;
	ret_parser = SUCCESS;
	lexer_list = test_lexer(cmd_line);
	if (lexer_list != NULL)
	{
		ret_parser = test_parser(lexer_list);
		if (ret_parser != FALSE)
			jobs = test_jobs(lexer_list);
		if (jobs == NULL)
			free_list_job(&jobs);
	}
	free_list_token(&lexer_list);
	return (jobs);
}

static void	check_std_fd(void)
{
	struct stat	wstat;

	if ((write(STDOUT_FILENO, "", 0) == FAILURE)
	|| (write(STDERR_FILENO, "", 0) == FAILURE)
	|| (fstat(STDIN_FILENO, &wstat) != 0))
	  	exit(0);
}

int			main(int ac, char **av)
{
	t_vector	*cmd_line;
	t_list		*jobs;
	int			ret_read;

	check_std_fd();
	usage(ac, av);
	init_env();
	cmd_line = vct_new();
	if (cmd_line == NULL)
		exit_routine_le(ERR_MALLOC);
	init_line_editor(cmd_line);
	jobs = NULL;
	ret_read = 1;
	while (ret_read > 0)
	{
		if (DEBUG_MODE == TRUE)
		{
			signal_manager(SIG_MODE_CMD_LINE_NO_BONUS);
			ret_read = read_loop(cmd_line);
		}
		else
		{
			signal_manager(SIG_MODE_CMD_LINE);
			ret_read = line_editor();
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		jobs = process_minishell(cmd_line);
		if (jobs != NULL)
		{
			if (hub_cleaner(jobs) == FAILURE)
			{
				vct_clear(cmd_line);
				free_list_job(&jobs);
				exit_routine_le(NULL);
				return (EXIT_FAILURE);
			}
		}
		vct_clear(cmd_line);
		free_list_job(&jobs);
//	ft_printf("\t\t\t\t[LAST EXIT STATUS %3d]\r", get_env_value_int(get_env_list(GET), "?"));  //TODO remove
	}
	exit_routine_le(NULL);
	free_list_job(&jobs);
	return (EXIT_SUCCESS);
}
