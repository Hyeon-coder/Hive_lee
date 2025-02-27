# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 20:04:17 by juhyeonl          #+#    #+#              #
#    Updated: 2025/02/20 21:47:53 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
		algorithm.c \
		check_digit_utils.c \
		command_utils.c \
		input_parse.c \
		main.c \
		ft_push.c \
		ft_reverse.c \
		ft_rotate.c \
		ft_split_utils.c \
		ft_split.c \
		ft_swap.c \
		stack_utils.c \
		utils.c
OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

