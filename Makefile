NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = \
	-Iincludes/cube3d \
	-Iincludes/get_next_line \
	-Iincludes/libft \
	-I$(MLX_DIR)

# ===========================
# MAIN
# ===========================

MAIN = \
	sources/main.c \
	sources/print_data.c

# ===========================
# HOOKS
# ===========================

HOOKS = \
	sources/hooks/close_handler.c \
	sources/hooks/keys.c \
	sources/hooks/movement.c

# ===========================
# RENDER
# ===========================

RENDER = \
	sources/render/pixel.c \
	sources/render/render.c \
	sources/render/raycasting.c \
	sources/render/load_textures.c \
	sources/render/texture_mapping.c

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
	$(HOOKS) \
	$(RENDER) \
	$(PARSER) \
	$(PARSER_UTILS) \
	$(CHECKER) \
	$(GNL)

OBJ_DIR = objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ===========================
# RULES
# ===========================

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re