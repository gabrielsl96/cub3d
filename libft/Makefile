# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 10:18:13 by gsousa-l          #+#    #+#              #
#    Updated: 2021/06/23 23:29:53 by gsousa-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= ft_bzero.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

NAME 	= libft.a

CC 		= gcc

LIB 	= ar rcs

FLAGS 	= -Wall -Werror -Wextra -c

RM 		= rm -f

OBJS = $(SRC:.c=.o)

.c.o:
			$(CC) $(FLAGS) $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)


all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
