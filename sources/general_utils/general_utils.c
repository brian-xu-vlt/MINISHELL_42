#include "minishell.h"

void	free_char_arr(char **arr)
{
	int				i;

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
	return ((ft_strchr((char *)bin_name, C_PATH) == NOT_FOUND) ? FALSE : TRUE);
}

t_data	*get_data_struct(t_data *mem)
{
	static t_data	*mem_backup = NULL;

	if (mem != GET)
		mem_backup = mem;
	return (mem_backup);
}
