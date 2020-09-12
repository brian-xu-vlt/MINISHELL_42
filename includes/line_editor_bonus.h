#include <termcap.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <string.h>

#include "define_bonus.h"
#include "enum_bonus.h"
#include "lexer_bonus.h"
#include "minishell_bonus.h"
#include "struct_bonus.h"

#include <sys/ioctl.h>

#ifndef LINE_EDITOR_BONUS_H
# define LINE_EDITOR_BONUS_H

/*************************************************
				DEFINES
************************************************/

# define	GET				NULL

#ifndef L_ED_BUFF_SIZE
# define	L_ED_BUFF_SIZE	16
#endif

#ifndef DEBUG
# define	DEBUG			FALSE
#endif

#ifndef DEBUG_LLDB
# define	DEBUG_LLDB		FALSE
#endif

#ifndef LLDB
# define	DEBUG_SIGNAL	FALSE
#endif

# define	EXECUTE			1
# define	CONTINUE		0


# define	ERR_NEW_VCT		"Could not malloc vector"
# define	ERR_VCT			"Vector function failed"
# define	ERR_SCREEN_SIZE	"Screen size is too small"
# define	ERR_TERM_NAME	"Term environement variable can't be located"
# define	ERR_TERMCAP		"Termcap could not be loaded by termcap library"
# define	ERR_MALLOC		"Malloc could not allocate memory"
/*

# define	K_UP			0x1b5b41
# define	K_DOWN			0x1b5b42
# define	K_RIGHT			0x1b5b43
# define	K_LEFT			0x1b5b44

# define	K_END			0x465b1b
# define	K_HOME			0x485b1b

# define	K_SHIFT			0x313b32
# define	K_CTRL			0x313b35
# define	K_CTRL_SHIFT	0x313b36

# define	K_DEL_BACKWARD	0x7f
# define	K_DEL_FOREWARD	0x1b5b337e

# define	K_ENTER			0xa
# define	K_ESCAPE		0x1b

//# define	K_CTRL_RIGHT	0x1b5b313b5343
//# define	K_CTRL_LEFT		0x1b5b313b5344
*/


# define	K_UP			0x415b1b
# define	K_DOWN			0x425b1b
# define	K_RIGHT			0x435b1b
# define	K_LEFT			0x445b1b

# define	K_CTRL_RIGHT	0x43353b315b1b
# define	K_CTRL_LEFT		0x44353b315b1b

# define	K_END			0x465b1b
# define	K_HOME			0x485b1b

# define	K_DEL_BACKWARD	0x7f
# define	K_DEL_FOREWARD	0x7e335b1b

# define	K_ENTER			0xa
# define	K_ESCAPE		0x1b
# define	K_SHIFT			0x323b31
# define	K_CTRL			0x353b31
# define	K_CTRL_SHIFT	0x363b31


# define	PROMPT			"~$>"

# define	NB_TERMCAP		17

enum	e_termcap
{
	SAVE_CURSOR_POS,
	RESTORE_CURSOR_POS,
	CLEAR_ALL_AFTER_CURS,
	MOVE_CURSOR_HOME,
	ONE_COL_LEFT,
	ONE_COL_RIGHT,
	ONE_ROW_DOWN,
	ONE_ROW_UP,
	DELETE_ONE_CHAR,
	HIDE_CURSOR,
	VISIBLE_CURSOR,
	IN_INSERT_MODE,
	OUT_INSERT_MODE,
	SELECT,
	UNSELECT,
	MOVE_AT_COL_X,
	MOVE_X_ROWS_UP
};

/*************************************************
				TYPEDEF
************************************************/

typedef struct	s_line_editor
{
	t_vector		*clipboard;
	struct termios	termios_backup;
	char			*termcap[NB_TERMCAP];
	t_vector		*cmd_line;
	t_vector		*history;
	int				srows;
	int				scols;
	int				prompt_len;
	int				cx;
	int				cy;	
	int				vct_index;
	int				vct_index_backup;
	int				select_min;	
	int				select_max;				
}				t_le;

/*************************************************
				DEBUG
************************************************/

void		debug_print_infos(t_vector *command_line);
void		debug_print_flag(char *flag);

/*************************************************
				UTILS
************************************************/
int			is_shift_on(long buff);
int			is_ctrl_on(long buff);
int			is_ctrl_shift_on(long buff);
int         ms_putchar(int c);
void		exit_routine_le(char *err_code);
void		refresh_command_line(t_vector *command_line);
int			get_ctrlkey(int c);
t_le		*get_env(t_le *env);
void		insert_char_in_vct(t_vector *command_line, char c);

/*************************************************
				HANDLERS
************************************************/

int			handle_esc_seq(char buff, t_vector *command_line);
void		handle_print_char(char buff, t_vector *command_line);

void		move_end_of_line(t_vector *command_line);
void		move_start_of_line(void);
void		move_one_word_right(t_vector *command_line);
void		move_one_word_left(t_vector *command_line);

void		delete_selection(t_vector *command_line, long key);
void		copy_selection(t_vector *command_line);
void		past_clipboard(t_vector *command_line);
void		cut_selection(t_vector *command_line);

void		call_history(long buff);

/*************************************************
				SELECTION
************************************************/

void		init_selection(void);
void		unselect_all();
void		update_selection(t_vector *command_line, long buff);

/*************************************************
				CURSOR
************************************************/

size_t		convert_cur_pos_vctindex(int cx, int cy);

int			move_cursor_right(t_vector *command_line);
int			move_cursor_left(void);
int			move_cursor_at_startingpoint();
void		move_cursor_at_index(t_vector *command_line, int target_index);

/*************************************************
				INIT FUNCTIONS
************************************************/
void		init_prompt(void);
void		init_term_mode(void);
void		init_minishell(void);

void		update_window_size(void);

/*************************************************
				MAIN FUNCTIONS
************************************************/
void		line_editor(t_vector *command_line);

#endif
