#include "minishell_bonus.h"

void	clean_quote(t_cmd *cmd)
{
	size_t	i;
	char	*str_av;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		if (ft_strchr(cmd->av[i], EXP) == NULL)
		{
			str_av = ft_strdup(cmd->av[i]);
			free(cmd->av[i]);
			cmd->av[i] = clean_quote_no_exp(str_av);
			ft_printf("cmd->av[%d] NEW = %s\n", i, cmd->av[i]);//DEBUG
		}
		else
		{
			str_av = ft_strdup(cmd->av[i]);
			free(cmd->av[i]);
			cmd->av[i] = clean_quote_exp(str_av);
			ft_printf("cmd->av[%d] NEW = %s\n", i, cmd->av[i]);//DEBUG
		}
		i++;
	}
	free(str_av);
}

static int	clean_command(t_cmd *cmd)
{
	int			ass_or_exp;
	bool		is_bad;
	enum e_cmd	cmd_type;

	ft_printf("CLEAN COMMAND\n");//
	ass_or_exp = FALSE;
	if (cmd->count_assign != 0 && cmd->count_exp != 0)
		ass_or_exp = NO_ASSIGN_BUT_EXP;
	is_bad = is_bad_ass_exp(cmd);
	cmd_type = get_cmd_type(cmd);
}

int	cleaner(t_cmd *cmd)
{
	clean_quote(cmd);
	clean_command(cmd);
}
