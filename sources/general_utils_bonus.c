#include "minishell_bonus.h"

void		free_char_arr(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

int		is_path(const char *bin_name)
{
	if (bin_name == NULL)
		return (false);
	return ((ft_strchr((char *)bin_name, '/') == NOT_FOUND) ? FALSE : TRUE);
}
