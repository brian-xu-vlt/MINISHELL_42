#include "line_editor_bonus.h"

void	cut_selection(t_vector *command_line)
{
	copy_selection(command_line);
	delete_selection(command_line, 0);
}
