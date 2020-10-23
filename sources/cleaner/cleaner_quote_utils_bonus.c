#include "minishell_bonus.h"

bool is_only_quote(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != C_QUOTE && str[i] != C_SIMPLE_QUOTE)
			return (false);
		i++;
	}
	return (true);
}

bool is_clean_command(char *str)
{
	char *clean_cmd[NB_CLEAN_COMMAND] = {"echo", "export", "unset", "env",
										 "exit"};
	size_t i;

	i = 0;
	while (i < NB_CLEAN_COMMAND)
	{
		if (ft_strequ(str, clean_cmd[i]) == TRUE)
			return (true);
		i++;
	}
	return (false);
}

void process_clean_command_quote(t_cmd *cmd, size_t i)
{
	char *str_av;

	str_av = ft_strdup(cmd->av[i]);
	if (ft_strchr(cmd->av[i], EXP) == NULL)
	{
		free(cmd->av[i]);
		cmd->av[i] = clean_quote_no_exp(str_av);
	}
	else
	{
		free(cmd->av[i]);
		cmd->av[i] = clean_quote_exp(str_av);
	}
	free(str_av);
}