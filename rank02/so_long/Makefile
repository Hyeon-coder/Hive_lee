NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Iget_next_line
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11 -lXrandr -lXinerama -lXcursor

SRCS = srcs/main.c \
       srcs/map_reader.c \
       srcs/map_validator.c \
       srcs/render.c \
       srcs/events.c \
       srcs/utils.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
SECONDARY = $(OBJS)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@make -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@if [ -d "$(MLX_DIR)" ]; then \
		make -C $(MLX_DIR) clean; \
	fi

fclean: clean
	rm -f $(NAME)
	@if [ -d "$(MLX_DIR)" ]; then \
		rm -rf $(MLX_DIR); \
	fi

re: fclean all

.PHONY: all clean fclean re 