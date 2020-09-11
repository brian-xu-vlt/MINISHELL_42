#include "line_editor_bonus.h"

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
		if (*buff == K_ENTER)
		{
			unselect_all(command_line);
			move_cursor_at_index(command_line, vct_getlen(command_line));
			return ;
		}
		else if (ft_isprint(*buff) == FALSE)
			handle_esc_seq(*(long *)buff, command_line);
		else if (ft_isprint(*buff) == TRUE)
			handle_print_char(buff[0], command_line);
		ft_bzero(buff, L_ED_BUFF_SIZE);
		if (DEBUG == TRUE)
			debug_print_infos(command_line);
	}
}
