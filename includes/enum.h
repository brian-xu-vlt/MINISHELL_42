/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:02:12 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 19:02:13 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum	e_state
{
	E_STATE_STRING,
	E_STATE_SQUOTE,
	E_STATE_DQUOTE,
	E_STATE_END,
	E_STATE_ERROR
};

enum	e_token_type
{
	E_SEPARATOR,
	E_PIPE,
	E_SIMPLE_QUOTE,
	E_QUOTE,
	E_LESS_THAN,
	E_GREATER_THAN,
	E_SPACE,
	E_TAB,
	E_DOUBLE_GREATER,
	E_OR,
	E_AND,
	E_WORD,
	E_EXP,
	E_ASSIGN,
	E_START,
	E_END,
	NO_TYPE
};

enum	e_condition_type
{
	E_NONE,
	E_NOT_OR,
	E_YES_AND
};

enum	e_cmd_type
{
	E_CMD_ASSIGN,
	E_CMD_S_REDIRECTION,
	E_CMD_D_REDIRECTION,
	E_CMD_AV
};

# define RESIZE	4

enum	e_state_quote_no_exp
{
	E_IN_SIMPLE_QUOTE,
	E_IN_DOUBLE_QUOTE,
	E_OUT
};

enum	e_between
{
	E_NOTHING,
	E_SIMPLE,
	E_DOUBLE,
	E_BOTH
};

enum	e_cmd
{
	E_ANY,
	E_EXPORT_EXEC,
	E_EXPORT_NO_EXEC,
	E_COMMAND
};

enum	e_state_redir
{
	E_IN_REDIR,
	E_IN_FILE,
	E_IN_OUT
};

#endif
