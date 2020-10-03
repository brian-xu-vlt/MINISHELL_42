#include "minishell_bonus.h"

static t_cmd	*fill_cmd_struct(int ac, char **av)
{
	t_cmd		*command;

	if (NB_FD != 3)
		return (NULL);
	command = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (command == NULL)
		exit_routine_le(ERR_MALLOC);
	command->name = av[0];
	command->ac = ac;
	command->av = av;
	command->fd[0] = STDIN_FILENO;
	command->fd[1] = STDOUT_FILENO;
	command->fd[2] = STDERR_FILENO;
	command->fd_string[0] = "STDIN_FILENO";
	command->fd_string[1] = "STDOUT_FILENO";
	command->fd_string[2] = "STDERR_FILENO";
	return (command);
}

static void		free_command_struct(t_cmd *command)
{
	int		i;

	i = 0;
	if (command->ac != 0)
	{
		while (command->av[i] != NULL)
			free(command->av[i++]);
		free(command->av);
	}
	free(command);
}

static t_cmd	*fake_cmd_parser(t_vector *cmd_line)
{
	char	**av;
	int		ac;

	av = ft_split(vct_getstr(cmd_line), ' ');
	ac = 0;
	while (av[ac] != NULL)
		ac++;
	return (fill_cmd_struct(ac, av));
}

int		test_executor(t_vector *cmd_line)
{
	t_cmd	*command;
	
	command = fake_cmd_parser(cmd_line);
	if (command != NULL)
	{
		executor(command);
		free_command_struct(command);
		return (SUCCESS);
	}
	return (FAILURE);
}
