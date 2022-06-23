# SOURCES
SRCS	= main.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			parse_quote.c \
			lexer.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tree_new_node.c \
			parser.c \


OBJS	= $(addprefix bin/, $(SRCS:.c=.o))

# COMPILATION
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -Ofast

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
	@mkdir -p bin
	@$(CC) $(C_OPTS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(BIN_OPT) $^ -L/usr/include -lreadline -o $@
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