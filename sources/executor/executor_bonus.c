#include "minishell_bonus.h"

static char		*create_full_path(const char *bin_dir, const char *bin_name)
{
	size_t			len_dir;
	size_t			len_name;
	char			*full_path;

	len_dir = ft_strlen(bin_dir);
	len_name = ft_strlen(bin_name);
	full_path = (char *)ft_calloc(len_dir + len_name + 3, sizeof(char));
	if (full_path == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memcpy(full_path, bin_dir, len_dir);
	ft_memcpy(full_path + len_dir, "/", 1);
	ft_memcpy(full_path + len_dir + 1, bin_name, len_name);
	return (full_path);
}

void			executor(const t_cmd *command)
{
	char			*bin_dir;
	char			*binary_full_path;

	write(STDERR_FILENO, "\n", 1);         // DEBUG / DEBUG / DEBUG / DEBUG / DEBUG / DEBUG / DEBUG
	bin_dir = NULL;
	if (command->name != NULL)
	{
		bin_dir = find_binary(command->name);
		if (bin_dir == NOT_FOUND)
			ft_printf("%s: not a valid command\n", command->name);
		else
		{
			binary_full_path = create_full_path(bin_dir, command->name);
			execute_bin(binary_full_path, command);
			free(bin_dir);
			free(binary_full_path);
		}
	}
}
