#include "minishell_bonus.h"

bool	stop_assign_str(t_vector *input)
{
	t_vector *cpy_input;

	cpy_input = input;
	vct_pop(cpy_input);
	//printf("len = %zu\n", vct_getlen(cpy_input));//DEBUG
	vct_cutfrom(cpy_input, vct_getlen(cpy_input) - 2);
	//ft_printf("CPY_INPUT = %s\n", vct_getstr(cpy_input));//DEBUG
	return (ft_strequ(vct_getstr(cpy_input), OR) == TRUE
				|| ft_strequ(vct_getstr(cpy_input), AND) == TRUE
				|| ft_strequ(vct_getstr(cpy_input), DOUBLE_GREATER) == TRUE ?
				true : false);
				
}

bool	stop_assign_char(char c)
{
	//ft_printf("C ============================== '%c'\n", c);//DEBUG
	return (c == C_SEPARATOR || c == C_PIPE || c == C_LESS_THAN
				|| c == C_GREATER_THAN || c == C_SPACE ? true : false);
}

int	handle_assign_quote(t_vector **input, t_vector **word)
{
	int	quote_open;
	int	quote_close;
	int	simple_quote_open;
	int	simple_quote_close;
	int	count_loop;
	t_vector	*cpy_input;
	int	no_error;

//	ft_printf("input MAIN= %s\n", vct_getstr(*input));//DEBUG
//	ft_printf("word MAIN= %s\n", vct_getstr(*word));//DEBUG
	quote_open = FALSE;
	quote_close = FALSE;
	simple_quote_open = FALSE;
	simple_quote_close = FALSE;
	count_loop = 0;
	vct_add(*word, vct_getfirstchar(*input));	
	vct_pop(*input);
	no_error = FALSE;
	while (vct_getlen(*input) > 0)
	{
		cpy_input = vct_dup(*input);
		//ft_printf("input MAIN %d = %s\n", count_loop, vct_getstr(*input));//DEBUG
		//ft_printf("word MAIN= %s\n", vct_getstr(*word));//DEBUG
		//ft_printf("COUNT LOOP = %d\n", count_loop);//DEBUG
		//ft_printf("QUOTE CLOSE = %d\n", quote_close);//DEBUG
		//ft_printf("SIMPLE QUOTE CLOSE = %d\n", simple_quote_close);//DEBUG
		if (count_loop != 0 && (stop_assign_char(vct_getcharat(*input, 1)) == true
				|| stop_assign_str(cpy_input) == true) && quote_close == FALSE
				&& simple_quote_close == FALSE)
		{
			//ft_printf("STOP_ASSIGN\n");//DEBUG
			vct_add(*word, vct_getfirstchar(*input));	
			//ft_printf("word MAIN= %s\n", vct_getstr(*word));//DEBUG
			no_error = TRUE;
			break ;
		}	
		if (quote_open == FALSE && vct_getfirstchar(*input) == C_QUOTE)
		{
			//ft_printf("QUOTE_OPEN TRUE\n");//DEBUG
			quote_open = TRUE;	
		}
		else if (quote_open == TRUE && vct_getfirstchar(*input) == C_QUOTE)
		{
			//ft_printf("QUOTE_CLOSE TRUE\n");//DEBUG
			quote_close = TRUE;
		}
		if (quote_close == TRUE && quote_open == TRUE)
		{
			//ft_printf("QUOTE_OPEN FALSE\n");//DEBUG
			//ft_printf("QUOTE_CLOSE FALSE\n");//DEBUG
			quote_close = FALSE;
			quote_open = FALSE;
		}
		if (simple_quote_open == FALSE && vct_getfirstchar(*input) == C_SIMPLE_QUOTE)
		{
			//ft_printf("SIMPLE_QUOTE_OPEN TRUE\n");//DEBUG
			simple_quote_open = TRUE;	
		}
		else if (simple_quote_open == TRUE && vct_getfirstchar(*input) == C_SIMPLE_QUOTE)
		{
			//ft_printf("SIMPLE_QUOTE_CLOSE TRUE\n");//DEBUG
			simple_quote_close = TRUE;
		}
		if (simple_quote_close == TRUE && simple_quote_open == TRUE)
		{
			//ft_printf("SIMPLE_QUOTE_CLOSE FALSE\n");//DEBUG
			//ft_printf("SIMPLE_QUOTE_OPEN FALSE\n");//DEBUG
			simple_quote_close = FALSE;
			simple_quote_open = FALSE;
		}
		count_loop++;
		vct_add(*word, vct_getfirstchar(*input));	
		vct_pop(*input);
	}
	/*ft_printf("QUOTE_OPEN END = %d\n", quote_open);//DEBUG
	ft_printf("QUOTE_CLOSE END = %d\n", quote_close);//DEBUG
	ft_printf("SIMPLE_QUOTE_OPEN END = %d\n", simple_quote_open);//DEBUG
	ft_printf("SIMPLE_QUOTE_CLOSE END = %d\n", simple_quote_close);//DEBUG*/
	if ((quote_open == TRUE || simple_quote_open == TRUE) && no_error != TRUE)
	{
		ft_printf("ERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRROR\n");//DEBUG
		return (FAILURE);
	}
	return (SUCCESS);
}
