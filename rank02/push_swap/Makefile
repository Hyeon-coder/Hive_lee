# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             #
#   Updated: 2021/07/09 18:33:23 by shovsepy         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = push_swap

SRCS =  \
		src/main.c \
		src/radix.c \
		src/simple.c \
		utils/check_args.c \
		utils/index.c \
		utils/stack.c \
		utils/utils.c \
		commend/push.c \
		commend/reverse_rotate.c \
		commend/rotate.c \
		commend/swap.c

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