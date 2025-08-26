# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 20:15:50 by trietpham         #+#    #+#              #
#    Updated: 2025/05/09 17:07:18 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CFLAGS		=	-g -pthread -Wall -Wextra -Werror -I ./Include
CC			=	cc

SRCS_DIR	=	./Srcs/
SRCS_FILES	=	$(SRCS_DIR)/main.c			\
				$(SRCS_DIR)/libft.c			\
				$(SRCS_DIR)/handle_arg.c	\
				$(SRCS_DIR)/init.c			\
				$(SRCS_DIR)/message.c		\
				$(SRCS_DIR)/utils.c			\
				$(SRCS_DIR)/routine.c		\
				$(SRCS_DIR)/simu.c			\
				$(SRCS_DIR)/destroy.c

OBJ_DIR		=	obj
OBJ_FILES	=	$(SRCS_FILES:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re