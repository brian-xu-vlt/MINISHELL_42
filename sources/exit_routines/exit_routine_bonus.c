#include "line_editor_bonus.h"

# define	NORMAL_EXIT					0
# define	ERR_ENV			 			-2
# define	ERR_NEW_VCT		 			-3
# define	ERR_VCT			 			-4
# define	ERR_ENVP		 			-5
# define	ERR_SCREEN_SIZE	 			-6
# define	ERR_TERM_NAME	 			-7
# define	ERR_TERMCAP		 			-8
# define	ERR_MALLOC		 			-9
# define	ERR_FORK		 			-10
# define	ERR_HUP			 			-11
# define	ERR_MS_PUTCHAR	 			-12
# define	ERR_MS_TPUTS 				-13

# define	NB_ERR_CODES				12

static void	print_exit_error(int error)
{
	static const int	err_code[NB_ERR_CODES] = {
		ERR_ENV ,ERR_NEW_VCT, ERR_VCT, ERR_ENVP, ERR_SCREEN_SIZE,
		ERR_TERM_NAME, ERR_TERMCAP, ERR_MALLOC, ERR_FORK, ERR_HUP,
		ERR_MS_PUTCHAR,ERR_MS_TPUTS };
	static const char	*err_code_str[NB_ERR_CODES] = {
		"Could not load environement variables.", "Could not malloc vector.",
		"Vector function failed.", "Envp is null.", "Screen size is too small.",
		"TERM environment variable not set.",
		"Minishell is not (yet) compatible to this Terminal",
		"Malloc could not allocate memory.", "Could not fork a child process.",
		"Received a Hang Up signal.", "Could not write on stdout",
		"Could not output termcaps" };
	int					i;

	i = 0;
	while (i < NB_ERR_CODES)
	{
		if (err_code[i] == error)
			ft_dprintf(STDERR_FILENO, "Minishell: %s\n", err_code_str[i]);
		i++;
	}
	return (NOT_FOUND);
}

void		exit_routine(int err_code)
{
	int			last_exit_status;

	last_exit_status = get_env_value_int(get_env_list(GET), S_QUESTION_MARK);
	exit_routine_le();
	exit_routine_env();
	exit_routine_lexer();
	// ...

	if (err_code != NORMAL_EXIT)
	{
		print_exit_error(err_code);
		exit (err_code);
	}
	else
		ft_dprintf(STDERR_FILENO, "exit\n");
	exit(last_exit_status);
}
