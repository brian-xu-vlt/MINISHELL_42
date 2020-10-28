#ifndef DEFINE_H
# define DEFINE_H

/******************************************************************************/
/*******************************_LEXER_****************************************/
/******************************************************************************/

#define SEPARATOR		";"//0
#define PIPE			"|"//1
#define SIMPLE_QUOTE	"'"//2
#define QUOTE			"\""//3
#define LESS_THAN		"<"//4
#define GREATER_THAN	">"//5
#define	SPACE			" "//6
#define TAB				"\t"//7
#define DOUBLE_GREATER	">>"//8
#define OR				"||"//9
#define AND				"&&"//10
#define EXP				'$'//12
#define ASSIGN			'='//13

#define S_WORD			"WORD"
#define S_EXP			"$"
#define S_ASSIGN		"="
#define S_START			"START"
#define S_END				"END"
#define S_NO_TYPE			"NO_TYPE"

#define C_SEPARATOR			';'//0
#define C_PIPE				'|'//1
#define C_SIMPLE_QUOTE		'\''//2
#define C_QUOTE				'\"'//3
#define C_LESS_THAN			'<'//4
#define C_GREATER_THAN		'>'//5
#define	C_SPACE				' '//6
#define C_TAB				'\t'//7

#define GRAMMAR			";|'\"<> \t"

#define	NB_GRAMMAR		8
#define DOUBLE_TOKEN	7
#define EXP_ASSIGN		11
#define FIRST_CHAR		0

#define N_SIMPLE_QUOTE	1
#define N_QUOTE			2

#define NB_FD			3
	
#define NB_FD			3

/******************************************************************************/
/*******************************_EXECUTOR_*************************************/
/******************************************************************************/

#define	F_REDIRECT_FAILURE		1<<0	
#define	F_REDIRECT_IN			1<<1
#define	F_REDIRECT_OUT			1<<2

#define SIG_MODE_NORMAL			0
#define SIG_MODE_LINE_EDITOR	1
#define SIG_MODE_EXEC			2


#define	ERR_NO_COMMAND		"command not found"
#define	ERR_NO_FILE			"No such file or directory"

#define DEFAULT_PATH_ENV	"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

#endif
