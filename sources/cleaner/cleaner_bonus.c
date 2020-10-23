#include "minishell_bonus.h"

void	clean_quote(t_cmd *cmd)
{
	size_t	i;
	char	*str_av;
	char	*tmp_av0;

	i = 0;
	tmp_av0 = ft_strdup(cmd->av[0]);
	while (i < (size_t)cmd->ac)
	{
		if (i != 0 && is_clean_command(tmp_av0) == true)
		{
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
			ft_printf("cmd->av[%d] CLEAN_COMMAND = %s\n", i, cmd->av[i]);//DEBUG
			free(str_av);
			i++;
			continue ;
		}
		if (i == 0 && is_only_quote(cmd->av[i]) == false)
		{
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
			ft_printf("cmd->av[%d] ONLY QUOTE FALSE = %s\n", i, cmd->av[i]);//DEBUG
			free(str_av);
			i++;
			continue ;
		}
		if (i == 0 && is_only_quote(cmd->av[i]) == true)
		{
			ft_printf("cmd->av[%d] ONLY QUOTE TRUE = %s\n", i, cmd->av[i]);//DEBUG
			i++;
			continue ;
		}
		if (ft_strchr(cmd->av[i], EXP) == NULL && is_clean_command(tmp_av0) == true)
		{
			str_av = ft_strdup(cmd->av[i]);
			free(cmd->av[i]);
			cmd->av[i] = clean_quote_no_exp(str_av);
			ft_printf("cmd->av[%d] NO EXP = %s\n", i, cmd->av[i]);//DEBUG
			free(str_av);
		}
		if (ft_strchr(cmd->av[i], EXP) != NULL && is_clean_command(tmp_av0) == true)
		{
			str_av = ft_strdup(cmd->av[i]);
			free(cmd->av[i]);
			cmd->av[i] = clean_quote_exp(str_av);
			ft_printf("cmd->av[%d] EXP = %s\n", i, cmd->av[i]);//DEBUG
			free(str_av);
		}
		ft_printf("cmd->av[%d] NO CLEAN_COMMAND = %s\n", i, cmd->av[i]);//DEBUG
		i++;
	}
	free(tmp_av0);
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
	cmd_type = get_cmd_type(cmd);
	is_bad = is_bad_ass_exp(cmd);
}

int	cleaner(t_cmd *cmd)
{
	clean_quote(cmd);
	clean_command(cmd);
}
