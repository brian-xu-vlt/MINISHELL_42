#ifndef ENUM_BONUS_H
# define ENUM_BONUS_H

/******************************************************************************/
/*******************************_TOKEN_****************************************/
/******************************************************************************/

enum e_token_type
{
	E_SEPARATOR,//0
	E_PIPE,//1
	E_SIMPLE_QUOTE,//2
	E_QUOTE,//3
	E_LESS_THAN,//4
	E_DOUBLE_GREATER,//5
	E_GREATER_THAN,//6
	E_ASSIGN,//7
	E_VAR,//8
	E_SPACE,//9
	E_TAB,//10
	E_WORD//11
};

#endif
