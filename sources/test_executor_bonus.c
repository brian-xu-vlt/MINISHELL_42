#include "minishell_bonus.h"

static t_cmd	*fill_cmd_struct(char *executable, char *av1)
{
	int			ac;
	t_cmd		*command;

	command = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (command == NULL)
		exit_routine_le(ERR_MALLOC);
	command->name = executable;
	ac = (av1 == NULL) ? 1 : 2;
	command->av = (char **)ft_calloc(ac + 1, sizeof(char *));
	if (command->av == NULL)
		exit_routine_le(ERR_MALLOC);
	command->av[0] = executable;	
	command->av[1] = av1;
	command->ac = ac;
	return (command);
}

static t_cmd	*fake_cmd_parser(t_vector *input)
{
	if (ft_strncmp(vct_getstr(input), "1", 2) == 0)
		return (fill_cmd_struct("/bin/ls", "-l"));
	if (ft_strncmp(vct_getstr(input), "2", 2) == 0)
		return (fill_cmd_struct("/bin/ls", NULL));
	else
		return (NULL);
}

int		test_executor(t_vector *input)
{
	t_cmd	*command;
	
	command = fake_cmd_parser(input);
	if (command != NULL)
		executor(command);
	return (SUCCESS);
}
