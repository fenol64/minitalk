NAME = minitalk.a

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cc -Wall -Wextra -Werror -o server server.o libft/libft.a
	cc -Wall -Wextra -Werror -o client client.o libft/libft.a

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean:	clean
	make -C libft fclean
	rm -rf $(NAME)

eclean: fclean
	rm -rf server client

re: fclean all
