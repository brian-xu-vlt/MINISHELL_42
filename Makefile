NAME = minishell
LIBDIR = ./libft
LIB = $(LIBDIR)libft.a

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -fPIC
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

ifeq ($(debug_mode), 1)
	DEBUG_MODE = 1
else
	DEBUG_MODE = 0
endif

CC = gcc

LIB_TERMCAP = -lncurses -ltermcap

INCLUDES = ./includes/
INCLUDES_LIB = ./libft/includes/

HEADER += $(INCLUDES)minishell.h
HEADER += $(INCLUDES)define.h
HEADER += $(INCLUDES)enum.h
HEADER += $(INCLUDES)lexer.h
HEADER += $(INCLUDES)cleaner.h
HEADER += $(INCLUDES)line_editor.h
HEADER += $(INCLUDES)struct.h

SRCS += exit_routine.c
SRCS += exit_routine_env.c
SRCS += exit_routine_line_editor.c

SRCS += main.c
SRCS += main_utils.c
SRCS += test_lexer.c
SRCS += test_parser.c
SRCS += test_jobs.c
SRCS += lexer.c
SRCS += token.c
SRCS += free_list.c
SRCS += parser.c
SRCS += parser_process.c

SRCS += debug_tools.c
SRCS += print_command_line.c
SRCS += refresh_command_line.c
SRCS += handle_esc_seq.c
SRCS += handle_print_char.c
SRCS += copy.c
SRCS += cut.c
SRCS += paste.c
SRCS += selection.c
SRCS += delete.c
SRCS += history.c
SRCS += move.c
SRCS += init_line_editor.c
SRCS += init_prompt.c
SRCS += init_term_mode.c
SRCS += update_screen_data.c
SRCS += line_editor_utils.c
SRCS += line_editor_is_utils.c
SRCS += utils_cursor.c

SRCS += builtins_set.c
SRCS += builtins_echo.c
SRCS += builtins_env.c
SRCS += builtins_export.c
SRCS += builtins_unset.c
SRCS += builtins_exit.c
SRCS += unset_env.c
SRCS += get_env.c
SRCS += get_envp.c
SRCS += init_env.c
SRCS += init_env_utils.c
SRCS += print_env.c
SRCS += store_env.c
SRCS += parse_env.c
SRCS += utils_env.c
SRCS += print_export_output_utils.c
SRCS += print_export_output.c
SRCS += line_editor.c
SRCS += print_errno.c
SRCS += general_utils.c
SRCS += safe_functions.c

SRCS += open_file_redirect.c
SRCS += open_file_utils.c
SRCS += signal_manager.c
SRCS += exit_status_manager.c
SRCS += utils_file_descriptor.c
SRCS += utils_executor.c
SRCS += export_exec_context.c
SRCS += execution_main_process.c
SRCS += execution_subshell.c
SRCS += executor.c
SRCS += exec_builtin.c
SRCS += hub_open_file_redirect.c
SRCS += locate_bin.c
SRCS += exec_bin.c
SRCS += job_command.c
SRCS += handle_no_word.c
SRCS += handle_no_word_utils.c
SRCS += job_command_utils.c
SRCS += job_command_create.c
SRCS += job_command_fill.c
SRCS += job_command_free.c
SRCS += command_process.c
SRCS += job_init.c
SRCS += job_command_is_something.c
SRCS += job_command_count.c
SRCS += job_command_create_utils.c
SRCS += cleaner.c
SRCS += hub_cleaner.c
SRCS += verif.c
SRCS += process_redirection.c
SRCS += clean_redirection.c
SRCS += clean_redirection_utils.c
SRCS += get_type_command.c
SRCS += get_envp_av.c
SRCS += get_envp_av_utils.c
SRCS += cleaner_utils.c
SRCS += builtins_pwd.c
SRCS += builtins_cd.c
SRCS += cleaner_quote.c
SRCS += cleaner_quote_utils.c
SRCS += quote_checker.c
SRCS += builtins_cd_transform.c
SRCS += builtins_cd_check.c
SRCS += builtins_exit_utils.c
SRCS += builtins_history.c
SRCS += create_tab_redir.c
SRCS += lexer_utils.c
SRCS += builtins_exit_error.c
SRCS += builtins_cd_utils.c
SRCS += get_redir_before.c
SRCS += cleaner_quote_pop.c
SRCS += cleaner_double_quote.c
SRCS += cleaner_expansion.c
SRCS += handle_no_word_parse.c

OBJ_DIR = ./objs/

vpath %.c sources/
vpath %.c sources/general_utils
vpath %.c sources/error_manager
vpath %.c sources/exit_routines
vpath %.c sources/lexer
vpath %.c sources/builtins
vpath %.c sources/env
vpath %.c sources/env/print_utils
vpath %.c sources/executor
vpath %.c sources/parser
vpath %.c sources/line_editor
vpath %.c sources/line_editor/debug
vpath %.c sources/line_editor/display
vpath %.c sources/line_editor/handlers
vpath %.c sources/line_editor/init
vpath %.c sources/line_editor/utils
vpath %.c sources/line_editor/handlers/clipboard
vpath %.c sources/line_editor/handlers/selection
vpath %.c sources/line_editor/handlers/special_keys
vpath %.c sources/command_job
vpath %.c sources/cleaner
vpath %.c sources/cleaner/cleaner_command
vpath %.c sources/cleaner/cleaner_redirection
vpath %.c sources/cleaner/cleaner_quote
vpath %.c sources/builtins/cd
vpath %.c sources/builtins/exit

OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

all : $(LIB)
	$(MAKE) $(NAME)

debug : $(LIB)
	$(MAKE) debug_mode=1 $(NAME)

$(OBJS): $(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) -D DEBUG_MODE=$(DEBUG_MODE) $(CFLAGS) -c $<  -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDES) -I$(INCLUDES_LIB) $(LIB_TERMCAP) -L./libft -lft -o $@
	@echo "\033[32m$@ is ready !\033[0m"

$(OBJ_DIR):
	mkdir $@

$(LIB) : FORCE
	$(MAKE) -C $(LIBDIR)

FORCE :

clean :
	$(MAKE) clean -C $(LIBDIR)
	$(RM) -R $(OBJ_DIR)

minishellclean :
	$(RM) -R $(OBJ_DIR)

fclean : clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)

mclean : minishellclean
	$(RM) $(NAME)

re : fclean
	$(MAKE)

tester: fclean debug
	./tester_bvalette/minishell_tester_bvalette.sh

f : all
	./$(NAME)

.PHONY: all clean fclean mclean re FORCE
#.SILENT:
