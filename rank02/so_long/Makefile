# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 09:58:28 by juhyeonl          #+#    #+#              #
#    Updated: 2025/03/05 14:00:23 by juhyeonl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Imlx -I. -Iget_next_line -I/usr/include/X11

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lXrandr -lXinerama -lXcursor

GNL_SRCS = \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/printf.a

SRCS = \
		srcs/main.c \
		srcs/handle/handles.c \
		srcs/map_reader.c \
		srcs/map_validator.c \
		srcs/render.c \
		srcs/events.c \
		srcs/utils.c \
		$(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(PRINTF)

$(PRINTF):
	make -C $(PRINTF_DIR)
	@if [ ! -f $(PRINTF) ]; then echo "Error: printf.a not found!"; exit 1; fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

