/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:21:12 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:21:18 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

/******************************************************************************/
/*******************************_LEXER_****************************************/
/******************************************************************************/

t_list					*lexer(t_vector *input);
size_t					get_token(char c);
ssize_t					get_double_token(t_vector *input);
void					free_list_token(t_list **token);
int						extract_token(t_list **token_list, char *str,
										size_t type);
void					exit_routine_lexer(t_vector *word, t_vector *vct,
											t_vector *tmp, t_token *token);
int						handle_assign_quote(t_vector *in, t_vector *word);
int						quote_checker(char *str);
bool					is_simplequote(t_vector *input);
typedef	enum e_state	(*t_state)(t_vector *);
bool					is_doublequote(t_vector *input);
bool					is_end(t_vector *input);
int						extract_token_word(t_list **token_list, t_vector *vct);
char					*handle_bracket(char *str, t_list **token_list);
void					free_list_token(t_list **token);
const char				*get_token_str(const int type);
char					*get_data(int type);
void					free_token(t_list *node, t_token *token);
int						handle_ret_lexer(int ret_process_lexer,
											t_list *token_list, t_vector *word,
											int flag);
t_list					*get_job(t_list *job);
int						no_word(t_list **token_list, t_vector *word,
									size_t type);
bool					stop_assign_char(char c);
bool					stop_assign_str(t_vector *input);
int						is_newline_error(bool dquote_state, bool quote_state,
											t_vector *input);
int						backsl_quote(bool quote_state, bool dquote_state,
										t_vector *input, t_vector *word);
int						handle_quote(char c, bool quote_state,
										bool dquote_state, t_vector *input);
int						backslash(char c, t_vector *word, t_vector *input,
									char next_c);
bool					parse_backslash(t_vector *input, t_vector *word, bool
									is_quoting);
void					pop_input_word(t_vector *input, t_vector *word);

#endif
