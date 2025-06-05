# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 00:45:57 by ljh3900           #+#    #+#              #
#    Updated: 2025/06/05 00:46:21 by ljh3900          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := philo
SRCDIR      := srcs
OBJDIR      := objs
INCDIR      := include
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -pthread -I$(INCDIR)

SRCS        := \
    $(SRCDIR)/main.c \
    $(SRCDIR)/init.c \
    $(SRCDIR)/routine.c \
    $(SRCDIR)/monitor.c \
    $(SRCDIR)/utils.c \
    $(SRCDIR)/clean.c

OBJS        := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/philo.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)