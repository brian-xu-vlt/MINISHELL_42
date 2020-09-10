#include "line_editor_bonus.h"

void	update_select(t_vector *command_line, long buff)
{
	int		vct_index;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	if (vct_index == 0 || vct_index == (int)vct_getlen(command_line))
		return ;
	if (le->select_min == -1)
	{
		le->select_min = vct_index - ((buff == K_RIGHT) ? 1 : 0);
		le->select_max = vct_index + ((buff == K_LEFT) ? 1 : 0);
	}
	else if (vct_index < le->select_min && vct_index < le->select_max)
		le->select_min = vct_index;
	else if (vct_index > le->select_min && vct_index > le->select_max)
		le->select_max = vct_index;
	else if (buff == K_LEFT && vct_index >= le->select_min && vct_index < le->select_max)
		le->select_max = vct_index;
	else if (buff == K_RIGHT && vct_index > le->select_min && vct_index <= le->select_max)
		le->select_min = vct_index;
}

void	init_selection()
{
	t_le *le;

	le = get_env(GET);
	le->select_min = -1;
	le->select_max = -1;
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
		if (is_shift_on(*((long *)buff)) == FALSE && get_env(GET)->select_min != -1)
			unselect_all(command_line);
		if (ft_isprint(*buff) == TRUE)
			handle_print_char(buff, command_line);
		else if (*buff == K_ENTER)
			return ;
		else if (ft_isprint(*buff) == FALSE)
			handle_esc_seq(*(long *)buff, command_line);
		ft_bzero(buff, L_ED_BUFF_SIZE);
		if (DEBUG == TRUE)
			debug_print_infos(command_line);
	}
}
