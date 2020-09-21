#include "line_editor_bonus.h"

void	init_term_mode(void)
{
	struct termios	termios_new;
	t_le			*le;

	le = get_struct(GET);
	tcgetattr(STDIN_FILENO, &(le->termios_backup));
	termios_new = le->termios_backup;
	termios_new.c_lflag &= ~(ICANON);
	termios_new.c_lflag &= ~(ECHO);
	if (DEBUG_SIGNAL != FALSE)
		termios_new.c_lflag |= ~(ISIG);
	termios_new.c_cc[VMIN] = 1;
	termios_new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_new);
}
