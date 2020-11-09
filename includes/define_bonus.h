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
#define C_EXPORT			'$'

#define GRAMMAR			";|'\"<> \t"

#define	NB_GRAMMAR		8
#define DOUBLE_TOKEN	7
#define EXP_ASSIGN		11
#define FIRST_CHAR		0

#define N_SIMPLE_QUOTE	1
#define N_QUOTE			

/******************************************************************************/
/*******************************_CLEANER_**************************************/
/******************************************************************************/

#define STR_EXPORT		"export"
#define DEL				"`~!@#$%^&*()_-+={}[]:,.?/'\" \t"


#define NB_DEL			29
#define NO_ASSIGN_BUT_EXP	1	
#define NB_CLEAN_COMMAND		5
#define	ALL_FREE					1
#define NOT_ALL_FREE					0
#define	FILE_FAIL						2

#define IN 0
#define OUT 1

#define NO_COMMAND 2

#define TRUE_ASSIGN	1
#define TRUE_EXP	2
#define TRUE_CMD	3
#define FALSE_ASSIGN 4
#define FALSE_EXP		5

/******************************************************************************/
/*******************************_BUILTIN_**************************************/
/******************************************************************************/

#define STR_PWD "pwd"
#define PWD_FAIL 1
#define PWD_SUCCESS 0


/******************************************************************************/
/*******************************_EXECUTOR_*************************************/
/******************************************************************************/
#define NB_FD			3

#define	F_NO_REDIRECT			0	
#define	F_REDIRECT_FAILURE		1<<0	
#define	F_REDIRECT_IN			1<<1
#define	F_REDIRECT_OUT			1<<2
#define	F_REDIRECT_OUT_APPEND	1<<3

#define SIG_MODE_DEFAULT		0
#define SIG_MODE_CMD_LINE		1
#define SIG_MODE_EXEC			2

#define STDFD_STORE             1
#define STDFD_RESTORE           2

#define	ERR_NO_COMMAND		"command not found"
#define	ERR_NO_FILE			"No such file or directory"

#define DEFAULT_PATH_ENV	"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

#endif
