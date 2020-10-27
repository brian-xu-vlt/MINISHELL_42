#include "minishell_bonus.h"

static t_clean_cmd	*init_clean_command()
{
	t_clean_cmd	*clean_cmd;
	
	clean_cmd = (t_clean_cmd *)malloc(sizeof(t_clean_cmd));
	if (clean_cmd == NULL)
		return (NULL);
	clean_cmd->count_assign = 0;
	clean_cmd->ac = 0;
	clean_cmd->index_export = 0;
	clean_cmd->av = NULL;
	return (clean_cmd);
}

static int	process_command_any(t_cmd *cmd, int ass_or_exp, bool is_bad,
								enum e_cmd cmd_type)
{
	if (is_bad == false)
		ft_printf("EXPORT POP ENV ET ASSIGN\n");
	//POP DANS ENV ET ASSIGN
	else if (is_bad = true)
		ft_printf("POP ENV CELUI FAUX\n");
	//POP SAUF CELUI FAUX
}

static int *process_command_command(t_cmd *cmd, int ass_or_exp, bool is_bad,
									enum e_cmd cmd_type)
{
	//SI LA COMMANDE EN QUESTION EST UNSET -->> ASS_OR_EXP = FALSE
	ft_printf("EXPORT POP MAIS PAS DANS ENV\n");
}

static int process_command_export(t_cmd *cmd, int ass_or_exp, bool is_bad,
								   enum e_cmd cmd_type)
{
	t_clean_cmd	*clean_cmd;
	size_t		i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		process_clean_command_quote(cmd, i);
		i++;
	}
	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		ft_printf("CLEAN COMMAND == NULL");
		return (FAILURE);//ERROR
	}
	count_ac_assign(cmd, clean_cmd, is_bad);
	clean_cmd->ac = cmd->ac - clean_cmd->count_assign;
	ft_printf("AC = %d\n", cmd->ac);//DEBUG
	ft_printf("ASS_OR_EXP = %d\n", ass_or_exp);//DEBUG
	ft_printf("CLEAN_CMD->COUNT_ASSIGN = %d\n", clean_cmd->count_assign);//DEBUG
	ft_printf("CLEAN_CMD->AC = %d\n", clean_cmd->ac);//DEBUG
	ft_printf("CLEAN_CMD->INDEX_EXPORT = %d\n", clean_cmd->index_export);//DEBUG
	if (init_tab_assign_ac(clean_cmd, cmd) == FAILURE)
	{
		ft_printf("PAS DE FAILURE\n");
		return (FAILURE);//ERROR
	}
	fill_clean_cmd(cmd, clean_cmd);
	ft_printf("CMD->COUNT_ASSIGN = %d\n", cmd->count_assign);//DEBUG
	/*if (cmd->count_assign != 0 && is_bad == false)
		ft_printf("EXPORT POP ENV\n");
	else if (cmd->count_assign != 0 && is_bad == true)
		ft_printf("EXPORT POP PAS ENV\n");
	//POP ET PAS ENV*/
	return (SUCCESS);
}

int process_clean_command(t_cmd *cmd, int ass_or_exp, bool is_bad,
						  enum e_cmd cmd_type)
{
	//COMPARER CHAQUE IF AVEC LES INDEXS DE OU SE TROUVE LES ASSIGN
	// + revoir les diff printf
	if (cmd_type == E_EXPORT_EXEC || cmd_type == E_EXPORT_NO_EXEC)
		if (process_command_export(cmd, ass_or_exp, is_bad, cmd_type) == FAILURE)
			return (FAILURE);
	if (cmd_type == E_COMMAND)
		if (process_command_command(cmd, ass_or_exp, is_bad, cmd_type) == FAILURE)
			return (FAILURE);
	if (cmd_type == E_ANY)
		if (process_command_any(cmd, ass_or_exp, is_bad, cmd_type) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}