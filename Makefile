NAME = minitalk.a

all: $(NAME)

$(NAME):
	make -C libft
	make -C _server
	make -C _client
	echo "Compiling minitalk..."

clean:
	make -C libft clean
	make -C _server clean
	make -C _client clean

fclean:	clean
	make -C libft fclean
	make -C _server fclean
	make -C _client fclean
	rm -f ./server ./client

re: fclean all
