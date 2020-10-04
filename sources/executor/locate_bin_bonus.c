#include "minishell_bonus.h"

static char		**get_all_path_directories(void)
{
	char	*path_env;

	path_env = vct_getstr(get_env_value_vct("PATH"));
	if (path_env == NOT_FOUND)
		return (NULL);
	else
		return (ft_split(path_env, ':'));
}

static int		go_through_single_dir(DIR *dir_stream, const char *bin_name)
{
	struct dirent	*cursor_file;

	cursor_file = readdir(dir_stream);
	while (cursor_file != NULL)
	{
		if (ft_strequ(cursor_file->d_name, (char *)bin_name) == TRUE)
			return (TRUE);
		cursor_file = readdir(dir_stream);
	}
	return (FALSE);
}

static int		find_binary_in_a_dir(char *directory, const char *bin_name)
{
	int				ret;
	DIR				*dir_stream;

	ret = FALSE;
	dir_stream = opendir(directory);
	if (dir_stream == NULL)
		return (FALSE);
	ret = go_through_single_dir(dir_stream, bin_name);
	closedir(dir_stream);
	return (ret);
}

/*
static char		*find_binary_in_pwd(const char *bin_name)
{
	char	*pwd;

	pwd = vct_getstr(get_env_value_vct("PWD"));
	if (pwd != NOT_FOUND && find_binary_in_a_dir(pwd, bin_name) == TRUE)
		return (ft_strdup(pwd));
	return (NOT_FOUND);
}
*/

char		*locate_binary_file(const char *bin_name)
{
	char	**dir_options;
	char	*ret_dir;
	int		i;

	ret_dir = NOT_FOUND;
	dir_options = get_all_path_directories();
	if (dir_options == NULL || dir_options[0] == NULL)
		return (NOT_FOUND);
	i = 0;
	while (dir_options[i] != NULL)
	{
		if (find_binary_in_a_dir(dir_options[i], bin_name) == TRUE)
		{
			ret_dir = ft_strdup(dir_options[i]);
			if (ret_dir == NULL)
				exit_routine_le(ERR_MALLOC);
			break ;
		}
		i++;
	}
	free_char_ptr_arr(dir_options);
	return (ret_dir);
}
