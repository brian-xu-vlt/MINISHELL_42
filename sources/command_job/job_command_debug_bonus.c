#include "minishell_bonus.h"

char	*debug_get_type(int type)
{
	char	*str_type[] = {"CMD_ASSIGN", "CMD_SIMPLE_REDIRECTION",
								"CMD_DOUBLE_REDIRECTION", "CMD_AV"};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == type)
			return (str_type[i]);
		i++;
	}
	return (NULL);
}

void	debug_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	printf("------------ NEW CMD ----------------\n");
	printf("name = %s\n", cmd->name);
	for (int i = 0; i < cmd->ac; i++) 
		printf("|-> av[%d] = [%s]\n", i, cmd->av[i]);
	for (int i = 0; i < 3; i++) 
		printf("|-> fd_string[%d] = [%s]\n", i, cmd->fd_string[i]);
	printf("-------------------------------------\n");
}
void	debug_token_list(t_list *list)
{
	t_token	*token;

	ft_printf("/////////////////\n");
	for (; list != NULL; list = list->next)
	{
		token = list->content;
		parser_debug(token);
	}
	ft_printf("/////////////////\n");
}
