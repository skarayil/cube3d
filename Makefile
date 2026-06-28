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
	sources/main.c \
	sources/print_data.c

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
	sources/parsing/utils/error_utils.c \
	sources/parsing/utils/copy_map.c

# ===========================
# PARSER CHECKER
# ===========================

CHECKER = \
	sources/parsing/checker/check_map.c \
	sources/parsing/checker/check_player.c \
	sources/parsing/checker/check_walls.c \
	sources/parsing/checker/player_direction.c

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
	$(GNL)

OBJ_DIR = objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ===========================
# RULES
# ===========================

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re