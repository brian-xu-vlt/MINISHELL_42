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
	clean_cmd->index_redir = 0;
	clean_cmd->count_redir = 0;
	clean_cmd->tab_redir = NULL;
	clean_cmd->tmp_tab_redir = NULL;
	clean_cmd->tmp_av = NULL;
	return (clean_cmd);
}

static int	process_command_any(t_cmd *cmd, int ass_or_exp, bool is_bad,
								enum e_cmd cmd_type)
{
	ft_printf("PROCESS COMMAND ANY\n");
	if (is_bad == false)
		ft_printf("EXPORT POP ENV ET ASSIGN\n");
	//POP DANS ENV ET ASSIGN
	else if (is_bad = true)
		ft_printf("POP ENV CELUI FAUX\n");
	//POP SAUF CELUI FAUX
}

static int process_command_command(t_cmd *cmd, int ass_or_exp, bool is_bad,
									enum e_cmd cmd_type)
{
	//SI LA COMMANDE EN QUESTION EST UNSET -->> ASS_OR_EXP = FALSE
	ft_printf("PROCESS COMMAND COMMAND\n");
}

static int process_command_export(t_cmd *cmd, int ass_or_exp, bool is_bad,
								   enum e_cmd cmd_type)
{
	t_clean_cmd	*clean_cmd;

	ft_printf("PROCESS COMMAND EXPORT\n");
	iter_clean_quote(cmd, (size_t)cmd->ac);
	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE);
		return (FAILURE);
	}
	count_ac_assign(cmd, clean_cmd, is_bad);
	clean_cmd->ac = cmd->ac - clean_cmd->count_assign;
	if (init_tab_assign_ac(clean_cmd, cmd) == FAILURE)
	{
		free_clean_command(clean_cmd, ALL_FREE);
		return (FAILURE);
	}
	if (fill_clean_cmd(cmd, clean_cmd) == FAILURE)
	{
		free_clean_command(clean_cmd, ALL_FREE);
		return (FAILURE);
	}
	if (process_redirection(cmd, clean_cmd) == FAILURE)
	{
		return (FAILURE);
	}
	free_clean_command(clean_cmd, ALL_FREE);
	return (SUCCESS);
}

int process_clean_command(t_cmd *cmd, int ass_or_exp, bool is_bad,
						  enum e_cmd cmd_type)
{
	//COMPARER CHAQUE IF AVEC LES INDEXS DE OU SE TROUVE LES ASSIGN
	// + revoir les diff printf
	if (cmd_type == E_EXPORT_EXEC || cmd_type == E_EXPORT_NO_EXEC)
	{
		if (process_command_export(cmd, ass_or_exp, is_bad, cmd_type) == FAILURE)
			return (FAILURE);
	}
	if (cmd_type == E_COMMAND)
	{
		if (process_command_command(cmd, ass_or_exp, is_bad, cmd_type) == FAILURE)
			return (FAILURE);
	}
	if (cmd_type == E_ANY)
	{
		if (process_command_any(cmd, ass_or_exp, is_bad, cmd_type) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}