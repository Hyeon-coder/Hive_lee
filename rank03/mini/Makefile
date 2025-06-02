# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 15:00:00 by JuHyeon           #+#    #+#              #
#    Updated: 2025/06/01 21:17:59 by ljh3900          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------------------------------------------------- #
# 기본 설정                                                                   #
# --------------------------------------------------------------------------- #

NAME    = minishell
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes -Ilibft
LDFLAGS = -lreadline
RM      = rm -f

OBJDIR  = objs

SRCS = srcs/main.c \
       srcs/utils.c \
       srcs/parse.c \
       srcs/execute/builtin/b_echo.c \
       srcs/execute/builtin/b_cd.c \
       srcs/execute/builtin/b_env.c \
       srcs/execute/builtin/b_export.c \
       srcs/execute/builtin/b_pwd.c \
       srcs/execute/builtin/b_unset.c \
       srcs/execute/execute.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LDFLAGS) -o $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(OBJDIR)/%.o: %.c includes/minishell.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
