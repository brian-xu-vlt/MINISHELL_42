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

#define ERROR_NEWLINE	-2

#define LEXER			0
#define TOKEN			1

#define NEWLINE			"newline"
#define ERR_SYNTAX 		"syntax error : unclosed quotting expression"
#define ERR_NEWLINE 	"syntax error : missing newline"

/******************************************************************************/
/*******************************_CLEANER_**************************************/
/******************************************************************************/

#define STR_EXPORT		"export"

#define EXP_DEL_EXCEPTION "_"

#define NB_DEL			30
#define NO_ASSIGN_BUT_EXP	1
#define NB_CLEAN_COMMAND		5
#define	ALL_FREE					1
#define NOT_ALL_FREE					0
#define MALLOC							2
#define FREE_ONLY_CMD					3
#define	FILE_FAIL						2

#define IN 0
#define OUT 1

#define NO_COMMAND 2

#define TRUE_ASSIGN	1
#define TRUE_EXP	2
#define TRUE_CMD	3
#define FALSE_ASSIGN 4
#define FALSE_EXP		5
#define BACKSL_ERROR	2

#define LOW_LINE		'_'
#define QUESTION_MARK	'?'
#define S_QUESTION_MARK	"?"
#define C_BACKSLASH		'\\'
#define C_EXP			'$'

#define CONTINUE		1
#define BREAK			2

#define C_PATH			'/'

#define NUM				1<<0
#define ARG				1<<1
#define MINUS_PLUS		1<<2

#define	F_SQUOTE					1<<1
#define	F_DQUOTE					1<<2
#define	F_EXP						1<<3

#define NO_FILE						2

#define ONLY_REDIR_BEFORE			-2

#define BEFORE						0
#define AFTER						1

#define ERROR_TOKEN	"Minishell: syntax error near unexpected token `"

#define CONTINUE	1
#define BREAK		2
#define DO_NOTHING		3

/******************************************************************************/
/*******************************_BUILTIN_**************************************/
/******************************************************************************/

#define STR_PWD "pwd"
#define PWD_FAIL 2
#define PWD_SUCCESS 0
#define CD_FAIL		1
#define CD_CONTINUE		2
#define STR_CD	"cd"
#define DOTDOT	".."
#define ENV_HOME	"HOME"
#define ENV_PWD		"PWD"
#define ENV_OLD_PWD		"OLDPWD"
#define C_ROOT		'/'
#define STR_ROOT	"/"
#define PERMISSION_DENIED	13
#define OLD_PWD				0
#define PWD					1
#define STR_MINUS				"-"
#define DOT					'.'
#define C_PLUS				'+'
#define C_MINUS				'-'
#define EXIT				"exit"
#define EXIT_FAIL			1
#define S_PLUS				"+"
#define S_MINUS				"-"
#define LEN_MIN_LONG		20
#define LEN_PLUS_LONG		19
#define POP_SPACE_TAB		0
#define COUNT_NUM			1
#define STR_UNSET				"unset"
#define PWD_HOME			0
#define PWD_DIR				1
#define NOTHING				2
#define PWD_OLDPWD			3
#define INVALID_OPTION		0
#define DIR_NULL			1
#define ERR_PERMISSION		"Permission denied"
#define ERR_NOT_DIR			"Not a directory"
#define CD_BUILT			"Minishell: cd:"
#define ERR_PERMISSION_SPACE	": Permission denied"
#define ERR_NOT_DIR_SPACE		": Not a directory"
#define HOME_SET			"HOME not set"
#define OLDPWD_SET			"OLDPWD not set"
#define OLDPWD_VALUE		"OLDPWD has no value"
#define HOME_VALUE			"HOME has no value"
#define ERR_ARG				"too many arguments"
#define ERR_OPT				"invalid option"
#define ERR_USAGE 			"cd: usage: cd [-L|[-P [-e]] [-@]] [dir]"
#define ERR_CLOSE 			"closedir"
#define ERR_NUM 			"numeric argument required"
#define ERR_MANY 			"too many arguments"
#define ERR_PWD_OPT			"invalid option"
#define STR_PWD				"pwd"
#define ERR_PWD_US 			"pwd: usage: pwd [-LP]\n"
#define ERR_GET_PWD 		"pwd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory"

#define BUILTIN_ENV_FAILURE			125

#define BUILTIN_INVALID_IDENTIFIER	2
#define BUILTIN_FAILURE				1
#define BUILTIN_SUCCESS				0

#define NUMFALSE_LENZERO				0
#define PARSER_FALSE					1
#define RETLONG_TRUE					2

#define F_EXPORT_OUTPUT				1
#define F_SET_OUTPUT				2

/******************************************************************************/
/*********************************_ENV_****************************************/
/******************************************************************************/

#define SHLVL_MIN					0
#define SHLVL_MAX					1000
#define SHLVL_MAX_MESSAGE			"Minishell: warning: shell level (limited to 1000) too high, resetting to 1\n"

/******************************************************************************/
/*******************************_EXECUTOR_*************************************/
/******************************************************************************/
#define	NB_FD					3
#define	NB_BUILTIN				9
#define	NB_SIG					6
#define	NB_SIG_STR				11

#define	F_NO_REDIRECT			0
#define	F_REDIRECT_FAILURE		1<<0
#define	F_REDIRECT_IN			1<<1
#define	F_REDIRECT_OUT			1<<2
#define	F_REDIRECT_OUT_APPEND	1<<3

#define	SIG_MODE_DEFAULT				0
#define	SIG_MODE_CMD_LINE				1
#define	SIG_MODE_CMD_LINE_NO_BONUS		2
#define	SIG_MODE_EXEC					3

#define	STDFD_STORE				1
#define	STDFD_RESTORE			2

#define	ERR_INVALID_OPTION		"invalid option"
#define	ERR_NO_COMMAND			"command not found"
#define	ERR_NO_FILE				"No such file or directory"

#define	DEFAULT_PATH_ENV		"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
#define	DEFAULT_TERM			"TERM=dumb"
#define	DEFAULT_EXIT_STATUS		"?=0"

/******************************************************************************/
/***************************_EXIT ROUTINE_*************************************/
/******************************************************************************/

# define	EXIT_NORMAL					0
# define	EXIT_ENV		 			-2
# define	EXIT_NEW_VCT		 		-3
# define	EXIT_VCT		 			-4
# define	EXIT_ENVP		 			-5
# define	EXIT_SCREEN_SIZE	 		-6
# define	EXIT_TERM_NAME	 			-7
# define	EXIT_TERMCAP		 		-8
# define	EXIT_MALLOC		 			-9
# define	EXIT_FORK		 			-10
# define	EXIT_HUP			 		-11
# define	EXIT_MS_PUTCHAR	 			-12
# define	EXIT_MS_TPUTS 				-13
# define	EXIT_SHLVL_MAX 				-14
# define	EXIT_UNKNOWN 				-15

# define	NB_EXIT_CODES				14

#endif
