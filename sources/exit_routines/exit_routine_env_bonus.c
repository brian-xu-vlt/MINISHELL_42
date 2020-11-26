#include "line_editor_bonus.h"

void		exit_routine_env(void)
{
	t_list		*env_lst;

	env_lst = get_env_list(GET);
	if (env_lst != NULL)
		free_env_list(env_lst);
}
