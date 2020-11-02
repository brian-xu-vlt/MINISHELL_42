#include "minishell_bonus.h"

bool is_wrong_ass(t_vector *vct)
{
	if (ft_isdigit(vct_getfirstchar(vct)) == TRUE)
		return (false);
	if (is_wrong_char(vct) == true)
		return (false);
	return (true);
}