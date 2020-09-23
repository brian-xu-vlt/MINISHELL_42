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

