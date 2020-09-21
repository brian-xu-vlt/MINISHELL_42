NAME = Minishell
LIBDIR = ./libft
LIB = $(LIBDIR)libft.a

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
ifneq ($(opti), 0)
	CFLAGS += -O3
endif

CC = gcc

INCLUDES = ./includes/
INCLUDES_LIB = ./libft/includes/

HEADER = $(INCLUDES)minishell_bonus.h

ifeq ($(test), 1)
	SRCS += main_tester_parser.c #TO DELETE
else
	SRCS += main_bonus.c
endif
SRCS += lexer_bonus.c
SRCS += token_bonus.c
SRCS += free_list_bonus.c
SRCS += lexer_utils_bonus.c
SRCS += parser_bonus.c
SRCS += parser_process_bonus.c
#SRCS += debug_tools.c
SRCS += print_command_line_bonus.c
SRCS += refresh_command_line_bonus.c
SRCS += handle_esc_seq_bonus.c
SRCS += handle_print_char_bonus.c
SRCS += copy_bonus.c
SRCS += cut_bonus.c
SRCS += paste_bonus.c
SRCS += selection_bonus.c
SRCS += delete_bonus.c
SRCS += history_bonus.c
SRCS += move_bonus.c
SRCS += init_minishell_bonus.c
SRCS += init_prompt_bonus.c
SRCS += init_term_mode_bonus.c
SRCS += exit_routine_le_bonus.c
SRCS += update_screen_data_bonus.c
SRCS += utils_bonus.c
SRCS += utils_cursor_bonus.c

OBJ_DIR = ./objs/

vpath %.c sources/
vpath %.c sources/lexer
vpath %.c sources/parser
vpath %.c sources/line_editor
#vpath %.c sources/line_editor/debug
vpath %.c sources/line_editor/display
vpath %.c sources/line_editor/handlers
vpath %.c sources/line_editor/init
vpath %.c sources/line_editor/utils
vpath %.c sources/line_editor/handlers/clipboard
vpath %.c sources/line_editor/handlers/selection
vpath %.c sources/line_editor/handlers/special_keys

OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

all : $(LIB)
	$(MAKE) $(NAME)

$(OBJS): $(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<  -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@

$(NAME_BONUS): $(OBJ_DIR) $(OBJS)
	$(CC) -D BONUS=1 $(CFLAGS) $(OBJS) -I$(INCLUDES) -I$(INCLUDES_LIB) -L./libft -lft -o $@
	echo "\033[32m$@ is ready !\033[0m"

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDES) -I$(INCLUDES_LIB) -L./libft -lft -o $@
	echo "\033[32m$@ is ready !\033[0m"

$(OBJ_DIR):
	mkdir $@

$(LIB) : FORCE
	$(MAKE) -C $(LIBDIR)

FORCE :

bonus : $(LIB)
	$(MAKE) $(NAME_BONUS)
	

clean :
	$(MAKE) clean -C $(LIBDIR)
	$(RM) -R $(OBJ_DIR)

fclean : clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)

re : fclean
	$(MAKE)

.PHONY: all clean fclean re FORCE
#.SILENT:
