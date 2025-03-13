NAME = minishell
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
LIBFT = ./libft/libft.a
RM = rm -rf
LIBS = -Llibft -lft -lreadline

SRCS =  ./builtins/is_builtins.c \
		./builtins/echo.c \
		./builtins/pwd.c \
		./builtins/cd.c \
		./builtins/exit.c \
		./builtins/env.c \
		./builtins/export.c\
		main.c parser_pipex.c pipes_exec.c token_handling.c find_command_path.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)

	@$(MAKE) --no-print-directory -C libft
	@printf "\033[1;93m[LIBFT]\033[0m"
	@printf "\033[1;92m  Success!\033[0m\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@printf "\033[1;93m[Minishell]\033[0m"
	@printf "\033[1;92m  Success!\033[0m\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(MAKE) clean --no-print-directory -C ./libft
	@$(RM) $(OBJS)
	@printf "\033[1;93m[.o]\033[0m"
	@printf "\033[1;92m  Cleaned!\033[0m\n"

fclean : clean
	@$(MAKE) fclean --no-print-directory -C ./libft
	@$(RM) $(NAME)
	@printf "\033[1;93m[.a]\033[0m"
	@printf "\033[1;92m  Cleaned!\033[0m\n"

re : fclean all
