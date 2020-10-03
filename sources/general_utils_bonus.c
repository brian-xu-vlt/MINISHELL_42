#include "minishell_bonus.h"

void	free_char_ptr_arr(char **ptr_arr)
{
	int		i;

	i = 0;
	if (ptr_arr == NULL)
		return ;
	while (ptr_arr[i] != NULL)
		free(ptr_arr[i++]);
	free(ptr_arr);
}

