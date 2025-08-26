# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 00:00:00 by JuHyeon           #+#    #+#              #
#    Updated: 2025/08/26 23:25:13 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c11

SRCS	= srcs/main.c \
		  srcs/utils.c \
		  srcs/init.c \
		  srcs/philo_routine.c \
		  srcs/monitor.c \
		  srcs/clean.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)