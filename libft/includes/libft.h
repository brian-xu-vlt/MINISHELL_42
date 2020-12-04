/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:46:43 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/29 17:46:45 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "vector.h"
# include <stdarg.h>
# include <stdint.h>
# define TRUE	1
# define FALSE	0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t				ft_strlen(const char *s);
size_t				ft_strclen(const char *str, char c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(char *s, int c);
char				*ft_strrchr(char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(char *big, char *little, size_t len);
int					ft_atoi(const char *str);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_isascii(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memdup(void *s, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_strdel(char **str);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
void				ft_memjoin_free(char **dest, char *src, size_t len_dest,
									size_t len_src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char *s1, char *set);
char				**ft_split(char const *s1, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_striter(char *s, int (*f)(int));
int					ft_strcheck(char *s, int (*f)(int));
ssize_t				ft_putchar_fd(char c, int fd);
ssize_t				ft_putstr_fd(char *s, int fd);
ssize_t				ft_putendl_fd(char *s, int fd);
ssize_t				ft_putnbr_fd(int n, int fd);
ssize_t				ft_putstr(char *str);
ssize_t				ft_putendl(char *str);
ssize_t				ft_putnbr(int nb);
char				*ft_strcat(char *dest, char *src);
int					ft_abs(int n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcdup(const char *s, char c);
size_t				get_size_of_nb(char *s);
int					ft_strequ(char *str1, char *str2);
int					ft_strnequ(char *str1, char *str2, size_t n);
int					ft_iswhitespace(int c);
int					ft_iswhitespacecomma(int c);
int					ft_iswhitespacedigit(int c);
int					ft_iscomma(int c);
double				ft_lfpow(double nb, int pow);
void				ft_int_to_char(unsigned char *s, int value);
int					ft_atoi_base(const char *str, char *base);
char				*ft_itoa_base(long long int nb, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
void				ft_putmem(void *ptr, size_t size);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstdel(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

typedef	struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree				*btree_create_node(void *item);
void				btree_free_suffix(t_btree *root);
size_t				btree_level_count(t_btree *root);
size_t				btree_nodes_count(t_btree *root);

void				btree_apply_item_prefix(t_btree *root,
														void (*applyf)(void *));
void				btree_apply_item_infix(t_btree *root,
														void (*applyf)(void *));
void				btree_apply_item_suffix(t_btree *root,
														void (*applyf)(void *));

void				btree_apply_node_prefix(t_btree *root,
													void (*applyf)(t_btree *));
void				btree_apply_node_infix(t_btree *root,
													void (*applyf)(t_btree *));
void				btree_apply_node_suffix(t_btree *root,
													void (*applyf)(t_btree *));

void				btree_insert_data(t_btree **root,
									void *item, int (*cmpf)(void *, void *));
void				*btree_search_item(t_btree *root,
								void *data_ref, int (*cmpf)(void *, void *));
void				btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem));

/*
**** PRINTF
*/

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

# define NB_FLAGS 3

# define MOD_HH			0x000001
# define MOD_LL			0x000002
# define MOD_H			0x000004
# define MOD_L			0x000008
# define MOD_MINUS		0x000010
# define MOD_ZERO		0x000020
# define MOD_DOT		0x000040

# define CONV_C			0x000100
# define CONV_S			0x000200
# define CONV_P			0x000400
# define CONV_D			0x000800
# define CONV_I			0x001000
# define CONV_U			0x002000
# define CONV_XMIN		0x004000
# define CONV_XMAJ		0x008000
# define CONV_N			0x010000
# define CONV_PERCENT	0x020000
# define CONV_ERROR		0x040000
# define NB_CONV 10
# define STR_CONV "cspdiuxXn%"

# define STAR	'*'

# define STR_HH "hh"
# define STR_LL "ll"
# define STR_H "h"
# define STR_L "l"
# define STR_MIN "-"
# define STR_ZERO "0"
# define STR_DOT "."

# define FREE_S1 1
# define FREE_S2 2

enum				e_st
{
	LETTER,
	FLAG,
	CONVERSION,
	DO_CONV
};

typedef	struct		s_option
{
	size_t			width;
	size_t			precision;
	size_t			cpy_width;
	size_t			cpy_precision;
	size_t			len_conversion;
	int				flag;
	int				post_negt;
	size_t			len_dest;
	size_t			len_src;
}					t_option;

typedef struct		s_st_machine
{
	char			buffer[BUFFER_SIZE];
	char			*out;
	size_t			len;
	size_t			len_out;
	struct s_option	option;
	enum e_st		state;
	char			char_error;
	char			pad[3];
}					t_st_machine;

typedef	int			(*t_fun)(char *, t_st_machine *, va_list *);

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_asprintf(char **ptr, const char *format, ...);
int					is_conversion(const char c);
void				ft_bzero(void *s, size_t n);
int					is_flag(const char *s);
void				fill_buffer(t_st_machine *machine, char c);
void				memjoin_free_option(char **dest, char *src,
												t_option *option);
void				memjoin_free(char **dest, char *src, size_t len_dest,
								size_t len_src);
int					letter_function(char *str, t_st_machine *machine,
									va_list *argptr);
int					flag_function(char *str, t_st_machine *machine,
									va_list *argptr);
int					conversion_function(char *str, t_st_machine *machine,
									va_list *argptr);
char				*xminxmaj_conv(unsigned long x, t_option *option);
char				*n_conv(long *ptr, t_option *option, size_t len);
char				*c_conv(int c, t_option *option);
char				*s_conv(char *str, t_option *option);
char				*p_conv(unsigned long p, t_option *option);
char				*u_conv(unsigned long u, t_option *option);
char				*di_conv(long d, t_option *option);
char				*puxxmaj_conv(unsigned long diux, t_option *option);
size_t				len_width(size_t width);
char				*hub_strjoin_width_precision(char *str,
														t_option *option,
														size_t len_str);
void				preset_flag(t_st_machine *machine);
int					it_is_csp(int flag);
char				*process_conversion(va_list *argptr,
												t_st_machine *machine);
void				initialisation(t_st_machine *machine);
char				*ft_ultoa_base(unsigned long nb, unsigned long base);
char				*ft_ltoa_base(long nb, long base);
char				*ft_ltoa_base_post(long nb, long base);
char				*add_minus(char *new_str);
char				*strjoin_xminxmaj_conversion(char *new_str,
														t_option *origin,
														t_option *option,
														char *number);
char				*strjoin_p_conversion(char *new_str, t_option *origin,
										t_option *option, char *number);
unsigned long		atoul(const char *str);
void				get_p_width(t_option *option, size_t len);
char				*p_is_zero(t_option *option, t_option *cpy_option);
char				*d_inferior_zero(long d, t_option *option);
char				*d_superior_zero(t_option *option, long d);
void				get_width_x(t_option *option, size_t len);
void				get_precision_x(t_option *cpy_option, t_option *option,
									size_t len);
char				*x_is_zero(t_option *option, t_option *cpy_option);
int					string_str_zero(t_option *option, t_option *cpy_option,
									unsigned int x, size_t len);
size_t				get_size_of_nb(char *s);
int					is_number(char *str);
size_t				initialisation_x_conversion(t_option *option,
												t_option *cpy_option,
												char **number, unsigned long x);
size_t				initialisation_p_conversion(t_option *option,
												t_option *cpy_option,
												char **number, unsigned long p);
void				initialisation_wipre_p_conversion(t_option *option,
													t_option *cpy_option,
													size_t len,
													unsigned long p);
int					parser(char *format, va_list *argptr,
								t_st_machine *machine);

/*
**** OTHER
*/

unsigned long		ft_atoul(const char *str);
char				*ft_ltoa_base(long nb, long base);
char				*ft_ultoa_base(unsigned long nb, unsigned long base);
void				ft_free_tab(size_t size, char **str);
size_t				ft_is_len_zero(char *str);

#endif
