NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	sources/parsing/read_file.c \
		sources/parsing/parse_file.c \
		sources/parsing/parse_texture.c \
		includes/get_next_line/get_next_line.c \
		includes/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

INCLUDES = -Iincludes/cube3d -Iincludes/get_next_line

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re