CC      = cc
NAME    = libft.a
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_atoi.c \
		  ft_strlen.c \
		  ft_strdup

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re