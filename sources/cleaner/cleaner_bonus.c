#include "minishell_bonus.h"


void		clean_quote(t_cmd *cmd)
{
	size_t	i;
	char	*tmp_av0;

	i = 0;
	tmp_av0 = ft_strdup(cmd->av[0]);
	while (i < (size_t)cmd->ac)
	{
		if (is_clean(i, tmp_av0, cmd->av[i], cmd) == true)
		{
			ft_printf("IS_CLEAN == TRUE\n");
			process_clean_command_quote(cmd, i);
		}
		i++;
	}
	free(tmp_av0);
}

static int	clean_command(t_cmd *cmd)
{
	int			ass_or_exp;
	bool		is_bad;
	enum e_cmd	cmd_type;

	ass_or_exp = FALSE;
	is_bad = false;
	if (cmd->count_assign != 0 && cmd->count_exp != 0)
		ass_or_exp = NO_ASSIGN_BUT_EXP;
	cmd_type = get_cmd_type(cmd);
	if (cmd_type == E_EXPORT_EXEC || cmd_type == E_EXPORT_NO_EXEC)
		ass_or_exp = FALSE;
	ft_printf("CMD TYPE = %d\n\n", cmd_type);
	if (cmd->count_assign != 0)
		is_bad = is_bad_ass(cmd);
	if (process_clean_command(cmd, ass_or_exp, is_bad, cmd_type) == FAILURE)
	{
		ft_printf("PROCESS CLEAN COMMAND == FAILURE\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	cleaner(t_cmd *cmd)
{
	clean_quote(cmd);
	ft_printf("\n\033[0;32mDEBUG AV CLEAN QUOTE\n\033[0m");//DEBUG
	debug_av(cmd->av, cmd->ac);//DEBUG
	if (clean_command(cmd) == FAILURE)
	{
		ft_printf("CLEAN COMMAND == FAILURE\n");
		return (FAILURE);
	}
	return (SUCCESS);
}