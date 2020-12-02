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
ifeq ($(opti), 1)
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
INCLUDES_BONUS = ./includes_bonus/
INCLUDES_LIB = ./libft/includes/

HEADER += $(INCLUDES)line_editor.h
HEADER += $(INCLUDES)minishell.h
HEADER += $(INCLUDES)define.h
HEADER += $(INCLUDES)enum.h
HEADER += $(INCLUDES)lexer.h
HEADER += $(INCLUDES)cleaner.h
HEADER += $(INCLUDES)struct.h

HEADER_BONUS += $(INCLUDES_BONUS)line_editor.h
HEADER_BONUS += $(INCLUDES_BONUS)minishell.h
HEADER_BONUS += $(INCLUDES_BONUS)define.h
HEADER_BONUS += $(INCLUDES_BONUS)enum.h
HEADER_BONUS += $(INCLUDES_BONUS)lexer.h
HEADER_BONUS += $(INCLUDES_BONUS)cleaner.h
HEADER_BONUS += $(INCLUDES_BONUS)struct.h

SRCS_BONUS += main_bonus.c
SRCS_BONUS += main_utils_bonus.c
SRCS_BONUS += line_editor_bonus.c
SRCS_BONUS += debug_tools_bonus.c
SRCS_BONUS += print_command_line_bonus.c
SRCS_BONUS += refresh_command_line_bonus.c
SRCS_BONUS += handle_esc_seq_bonus.c
SRCS_BONUS += handle_print_char_bonus.c
SRCS_BONUS += copy_bonus.c
SRCS_BONUS += cut_bonus.c
SRCS_BONUS += paste_bonus.c
SRCS_BONUS += selection_bonus.c
SRCS_BONUS += delete_bonus.c
SRCS_BONUS += history_bonus.c
SRCS_BONUS += move_bonus.c
SRCS_BONUS += init_line_editor_bonus.c
SRCS_BONUS += init_prompt_bonus.c
SRCS_BONUS += init_term_mode_bonus.c
SRCS_BONUS += update_screen_data_bonus.c
SRCS_BONUS += line_editor_utils_bonus.c
SRCS_BONUS += line_editor_is_utils_bonus.c
SRCS_BONUS += utils_cursor_bonus.c

SRCS_BONUS += exit_routine_bonus.c
SRCS_BONUS += exit_routine_env.c
SRCS_BONUS += exit_routine_line_editor_bonus.c

SRCS_BONUS += test_lexer.c
SRCS_BONUS += test_parser.c
SRCS_BONUS += test_jobs.c
SRCS_BONUS += lexer.c
SRCS_BONUS += token.c
SRCS_BONUS += free_list.c
SRCS_BONUS += parser.c
SRCS_BONUS += parser_process.c

SRCS_BONUS += builtins_set.c
SRCS_BONUS += builtins_echo.c
SRCS_BONUS += builtins_env.c
SRCS_BONUS += builtins_export.c
SRCS_BONUS += builtins_unset.c
SRCS_BONUS += builtins_exit.c
SRCS_BONUS += unset_env.c
SRCS_BONUS += get_env.c
SRCS_BONUS += get_envp.c
SRCS_BONUS += init_env.c
SRCS_BONUS += init_env_utils.c
SRCS_BONUS += print_env.c
SRCS_BONUS += store_env.c
SRCS_BONUS += parse_env.c
SRCS_BONUS += utils_env.c
SRCS_BONUS += print_export_output_utils.c
SRCS_BONUS += print_export_output.c
SRCS_BONUS += print_errno.c
SRCS_BONUS += general_utils.c
SRCS_BONUS += safe_functions.c

SRCS_BONUS += open_file_redirect.c
SRCS_BONUS += open_file_utils.c
SRCS_BONUS += signal_manager_bonus.c
SRCS_BONUS += exit_status_manager.c
SRCS_BONUS += utils_file_descriptor.c
SRCS_BONUS += utils_executor.c
SRCS_BONUS += export_exec_context.c
SRCS_BONUS += execution_main_process.c
SRCS_BONUS += execution_subshell.c
SRCS_BONUS += executor.c
SRCS_BONUS += exec_builtin.c
SRCS_BONUS += hub_open_file_redirect.c
SRCS_BONUS += locate_bin.c
SRCS_BONUS += exec_bin.c
SRCS_BONUS += job_command.c
SRCS_BONUS += handle_no_word.c
SRCS_BONUS += handle_no_word_utils.c
SRCS_BONUS += job_command_utils.c
SRCS_BONUS += job_command_create.c
SRCS_BONUS += job_command_fill.c
SRCS_BONUS += job_command_free.c
SRCS_BONUS += command_process.c
SRCS_BONUS += job_init.c
SRCS_BONUS += job_command_is_something.c
SRCS_BONUS += job_command_count.c
SRCS_BONUS += job_command_create_utils.c
SRCS_BONUS += cleaner.c
SRCS_BONUS += hub_cleaner.c
SRCS_BONUS += verif.c
SRCS_BONUS += process_redirection.c
SRCS_BONUS += clean_redirection.c
SRCS_BONUS += clean_redirection_utils.c
SRCS_BONUS += get_type_command.c
SRCS_BONUS += get_envp_av.c
SRCS_BONUS += get_envp_av_utils.c
SRCS_BONUS += cleaner_utils.c
SRCS_BONUS += builtins_pwd.c
SRCS_BONUS += builtins_cd.c
SRCS_BONUS += cleaner_quote.c
SRCS_BONUS += cleaner_quote_utils.c
SRCS_BONUS += quote_checker.c
SRCS_BONUS += builtins_cd_transform.c
SRCS_BONUS += builtins_cd_check.c
SRCS_BONUS += builtins_exit_utils.c
SRCS_BONUS += builtins_history_bonus.c
SRCS_BONUS += create_tab_redir.c
SRCS_BONUS += lexer_utils.c
SRCS_BONUS += builtins_exit_error.c
SRCS_BONUS += builtins_cd_utils.c
SRCS_BONUS += get_redir_before.c
SRCS_BONUS += cleaner_quote_pop.c
SRCS_BONUS += cleaner_double_quote.c
SRCS_BONUS += cleaner_expansion.c
SRCS_BONUS += handle_no_word_parse.c

SRCS += exit_routine.c
SRCS += exit_routine_env.c

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
OBJ_DIR_BONUS = ./objs_bonus/

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
OBJS_BONUS = $(patsubst %.c, $(OBJ_DIR_BONUS)%.o, $(SRCS_BONUS))

all : $(LIB)
	$(MAKE) $(NAME)

bonus : $(LIB)
	$(MAKE) bonus_comp

$(OBJS): $(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) -D DEBUG_MODE=$(DEBUG_MODE) $(CFLAGS) -c $<  -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@

$(OBJS_BONUS): $(OBJ_DIR_BONUS)%.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $<  -I $(INCLUDES_BONUS) -I $(INCLUDES_LIB) -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDES) -I$(INCLUDES_LIB) $(LIB_TERMCAP) -L./libft -lft -o $@
	@echo "\033[32m$@ is ready !\033[0m"

bonus_comp : $(OBJ_DIR_BONUS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -I$(INCLUDES_BONUS) -I$(INCLUDES_LIB)	$(LIB_TERMCAP) -L./libft -lft -o $(NAME)
	@echo "\033[32m$@ is ready ! With Bonus !! \033[0m"

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR_BONUS):
	mkdir $@

$(LIB) : FORCE
	$(MAKE) -C $(LIBDIR)

# FORCE :

clean :
	$(MAKE) clean -C $(LIBDIR)
	$(RM) -R $(OBJ_DIR)
	$(RM) -R $(OBJ_DIR_BONUS)

minishellclean :
	$(RM) -R $(OBJ_DIR)
	$(RM) -R $(OBJ_DIR_BONUS)

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
