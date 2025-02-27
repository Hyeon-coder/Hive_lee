# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 09:58:28 by juhyeonl          #+#    #+#              #
#    Updated: 2025/02/23 20:41:38 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -I. -Iget_next_line
MLX_FLAGS = -L./mlx -lmlx -lXext -lX11

# get_next_line 관련 파일 포함
GNL_SRCS = \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

SRCS = \
		main.c \
		map_reader.c \
		map_validator.c \
		render.c \
		events.c \
		utils.c \
		$(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all