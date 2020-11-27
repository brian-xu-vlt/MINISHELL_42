#include "minishell_bonus.h"

void	exit_error(t_vector *vct_av, char *av, char c, int flag)
{
	if (flag == NUMFALSE_LENZERO)
		ms_setenv_int(get_env_list(GET), "?",
						print_error(vct_av, av, c, MINUS_PLUS | NUM),
													F_OVERWRITE);
	if (flag == PARSER_FALSE)
		ms_setenv_int(get_env_list(GET), "?", print_error(vct_av, av, c, NUM),
						F_OVERWRITE);
	if (flag == RETLONG_TRUE)
		ms_setenv_int(get_env_list(GET), "?", print_error(vct_av, av, c, NUM),
						F_OVERWRITE);
	exit_routine(EXIT_NORMAL);
}
