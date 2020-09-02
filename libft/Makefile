# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#                                                     +:+ +:+         +:+      #
#    By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 15:19:15 by lfallet           #+#    #+#              #
#    Updated: 2020/09/02 16:24:57 by bvalette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS += -Wall
CFLAGS += -Wextra
ifeq ($(debug), 0)
	CFLAGS += -g3
else ifeq ($(debug), 1)
	CFLAGS += -fsanitize=address
	CFLAGS += -g3
else ifeq ($(debug), 2)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
else ifeq ($(debug), 3)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -Wpadded
else ifeq ($(debug), 4)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -Wpadded
	ifneq ($(CC), gcc)
		CFLAGS += -Weverything
	endif
endif
ifeq ($(err), 0)
	CFLAGS += -g3
else
	CFLAGS += -Werror
endif

CC = gcc

INCLUDES = includes/

HEADER += $(INCLUDES)libft.h
HEADER += $(INCLUDES)get_next_line.h
HEADER += $(INCLUDES)vector.h

SRCS += ft_atoi.c
SRCS += ft_atoul.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_free_tab.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_is_len_zero.c
SRCS += ft_isprint.c
SRCS += ft_itoa.c
SRCS += ft_ltoa_base.c
SRCS += ft_memccpy.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memdup.c
SRCS += ft_memjoin_free.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strdel.c
SRCS += ft_strdup.c
SRCS += ft_strndup.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strclen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_striter.c
SRCS += ft_strcheck.c
SRCS += ft_substr.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_ultoa_base.c
SRCS += ft_putstr.c
SRCS += ft_putendl.c
SRCS += ft_putnbr.c
SRCS += ft_strcat.c
SRCS += ft_abs.c
SRCS += ft_strncpy.c
SRCS += ft_strcdup.c
SRCS += ft_get_size_of_nb.c
SRCS += ft_strequ.c
SRCS += ft_strnequ.c
SRCS += ft_iswhitespace.c
SRCS += ft_iswhitespacedigit.c
SRCS += ft_iswhitespacecomma.c
SRCS += ft_iscomma.c
SRCS += ft_bubblesort_minindex.c
SRCS += ft_lfpow.c
SRCS += ft_int_to_char.c
SRCS += ft_atoi_base.c
SRCS += ft_convert_base.c
SRCS += ft_put_mem.c

SRCS += ft_lstadd_back.c
SRCS += ft_lstadd_front.c
SRCS += ft_lstclear.c
SRCS += ft_lstdelone.c
SRCS += ft_lstdel.c
SRCS += ft_lstiter.c
SRCS += ft_lstlast.c
SRCS += ft_lstmap.c
SRCS += ft_lstnew.c
SRCS += ft_lstsize.c

SRCS += vct_add.c
SRCS += vct_addstr.c
SRCS += vct_del.c
SRCS += vct_getlen.c
SRCS += vct_getstr.c
SRCS += vct_new.c
SRCS += vct_resize.c
SRCS += vct_nlen.c
SRCS += vct_clen.c
SRCS += vct_print.c
SRCS += vct_print_fd.c
SRCS += vct_printendl.c
SRCS += vct_printendl_fd.c
SRCS += vct_pop.c
SRCS += vct_cut.c
SRCS += vct_push.c
SRCS += vct_popfrom.c
SRCS += vct_cutfrom.c
SRCS += vct_pushstr.c
SRCS += vct_addstrat.c
SRCS += vct_addcharat.c
SRCS += vct_apply.c
SRCS += vct_cat.c
SRCS += vct_cdup.c
SRCS += vct_dup.c
SRCS += vct_chr.c
SRCS += vct_cpy.c
SRCS += vct_strdup.c
SRCS += vct_equ.c
SRCS += vct_getfirstchar.c
SRCS += vct_join.c
SRCS += vct_joinfree.c
SRCS += vct_split.c
SRCS += vct_chrstr.c
SRCS += vct_popcut.c
SRCS += vct_splitchr.c
SRCS += vct_readline.c
SRCS += vct_addmem.c
SRCS += vct_getcharat.c
SRCS += vct_clear.c

SRCS += get_next_line.c
SRCS += get_next_line_multifd.c
SRCS += get_next_line_utils.c

SRCS += libftprintf.c
SRCS += printf_misc.c
SRCS += state_machine.c
SRCS += atoul.c
SRCS += utils_precision_width.c
SRCS += utils_string.c
SRCS += conversion_disc.c
SRCS += conversion_pux.c
SRCS += join_p_conversion.c
SRCS += join_x_conversion.c
SRCS += process_conversion.c
SRCS += utils_di_conversion.c
SRCS += utils_p_conversion.c
SRCS += utils_x_conversion.c
SRCS += ft_ltoa_base_post.c
SRCS += utils_number.c

SRCS += btree_apply_by_level.c
SRCS += btree_apply_infix.c
SRCS += btree_apply_prefix.c
SRCS += btree_apply_suffix.c
SRCS += btree_create_node.c
SRCS += btree_free_suffix.c
SRCS += btree_insert_data.c
SRCS += btree_level_count.c
SRCS += btree_nodes_count.c
SRCS += btree_search_item.c

vpath %.c sources/
vpath %.c sources/conversion/
vpath %.c sources/initialisation/
vpath %.c sources/is_something/
vpath %.c sources/list/
vpath %.c sources/mem/
vpath %.c sources/output/
vpath %.c sources/gnl/
vpath %.c sources/printf/
vpath %.c sources/printf/conversion/
vpath %.c sources/printf/utils/
vpath %.c sources/printf/parser/
vpath %.c sources/string/
vpath %.c sources/vector/
vpath %.c sources/maths/
vpath %.c sources/binary_tree/

OBJS = $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
OBJS_DIR = ./objs/

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir $@

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS) : $(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean :
	$(RM) -R $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE)

.PHONY: all bonus clean fclean re
#.SILENT:
