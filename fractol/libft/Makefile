# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urabex <urabex@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 13:08:39 by hurabe            #+#    #+#              #
#    Updated: 2024/10/05 18:07:17 by urabex           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c

OBJS	= $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# INCS	= -I includes
NAME	= libft.a
CC		= clang
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

ifeq ($(BONUS_FLAG),yes)
	SOURCES = $(BASIC_SRCS)
else
	SOURCES = $(BASIC_SRCS)
endif

# %.o:%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re