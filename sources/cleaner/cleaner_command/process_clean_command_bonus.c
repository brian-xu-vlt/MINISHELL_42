#include "minishell_bonus.h"

t_clean_cmd	*init_clean_command()
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
	clean_cmd->tmp_fd_in = 0;
	clean_cmd->count_other = 0;
	clean_cmd->tmp_fd_out = 1;
	clean_cmd->tmp_fd_append = 1;
	return (clean_cmd);
}

/*static int			process_command_any(t_cmd *cmd, int ass_or_exp, bool is_bad,
								enum e_cmd cmd_type)
{
	ft_printf("PROCESS COMMAND ANY\n");
	if (is_bad == false)
		ft_printf("EXPORT POP ENV ET ASSIGN\n");
	//POP DANS ENV ET ASSIGN
	else
		ft_printf("POP ENV CELUI FAUX\n");
	//POP SAUF CELUI FAUX
	return(SUCCESS);
}*/

static int			process_command_command(t_cmd *cmd/*, int ass_or_exp,
												bool is_bad,
												enum e_cmd cmd_type*/)
{
	t_clean_cmd *clean_cmd;
	int			ret;
	int			index_cmd;

	clean_cmd = init_clean_command();
	ret = SUCCESS;
	ft_printf("PROCESS COMMAND COMMAND\n");
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE);
		return (FAILURE);
	}
	index_cmd = get_cmd(cmd, clean_cmd);
	ft_printf("INDEX_CMD = %d\n", index_cmd);//DEBUG
	iter_clean_quote(cmd, (size_t)cmd->ac);
	if (get_envp_av(cmd, clean_cmd, index_cmd) == FAILURE)
		return (FAILURE);
	process_redirection(cmd, clean_cmd);
	return(SUCCESS);
}


/*static int 			process_command_export(t_cmd *cmd, bool is_bad,
											enum e_cmd cmd_type)
{
	t_clean_cmd *clean_cmd;
	int ret_redirection;
	int	ret;

	ft_printf("PROCESS COMMAND EXPORT\n");//DEBUG
	iter_clean_quote(cmd, (size_t)cmd->ac);
	clean_cmd = init_clean_command();
	ret = SUCCESS;
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE);
		return (FAILURE);
	}
	count_ac_assign(cmd, clean_cmd, is_bad);
	ft_printf("count_assign = %d\n", clean_cmd->count_assign);//DEBUG
	ft_printf("count_other = %d\n", clean_cmd->count_other);//DEBUG
	clean_cmd->ac = cmd->ac - clean_cmd->count_assign - clean_cmd->count_other;
	ft_printf("ac = %d\n", clean_cmd->ac);//DEBUG
	ret = init_tab_assign_ac(clean_cmd, cmd);
	if (ret != FAILURE)
	{
		ret = fill_clean_cmd(cmd, clean_cmd);
		//if (ret != FAILURE)
		//	ret = clean_av_len(cmd, clean_cmd);
		if (ret != FAILURE)
			ret = process_redirection(cmd, clean_cmd);
	}
	free_clean_command(clean_cmd, ALL_FREE);
	return (ret);
}*/

int 				process_clean_command(t_cmd *cmd/*, int ass_or_exp,
											bool is_bad, enum e_cmd cmd_type*/)
{
	//COMPARER CHAQUE IF AVEC LES INDEXS DE OU SE TROUVE LES ASSIGN
	// + revoir les diff printf
	//if (cmd_type == E_EXPORT_EXEC || cmd_type == E_EXPORT_NO_EXEC)
		return (process_command_command(cmd/*, ass_or_exp, is_bad, cmd_type*/));
//	if (cmd_type == E_COMMAND)
//		return (process_command_command(cmd, ass_or_exp, is_bad, cmd_type));
////	if (cmd_type == E_ANY)
//		return (process_command_any(cmd, ass_or_exp, is_bad, cmd_type));
	//return (SUCCESS);
}