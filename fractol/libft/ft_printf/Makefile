# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urabex <urabex@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 21:27:34 by hurabe            #+#    #+#              #
#    Updated: 2024/10/05 18:22:44 by urabex           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= clang
FLAGS	= -Wall -Werror -Wextra
LIBFT	= ../libft/libft.a
SRCS	= ft_printf.c ft_printf_char.c ft_printf_str.c \
		  ft_printf_pointer.c ft_printf_nbr.c \
		  ft_printf_nbr_unsigned.c ft_printf_hex.c
OBJS	= ${SRCS:.c=.o}

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	make -C libft
	cp ${LIBFT} ${NAME}
	${AR} rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	make fclean -C libft
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean



# NAME	= libftprintf.a
# CC		= clang
# FLAGS	= -Wall -Werror -Wextra
# LIBFT	= fractol/libft/libft.a
# SRCS	= ft_printf.c ft_printf_char.c ft_printf_str.c \
# 		  ft_printf_pointer.c ft_printf_nbr.c \
# 		  ft_printf_nbr_unsigned.c ft_printf_hex.c
# OBJS	= ${SRCS:.c=.o}

# %.o:%.c
# 	${CC} ${FLAGS} -c $< -o $@

# ${NAME}: ${OBJS}
# 	make -C fractol/libft/
# 	cp ${LIBFT} ${NAME}
# 	${AR} rcs ${NAME} ${OBJS}

# all: ${NAME}

# clean:
# 	make fclean -C fractol/libft/
# 	${RM} ${OBJS}

# fclean: clean
# 	make fclean -C fractol/libft/
# 	${RM} ${NAME}

# re: fclean all

# .PHONY: all re clean fclean