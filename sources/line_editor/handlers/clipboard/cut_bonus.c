#include "line_editor_bonus.h"

void	cut_selection(void)
{
	copy_selection();
	delete_selection(0);
}
