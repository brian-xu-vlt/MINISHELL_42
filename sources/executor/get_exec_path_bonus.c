#include "minishell_bonus.h"

static char		*create_full_path(const char *dir, const char *bin_name)
{
	size_t	len_dir;
	size_t	len_name;
	char  	*full_path;

	len_dir = ft_strlen(dir);
	len_name = ft_strlen(bin_name);
	full_path = (char *)ft_calloc(len_dir + len_name + 3, sizeof(char));
	if (full_path == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memcpy(full_path, dir, len_dir);
	ft_memcpy(full_path + len_dir, "/", 1);
	ft_memcpy(full_path + len_dir + 1, bin_name, len_name);
	return (full_path);
}

char		**get_all_path_directories(void)
{
	char	*path_env;

	path_env = vct_getstr(get_env_value_vct(get_env_list(GET), "PATH"));
	if (path_env == NOT_FOUND)
		return (NULL);
	else
		return (ft_split(path_env, ':'));
}

int		is_absolute_path(const char *bin_name)
{
	return ((ft_strchr((char *)bin_name, '/') == NOT_FOUND) ? FALSE : TRUE);
}

char	*get_exec_path(char *dir, const char *name)
{
	if (dir != NULL)
		return (create_full_path(dir, name));
	return (NULL);
}

