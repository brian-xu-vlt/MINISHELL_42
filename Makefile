NAME = Minishell
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

HEADER += $(INCLUDES)minishell_bonus.h
HEADER += $(INCLUDES)define_bonus.h
HEADER += $(INCLUDES)enum_bonus.h
HEADER += $(INCLUDES)lexer_bonus.h
HEADER += $(INCLUDES)line_editor_bonus.h
HEADER += $(INCLUDES)parser_bonus.h
HEADER += $(INCLUDES)struct_bonus.h

SRCS += exit_routine_bonus.c
SRCS += exit_routine_env_bonus.c
SRCS += exit_routine_line_editor_bonus.c

#SRCS += test_bonus.c
SRCS += main_bonus.c
#SRCS += main_tester_valid_identifier.c
#SRCS += main_tester_parser.c #TO DELETE
#SRCS += main_tester_job_command.c #TO DELETE
#SRCS += main_tester_cleaner_quote_bonus.c #TO DELETE
SRCS += test_lexer_bonus.c
SRCS += test_parser_bonus.c
SRCS += test_jobs_bonus.c
SRCS += lexer_bonus.c
SRCS += token_bonus.c
SRCS += free_list_bonus.c
SRCS += parser_bonus.c
SRCS += parser_process_bonus.c

SRCS += debug_tools.c
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
SRCS += init_line_editor_bonus.c
SRCS += init_prompt_bonus.c
SRCS += init_term_mode_bonus.c
SRCS += update_screen_data_bonus.c
SRCS += line_editor_utils_bonus.c
SRCS += line_editor_is_utils_bonus.c
SRCS += utils_cursor_bonus.c

SRCS += builtins_echo_bonus.c
SRCS += builtins_env_bonus.c
SRCS += builtins_export_bonus.c
SRCS += builtins_unset_bonus.c
SRCS += builtins_exit_bonus.c
SRCS += unset_env_bonus.c
SRCS += get_env_bonus.c
SRCS += get_envp_bonus.c
SRCS += init_env_bonus.c
SRCS += print_env_bonus.c
SRCS += store_env_bonus.c
SRCS += parse_env_bonus.c
SRCS += utils_env_bonus.c
SRCS += print_export_output_utils_bonus.c
SRCS += print_export_output_bonus.c
SRCS += line_editor_bonus.c
SRCS += print_errno.c
SRCS += general_utils_bonus.c

SRCS += open_file_redirect_bonus.c
SRCS += signal_manager_bonus.c
SRCS += exit_status_manager_bonus.c
SRCS += utils_file_descriptor_bonus.c
SRCS += utils_executor_bonus.c
SRCS += export_exec_context_bonus.c
SRCS += execution_main_process_bonus.c
SRCS += execution_subshell_bonus.c
SRCS += executor_bonus.c
SRCS += exec_builtin_bonus.c
SRCS += locate_bin_bonus.c
SRCS += exec_bin_bonus.c
SRCS += job_command_bonus.c
SRCS += handle_no_word_bonus.c
SRCS += handle_no_word_utils_bonus.c
SRCS += job_command_utils_bonus.c
SRCS += job_command_create_bonus.c
SRCS += job_command_fill_bonus.c
#SRCS += test_job_command.c
#SRCS += verif.c
SRCS += job_command_free_bonus.c
SRCS += command_process_bonus.c
SRCS += job_init_bonus.c
SRCS += job_command_is_something_bonus.c
SRCS += job_command_count_bonus.c
SRCS += job_command_create_utils_bonus.c
SRCS += cleaner_bonus.c
SRCS += hub_cleaner_bonus.c
SRCS += verif_bonus.c
SRCS += process_redirection_bonus.c
SRCS += clean_redirection_bonus.c
SRCS += clean_redirection_utils_bonus.c
SRCS += get_type_command_bonus.c
SRCS += get_envp_av_bonus.c
SRCS += get_envp_av_utils_bonus.c
SRCS += cleaner_utils_bonus.c
SRCS += builtins_pwd_bonus.c
SRCS += builtins_cd_bonus.c
SRCS += cleaner_quote_bonus.c
SRCS += cleaner_quote_utils_bonus.c
SRCS += quote_checker_bonus.c
SRCS += builtins_cd_transform_bonus.c
SRCS += builtins_cd_check_bonus.c
SRCS += builtins_exit_utils_bonus.c
SRCS += builtins_history_bonus.c
SRCS += create_tab_redir_bonus.c
SRCS += lexer_utils_bonus.c
SRCS += test_cleaner.c
SRCS += builtins_exit_error_bonus.c


OBJ_DIR = ./objs/

vpath %.c sources/
vpath %.c sources/error_manager
vpath %.c sources/exit_routines
vpath %.c sources/lexer
vpath %.c sources/builtins
vpath %.c sources/env
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

$(OBJS): $(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) -D DEBUG_MODE=$(DEBUG_MODE) -D BONUS_FLAG=1 $(CFLAGS) -c $<  -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDES) -I$(INCLUDES_LIB) $(LIB_TERMCAP) -L./libft -lft -o $@
	echo "\033[32m$@ is ready !\033[0m"

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

f : all
	./$(NAME)

.PHONY: all clean fclean mclean re FORCE
#.SILENT:
