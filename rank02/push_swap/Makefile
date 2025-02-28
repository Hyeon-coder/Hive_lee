# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 20:04:17 by juhyeonl          #+#    #+#              #
#    Updated: 2025/02/28 03:12:10 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
		srcs/cmd/ft_push.c \
		srcs/cmd/ft_reverse.c \
		srcs/cmd/ft_rotate.c \
		srcs/cmd/ft_swap.c \
		srcs/sort/sort_branch.c \
		srcs/sort/radix_sort.c \
		srcs/sort/mini_sort.c \
		srcs/check_digit_utils.c \
		srcs/input_parse.c \
		srcs/main.c \
		srcs/stack_utils.c \
		srcs/utils.c
OBJ = $(SRCS:.c=.o)

LIBFT = libft/others/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I libft/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf push_swap.dSYM

re: fclean all

.PHONY: all clean fclean re

