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
	E_GREATER_THAN,//5
	E_SPACE,//6
	E_TAB,//7
	E_DOUBLE_GREATER,//8
	E_OR,//9
	E_AND,//10
	E_WORD,//11
	E_EXP,//12
	E_ASSIGN,//13
	E_START,//14
	E_END,//15
	NO_TYPE//16
};

#endif