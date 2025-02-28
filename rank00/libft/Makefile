# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 23:06:49 by JuHyeon           #+#    #+#              #
#    Updated: 2025/02/28 15:06:25 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
		string/ft_strlen.c \
		string/ft_strlcpy.c \
		string/ft_strlcat.c \
		string/ft_strncmp.c \
		string/ft_strnstr.c \
		string/ft_strchr.c \
		string/ft_strrchr.c \
		string/ft_strdup.c \
		string/ft_strjoin.c \
		string/ft_strtrim.c \
		string/ft_substr.c \
		string/ft_split.c \
		string/ft_strmapi.c \
		string/ft_striteri.c \
		memory/ft_memset.c \
		memory/ft_memcpy.c \
		memory/ft_memmove.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		memory/ft_bzero.c \
		memory/ft_calloc.c \
		char/ft_isalpha.c \
		char/ft_isdigit.c \
		char/ft_isalnum.c \
		char/ft_isascii.c \
		char/ft_isprint.c \
		char/ft_toupper.c \
		char/ft_tolower.c \
		conversion/ft_atoi.c \
		conversion/ft_itoa.c \
		print/ft_putchar_fd.c \
		print/ft_putstr_fd.c \
		print/ft_putnbr_fd.c \
		print/ft_putendl_fd.c \
		print/ft_error.c

BONUS_SRCS = \
		linked_list/ft_lstnew.c \
		linked_list/ft_lstadd_front.c \
		linked_list/ft_lstsize.c \
		linked_list/ft_lstlast.c \
		linked_list/ft_lstadd_back.c \
		linked_list/ft_lstdelone.c \
		linked_list/ft_lstclear.c \
		linked_list/ft_lstiter.c \
		linked_list/ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p others
	@$(AR) $(NAME) $(OBJS)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "OBJS deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re bonus
