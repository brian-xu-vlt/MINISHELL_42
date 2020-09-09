#include "line_editor_bonus.h"

void	update_select()
{
	int		vct_index;

	vct_index = convert_cur_pos_vctindex(g_le.cx, g_le.cy);
	if (g_le.select_min == -1)
	{
		g_le.select_min = vct_index;
		g_le.select_max = vct_index;
	}
	else if (vct_index < g_le.select_min)
		g_le.select_min = vct_index;
	else if (vct_index > g_le.select_max)
		g_le.select_max = vct_index;
}

void	init_selection()
{
	g_le.select_min = -1;
	g_le.select_max = -1;
}

void		unselect_all(t_vector *command_line)
{
	init_selection();
	refresh_command_line(command_line);
}

void		line_editor(t_vector *command_line)
{
	char	buff[L_ED_BUFF_SIZE];
	int		ret;

	if (command_line == NULL)
		exit_routine_le(ERR_NEW_VCT);
	update_window_size();
	init_prompt();
	init_selection();
	ft_bzero(buff, L_ED_BUFF_SIZE);
	while((ret = read(STDIN_FILENO, buff, L_ED_BUFF_SIZE - 1)) >= 0)
	{
		update_window_size();
		if (is_shift_on(*(long *)buff) == FALSE && g_le.select_min != -1)
			unselect_all(command_line);
		if (ft_isprint(*buff) == TRUE)
			handle_print_char(buff, command_line);
		else if (*buff == K_ENTER)
			return ;
		else if (ft_isprint(*buff) == FALSE)
			handle_esc_seq(buff, command_line);
		ft_bzero(buff, L_ED_BUFF_SIZE);
		if (DEBUG == TRUE)
			debug_print_infos(command_line);
	}
}
