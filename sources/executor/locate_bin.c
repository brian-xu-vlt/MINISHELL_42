/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:17:29 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:17:30 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_all_path_directories(void)
{
	char		*path_env;
	char		**dir_list;

	dir_list = NULL;
	path_env = vct_getstr(get_env_value_vct(get_env_list(GET), "PATH"));
	if (path_env == NOT_FOUND)
		return (NULL);
	else
	{
		dir_list = ft_split(path_env, ':');
		if (dir_list == NULL)
			exit_routine(EXIT_MALLOC);
	}
	return (dir_list);
}

static int	stat_path(const char *path_to_stat)
{
	struct stat	statbuf;
	int			ret;

	errno = 0;
	if (path_to_stat == NULL)
		return (FAILURE);
	ft_bzero(&statbuf, sizeof(struct stat));
	ret = stat(path_to_stat, &statbuf);
	if (S_ISDIR(statbuf.st_mode) != 0)
		errno = EISDIR;
	return ((ret != FAILURE && errno == 0) ? SUCCESS : FAILURE);
}

static void	concat_path(t_vector **vct, char *dir_option, char *bin_name)
{
	if (vct == NULL)
		return ;
	safe_vct_addstr(*vct, (char *)dir_option);
	safe_vct_addstr(*vct, "/");
	safe_vct_addstr(*vct, (char *)bin_name);
}

static char	*check_dir_option(const char *bin_name, const char *dir_option)
{
	t_vector	*full_path_vct;
	char		*full_path;
	char		*ret_full_path;
	int			ret;

	errno = 0;
	ret_full_path = NOT_FOUND;
	full_path_vct = safe_vct_new();
	concat_path(&full_path_vct, (char *)dir_option, (char *)bin_name);
	ret = stat_path(vct_getstr(full_path_vct));
	if (ret == SUCCESS)
	{
		full_path = vct_getstr(full_path_vct);
		if (full_path != NOT_FOUND)
			ret_full_path = ft_strdup(full_path);
	}
	vct_del(&full_path_vct);
	return (ret_full_path);
}

char		*locate_binary_file(const char *bin_name)
{
	char		**dir_list;
	char		*ret_full_path;
	int			i;

	errno = 0;
	ret_full_path = NOT_FOUND;
	dir_list = get_all_path_directories();
	if (is_path(bin_name) == TRUE || dir_list == NULL || dir_list[0] == NULL)
	{
		if (stat_path(bin_name) == SUCCESS)
			ret_full_path = ft_strdup(bin_name);
		else
			print_set_errno(errno, NULL, bin_name, NULL);
	}
	else if (bin_name != NULL && dir_list != NULL)
	{
		i = 0;
		while (dir_list[i] != NULL && ret_full_path == NOT_FOUND)
			ret_full_path = check_dir_option(bin_name, dir_list[i++]);
		if (ret_full_path == NOT_FOUND || errno == ENOENT)
			print_set_errno(0, ERR_NO_COMMAND, bin_name, NULL);
	}
	free_char_arr(dir_list);
	return (ret_full_path);
}
