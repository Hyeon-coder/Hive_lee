# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 08:20:39 by JuHyeon           #+#    #+#              #
#    Updated: 2025/03/13 21:23:07 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
		srcs/main.c \
		srcs/commend/push.c \
		srcs/commend/reverse_rotate.c \
		srcs/commend/rotate.c \
		srcs/commend/swap.c \
		srcs/sort/mini_sort.c \
		srcs/sort/radix_sort.c \
		srcs/sort/simple_sort.c \
		srcs/utils/check_args.c \
		srcs/utils/free.c \
		srcs/utils/index.c \
		srcs/utils/stack_utils.c \
		srcs/utils/utils.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re