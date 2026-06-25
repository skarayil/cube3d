NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = \
	sources/parsing/read_file.c \
	sources/parsing/parse_file.c \
	sources/parsing/parse_color.c \
	sources/parsing/parse_texture.c \
	sources/parsing/get_colors.c \
	includes/get_next_line/get_next_line.c \
	includes/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

INCLUDES = -Iincludes/cube3d \
		   -Iincludes/get_next_line \
		   -Iincludes/libft

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re