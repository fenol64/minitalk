NAME=client

RAW_SRCS=$(shell find .)
SRCS=$(filter %.c, $(RAW_SRCS))

all: $(NAME)

$(NAME):
	@echo "Compiling client..."
	@cc -Wall -Wextra -Werror $(SRCS) ./../libft/libft.a -o $(NAME)
	cp $(NAME) ./../

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all