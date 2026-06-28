NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = \
	-Iincludes/cube3d \
	-Iincludes/get_next_line \
	-Iincludes/libft

# ===========================
# MAIN
# ===========================

MAIN = \
	sources/main.c

# ===========================
# PARSER
# ===========================

PARSER = \
	sources/parsing/parser/read_file.c \
	sources/parsing/parser/parse_file.c \
	sources/parsing/parser/parse_identifier.c \
	sources/parsing/parser/parse_texture.c \
	sources/parsing/parser/parse_color.c

# ===========================
# PARSER UTILS
# ===========================

PARSER_UTILS = \
	sources/parsing/utils/get_colors.c \
	sources/parsing/utils/find_map.c \
	sources/parsing/utils/copy_map.c

# ===========================
# PARSER CHECKER
# ===========================

CHECKER = \
	sources/parsing/checker/check_map.c \
	sources/parsing/checker/check_player.c

# ===========================
# RENDERING
# ===========================

RENDERING =

# ===========================
# RAYCASTING
# ===========================

RAYCASTING =

# ===========================
# EVENTS
# ===========================

EVENTS =

# ===========================
# MLX
# ===========================

MLX =

# ===========================
# UTILS
# ===========================

UTILS =

# ===========================
# GNL
# ===========================

GNL = \
	includes/get_next_line/get_next_line.c \
	includes/get_next_line/get_next_line_utils.c

# ===========================
# SOURCES
# ===========================

SRC = \
	$(MAIN) \
	$(PARSER) \
	$(PARSER_UTILS) \
	$(CHECKER) \
	$(RENDERING) \
	$(RAYCASTING) \
	$(EVENTS) \
	$(MLX) \
	$(UTILS) \
	$(GNL)

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
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