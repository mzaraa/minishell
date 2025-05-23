# SOURCES
SRCS	=	main.c \
			mini_libft/ft_split.c \
			mini_libft/ft_strtrim.c \
			mini_libft/ft_strchr.c \
			mini_libft/ft_substr.c \
			mini_libft/ft_isalnum.c \
			mini_libft/ft_itoa.c \
			mini_libft/ft_putstr_fd.c \
			mini_libft/ft_strlcat.c \
			parser_lexer/parse_quote.c \
			parser_lexer/lexer.c \
			parser_lexer/replace_var.c \
			linked_list_token/ft_lstadd_back.c \
			linked_list_token/ft_lstadd_front.c \
			linked_list_token/ft_lstlast.c \
			linked_list_token/ft_lstnew.c \
			linked_list_token/ft_lstsize.c \
			linked_list_token/ft_lstclear.c \
			linked_list_token/ft_lstdelone.c \
			ast_tree/ft_tree_new_node.c \
			ast_tree/build_tree.c \
			ast_tree/ft_tree_clear.c \
			parser_lexer/parser.c \
			linked_list_env/ft_lstadd_front_env.c \
			linked_list_env/ft_lstadd_back_env.c \
			linked_list_env/ft_lstlast_env.c \
			linked_list_env/ft_lstnew_env.c \
			linked_list_env/ft_lstsize_env.c \
			linked_list_env/ft_lstclear_env.c \
			linked_list_env/ft_lstdelone_env.c \
			linked_list_env/setup_env.c \
			linked_list_env/var_replace_v2.c \
			print/print_list_and_tree.c \
			exec_pipe/pipe_init.c \
			exec_word/builtin.c \
			exec_word/word.c \
			exec_word/ft_env.c \
			exec_word/ft_export.c \
			exec_word/ft_unset.c \
			exec_word/ft_pwd.c \
			exec_word/ft_cd.c \
			exec_word/ft_execve.c \
			exec_word/ft_exit.c \
			ft_error.c \

# linked_list_env/replace_env_var.c \


OBJS	= $(addprefix bin/, $(SRCS:.c=.o))

# COMPILATION
CC		= gcc
FLAGS	=  -I/usr/local/include -Wall -Wextra -Werror 

INCS	= 

LIBS	= # LIBRARIES (ex: libft)

C_OPTS	= $(FLAGS) $(INCS) -g
BIN_OPT	= $(LIBS)

# OTHER
NAME = minishell

RED = \033[91;1m
GRE = \033[32;1m
GRA = \033[37m
BLU = \033[34m
EOC = \033[0m

bin/%.o: %.c
	@mkdir -p bin/ bin/linked_list_token bin/ast_tree bin/mini_libft bin/parser_lexer bin/linked_list_env bin/print bin/exec_pipe bin/exec_word
	@$(CC) $(C_OPTS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(BIN_OPT) $^ -L/usr/include libreadline.a -ltermcap -o $@
#	@$(CC) $(BIN_OPT) $^ -L/usr/include -lreadline -o $@
	@echo "$(GRE)$@ compiled 🤢$(EOC)"

run: all
	@./$(NAME)

debug:
	@rm -rf bin
	@rm -f $(NAME)
	@make C_OPTS="$(C_OPTS) -g" BIN_OPT="$(BIN_OPT) -fsanitize=address"

clean:
	@rm -rf bin
	@echo "$(RED)objects deleted 😡$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)executables deleted 😡$(EOC)"

re: fclean all

.PHONY: all clean fclean re