#include "minishell_bonus.h"

static char		**get_all_path_directories(void)
{
	char	*path_env;

	path_env = vct_getstr(get_env_value_vct("PATH"));
	return (ft_split(path_env, ':'));
}

static int		go_through_single_dir(DIR *dir_stream, char *binary_name)
{
	struct dirent	*cursor_file;

	cursor_file = readdir(dir_stream);
	while (cursor_file != NULL)
	{
		if (ft_strequ(cursor_file->d_name, binary_name) == TRUE)
			return (TRUE);
		cursor_file = readdir(dir_stream);
	}
	return (FALSE);
}

static int		find_binary_in_a_dir(char *directory, char *binary_name)
{
	int				ret;
	DIR				*dir_stream;

	ret = FALSE;
	dir_stream = opendir(directory);
	if (dir_stream == NULL)
		return (FALSE);
	ret = go_through_single_dir(dir_stream, binary_name);
	closedir(dir_stream);
	return (ret);
}

static char		*find_binary(char *binary_name)
{
	char	**dir_options;
	char	*valid_dir;
	int		i;

	dir_options = get_all_path_directories();
	i = 0;
	while (dir_options[i] != NULL)
	{
		if (find_binary_in_a_dir(dir_options[i], binary_name) == TRUE)
		{
			valid_dir = ft_strdup(dir_options[i]);
			if (valid_dir == NULL)
				exit_routine_le(ERR_MALLOC);
			free_char_ptr_arr(dir_options);
			return (valid_dir);
		}
		i++;
	}
	free_char_ptr_arr(dir_options);
/*	if (find_binary_in_pwd() == TRUE)
		return (ft_strdup(vct_getstr(get_env_value_vct("pwd"))));
*/	return (NOT_FOUND);
}

void			executor(t_cmd *command)
{
	char			*binary_dir;

	write(STDERR_FILENO, "\n", 1);         // DEBUG / DEBUG / DEBUG / DEBUG / DEBUG / DEBUG / DEBUG / DEBUG
	binary_dir = NULL;
	if (command->name != NULL)
	{
		binary_dir = find_binary(command->name);
		if (binary_dir != NULL)
		{
			execve(command->name, command->av, get_env_data(GET)->envp);
			free(binary_dir);
		}
		else
			ft_printf("%s: not a valid command\n", command->name);
	}
}
