#include "line_editor_bonus.h"

static t_vector	*history(long flag)
{
	static int	i;
	static 		t_vector *history_stock[9];

	if (history_stock[0] == NULL)
	{
		while (i <= 9)
		{
			history_stock[i] = vct_new();
			vct_add(history_stock[i], i + '0');
			i++;
		}	
		i = 0;
	}
	if (i == 0 && flag == K_DOWN)
		return (NULL);
	else if (i == 9 && flag == K_UP)
		i = 9;
	else if (flag == K_UP) 
		i++;
	else if (flag == K_DOWN) 
		i--;
	return (history_stock[i]);
}

void			call_history(long buff)
{
	t_le *le;

	le = get_env(GET);
	le->vct_history = history(buff);	
}
