#include "minishell_bonus.h"

void		init_env(char **env)
{
	int		index;

	if (env == NULL)
		return ;
	index = 0;
	while (env[index] != NULL)
	{
		store_env(env[index]);
		index++;
	}
}








/*

invalid names:
- contain '-'
- first char is numeric

env: show exported var WITH VALUE
export: show exported var with AND without value + sorted alphabeticly


- export test="42" valid, so need to stripoff quotes

toto=42'0'
toto='0'
toto'0'


*/

/*
void		remove_quotes(char **env)
{
	int			i;
	int			env_len;
	char		c;
	t_vector	tmp_env;

	tmp_env = vct_new();
	vct_add(tmp_env, env);
	env_len = vct_getlen(tmp_env);
	i = 0;
	while (i <= env_len)
	{
		c = vct_getcharat(tmp_vct, i);
		if (c == '\"' || c == '\'')
			vct_popcharat(tmp_vct, i);
		i++;
	}

}
*/


