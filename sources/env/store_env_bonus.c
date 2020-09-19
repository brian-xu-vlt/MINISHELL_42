#include "line_editor_bonus.h"

static void	store_new_env(char *env_name, char *env_value)
{
	int			ret;
	t_vector	*new_content;
	t_list		*new_elem;
	t_list		*env;

	new_content = vct_new();
	new_elem = ft_lstnew(new_content);
	if (new_elem == NULL || new_content == NULL)
		exit_routine_le(ERR_MALLOC);
	ret = 0;
	ret += vct_addstr(new_content, env_name);
	ret += vct_add(new_content, '=');
	ret += vct_addstr(new_content, env_value);
	if (ret != SUCCESS * 3)
		exit_routine_le(ERR_MALLOC);
	env = get_struct(GET)->env;
	if (env != NULL)
		ft_lstadd_back(&env, new_elem);
	else
		env = new_elem;
}

static void	update_existing_env(t_vector *env_vct, char *env_value)
{
	size_t		value_startingpoint;

	value_startingpoint = vct_chr(env_vct, '=') + 1;
	if (value_startingpoint > 0)
	{
		vct_cutfrom(env_vct, vct_getlen(env_vct) - value_startingpoint);
		vct_addstrat(env_vct, value_startingpoint, env_value);
	}
}

void		store_env(char *env_name, char *env_value)
{
	t_vector	*env_vct;

	if (env_name == NULL || env_value == NULL)
		return ;
	if ((env_vct = get_env(env_name)) == NOT_FOUND)
		store_new_env(env_name, env_value);
	else
		update_existing_env(env_vct, env_value);
}
