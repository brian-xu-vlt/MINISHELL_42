/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:00:06 by lfallet           #+#    #+#             */
/*   Updated: 2020/09/04 15:38:18 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef FAILURE
#  define FAILURE -1
# endif

# ifndef BUFF_SIZE
#  define BUFF_SIZE 5
# endif

# define CLEANUP					-42
# define DEFAULT_VECTOR_SIZE		64
# define DEFAULT_VECTOR_RESIZE		16

# define NB_CONVERSION 2
# define NB_TOIS 11

# define NONE	0
# define FIRST	1
# define SECOND	2

# define NO_SEP		0x00
# define EACH_SEP 	0x01
# define ALL_SEP 	0x02
# define WORD	 	0x04
# define INIT	 	0x08

# define IS_EOF		0
# define IS_LINE	1

enum			e_apply_tois
{
	TO_LOWER,
	TO_UPPER,
	IS_ALNUM,
	IS_ALPHA,
	IS_ASCII,
	IS_DIGIT,
	IS_PRINT,
	IS_WHITESPACE,
	IS_WHITESPACECOMMA,
	IS_WHITESPACEDIGIT,
	IS_COMMA,
	TO_ATOI
};

typedef struct	s_vector
{
	char		*str;
	size_t		size;
	size_t		len;
	size_t		resize;
}				t_vector;

typedef int		(*t_ic_function)(int);

int				vct_addstr(t_vector *vct, char *str);
int				vct_add(t_vector *vct, char c);
int				vct_resize(t_vector *vct, size_t len);
void			vct_del(t_vector **vct);
t_vector		*vct_new(void);
char			*vct_getstr(t_vector *vct);
size_t			vct_getlen(t_vector *vct);
size_t			vct_nlen(t_vector *vct, size_t n);
size_t			vct_clen(t_vector *vct, char c);
ssize_t			vct_print(t_vector *vct);
ssize_t			vct_print_fd(t_vector *vct, int fd);
ssize_t			vct_printendl(t_vector *vct);
ssize_t			vct_printendl_fd(t_vector *vct, int fd);
int				vct_pop(t_vector *vct);
int				vct_cut(t_vector *vct);
int				vct_push(t_vector *vct, char c);
int				vct_popfrom(t_vector *vct, size_t nb_of_char);
int				vct_cutfrom(t_vector *vct, size_t nb_of_char);
int				vct_pushstr(t_vector *vct, char *str);
int				vct_addstrat(t_vector *vct, size_t index, char *str);
int				vct_addcharat(t_vector *vct, size_t index, char c);
int				vct_apply(t_vector *vct, int flag);
int				vct_cat(t_vector *dest, t_vector *src);
t_vector		*vct_cdup(t_vector *vct, char c);
t_vector		*vct_dup(t_vector *vct);
ssize_t			vct_chr(t_vector *vct, char c);
int				vct_cpy(t_vector *dest, t_vector *src);
char			*vct_strdup(t_vector *vct);
int				vct_equ(t_vector *vct1, t_vector *vct2);
char			vct_getfirstchar(t_vector *vct);
t_vector		*vct_join(t_vector *vct1, t_vector *vct2);
t_vector		*vct_joinfree(t_vector **vct1, t_vector **vct2, int flag);
t_vector		*vct_split(t_vector *vct, char *str, const unsigned int flag);
int				vct_chrstr(t_vector *vct, size_t index, char *search);
t_vector		*vct_popcut(t_vector *vct, size_t end, size_t start);
t_vector		*vct_splitchr(t_vector *vct, char c);
ssize_t			vct_readline(t_vector *vct, const int fd);
int				vct_addmem(t_vector *vct, void *mem, size_t len);
char			vct_getcharat(t_vector *vct, size_t index);
void			vct_clear(t_vector *vct);
int				vct_chrnstr(t_vector *vct, char *str);

#endif
