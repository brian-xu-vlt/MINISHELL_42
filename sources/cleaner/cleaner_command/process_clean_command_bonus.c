#include "minishell_bonus.h"

int	process_clean_command(t_cmd *cmd, int ass_or_exp, bool is_bad,
							enum e_cmd cmd_type)
{
	//COMPARER CHAQUE IF AVEC LES INDEXS DE OU SE TROUVE LES ASSIGN
	// + revoir les diff printf
	if (cmd_type == E_EXPORT_EXEC || cmd_type == E_EXPORT_NO_EXEC)
	{
		if (cmd->count_assign != 0 && is_bad == false)
			ft_printf("EXPORT POP ENV\n");
		else if (cmd->count_assign != 0 && is_bad == true)
			ft_printf("EXPORT POP PAS ENV\n");
			//POP ET PAS ENV
	}
	if (cmd_type == E_COMMAND && is_bad == false)
			ft_printf("EXPORT POP MAIS PAS DANS ENV\n");
		//POP MAIS PAS DANS ENV
	if (cmd_type == E_ANY)
	{
		if (is_bad == false)
			ft_printf("EXPORT POP ENV ET ASSIGN\n");
			//POP DANS ENV ET ASSIGN
		else if (is_bad = true)
			ft_printf("POP ENV CELUI FAUX\n");
			//POP SAUF CELUI FAUX
	}
}