NAME    := so_long

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
MLX_DIR := mlx
INCS    := -I. -Ilibft -I$(MLX_DIR)
MLXFLAG := -L$(MLX_DIR) -lmlx -lXext -lX11

SRC := \
    srcs/main.c srcs/map.c srcs/render.c srcs/input.c srcs/game.c srcs/utils.c \
    srcs/map_check_basic.c srcs/map_check_path.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) libft/libft.a -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(MLX_DIR)/libmlx.a:
	@git clone --depth 1 https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) 2>/dev/null || true
	@$(MAKE) -C $(MLX_DIR) >/dev/null

libft/libft.a:
	@$(MAKE) -C libft >/dev/null

clean:
	@$(MAKE) -C libft clean >/dev/null
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)
	@$(MAKE) -C libft fclean >/dev/null

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
