#include "minishell_bonus.h"

static void	echo_loop(char **av)
{
	size_t		av_len;

	while (av != NULL && *av != NULL)
	{
		av_len = ft_strlen(*av);
		if (av_len > 0)
			ft_putstr_fd(*av, STDOUT_FILENO);
		av++;
		// if (*av != NULL && av_len > 0)
		if (*av != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
}

static int	is_valid_option(const char *av_to_test, const char *option)
{
	int			i;

	if (av_to_test == NULL || option == NULL)
		return (FAILURE);
	if (av_to_test[0] != '-' || option[0] != '-'
						|| ft_strlen(av_to_test) < 2 || ft_strlen(option) != 2)
		return (FALSE);
	i = 1;
	while (av_to_test[i] != '\0' && ft_isprint(option[1]) == TRUE)
	{
		if (av_to_test[i] != option[1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			echo_builtin(int ac, char **av, __attribute__((unused)) char **envp)
{
	const char	*builtin = "echo";
	const char	*option = "-n";
	int			new_line_flag;

	new_line_flag = TRUE;
	if (av != NULL && ft_strequ(*av, (char *)builtin) == TRUE && ac >= 2)
	{
		av++;
		while (av != NULL && is_valid_option(*av, option) == TRUE)
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
