CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = main.c execution.c parsing.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
