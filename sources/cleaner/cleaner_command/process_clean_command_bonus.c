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
	return (clean_cmd);
}

static t_clean_cmd *process_command_any(t_cmd *cmd, int ass_or_exp, bool is_bad,
								enum e_cmd cmd_type)
{
	if (is_bad == false)
		ft_printf("EXPORT POP ENV ET ASSIGN\n");
	//POP DANS ENV ET ASSIGN
	else if (is_bad = true)
		ft_printf("POP ENV CELUI FAUX\n");
	//POP SAUF CELUI FAUX
}

static t_clean_cmd *process_command_command(t_cmd *cmd, int ass_or_exp, bool is_bad,
									enum e_cmd cmd_type)
{
	ft_printf("EXPORT POP MAIS PAS DANS ENV\n");
}

static t_clean_cmd *process_command_export(t_cmd *cmd, int ass_or_exp, bool is_bad,
								   enum e_cmd cmd_type)
{
	t_clean_cmd	*clean_cmd;

	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		ft_printf("CLEAN COMMAND == NULL");
		return (NULL);
	}
	count_ac_assign(cmd, clean_cmd, is_bad);
	clean_cmd->ac = cmd->ac - clean_cmd->count_assign;
	ft_printf("AC = %d\n", cmd->ac);//DEBUG
	ft_printf("CLEAN_CMD->COUNT_ASSIGN = %d\n", clean_cmd->count_assign);//DEBUG
	ft_printf("CLEAN_CMD->AC = %d\n", clean_cmd->ac);//DEBUG
	ft_printf("CLEAN_CMD->INDEX_EXPORT = %d\n", clean_cmd->index_export);//DEBUG
	/*if (cmd->count_assign != 0 && is_bad == false)
		ft_printf("EXPORT POP ENV\n");
	else if (cmd->count_assign != 0 && is_bad == true)
		ft_printf("EXPORT POP PAS ENV\n");
	//POP ET PAS ENV*/
}

int process_clean_command(t_cmd *cmd, int ass_or_exp, bool is_bad,
						  enum e_cmd cmd_type)
{
	//COMPARER CHAQUE IF AVEC LES INDEXS DE OU SE TROUVE LES ASSIGN
	// + revoir les diff printf
	if (cmd_type == E_EXPORT_EXEC || cmd_type == E_EXPORT_NO_EXEC)
	{
		process_command_export(cmd, ass_or_exp, is_bad, cmd_type);
	}
	if (cmd_type == E_COMMAND)
		process_command_command(cmd, ass_or_exp, is_bad, cmd_type);
	if (cmd_type == E_ANY)
	{
		process_command_any(cmd, ass_or_exp, is_bad, cmd_type);
	}
}