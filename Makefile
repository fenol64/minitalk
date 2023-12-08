NAME = minitalk.a

SRCS = server.c client.c
BONUS_SRCS = server_bonus.c client_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

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

bonus: $(BONUS_OBJS)
	make -C libft
	cc -Wall -Wextra -Werror -o server server_bonus.o libft/libft.a
	cc -Wall -Wextra -Werror -o client client_bonus.o libft/libft.a

fclean:	clean $(OBJS) $(BONUS_OBJS)
	make -C libft fclean
	rm -rf $(NAME) $(OBJS) $(BONUS_OBJS)

eclean: fclean
	rm -rf server client

re: fclean all
