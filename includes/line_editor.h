/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:02:19 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 19:02:20 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_H
# define LINE_EDITOR_H

# ifndef DEBUG_MODE
#  define DEBUG_MODE FALSE
# endif

# ifndef DEBUG_LLDB
#  define DEBUG_LLDB FALSE
# endif

# ifndef LLDB
#  define DEBUG_SIGNAL FALSE
# endif

/*
*********     UTILS     ***********
*/

# define GET					NULL
# define UNSET					-1
# define RESET					-1

/*
*********  SCREEN  FLAG ***********
*/

# define FULL_REFRESH			0x000001
# define HISTORY_REFRESH		0x000002
# define RESIZE_REFRESH			0x000004

/*
*********  USER KEYS  *************
*/

# define K_EOF					4
# define K_TAB					9
# define K_UP					0x415b1b
# define K_DOWN					0x425b1b
# define K_RIGHT				0x435b1b
# define K_LEFT					0x445b1b
# define K_CTRL_RIGHT			0x43353b315b1b
# define K_CTRL_LEFT			0x44353b315b1b
# define K_END					0x465b1b
# define K_HOME					0x485b1b
# define K_DEL_BACKWARD			0x7f
# define K_DEL_FOREWARD			0x7e335b1b
# define K_ENTER				0xa

# define K_ESCAPE				0x1b
# define K_SHIFT				0x323b31
# define K_CTRL					0x353b31
# define K_CTRL_SHIFT			0x363b31

# define CTRL_MASK				0x000001
# define SHIFT_MASK				0x000002

# define PROMPT_SIMPLE			"NO_LINE_ED~$>"
# define PROMPT_LINE_EDITION	"LINE_EDITION~$>"

/*
*********  DEBUG TERMCAPS *********
*/

# define HIGHLIGHT				"md"
# define NO_HIGHLIGHT			"me"
# define SAVE_CURSOR_POS		"sc"
# define RESTORE_CURSOR_POS		"rc"

/*
*****  LINE EDITOR TERNCAPS ******
*/

# define NB_ESSENTIAL_TERMCAP	12
# define NB_OPTIONAL_TERMCAP	4

enum	e_essential_termcap
{
	CLEAR_LINE,
	CLEAR_ALL_AFTER_CURS,
	SELECT,
	UNSELECT,
	MOVE_CURSOR_HOME,
	ONE_COL_LEFT,
	ONE_COL_RIGHT,
	ONE_ROW_DOWN,
	ONE_ROW_UP,
	MOVE_X_ROWS_UP,
	CURSOR_POSITION_REQUEST,
	RETURN_CARRIAGE
};

enum	e_optional_termcap
{
	MOVE_AT_COL_X = NB_ESSENTIAL_TERMCAP,
	VISIBLE_CURSOR,
	HIDE_CURSOR,
	SCROLLING_CAPABILITY
};

/*
**				TYPEDEF
*/

typedef struct		s_line_editor
{
	int		coucou;
}					t_le;

/*
**				MAIN FUNCTIONS
*/
int					line_editor(void);

#endif
