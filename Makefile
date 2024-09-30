# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 20:40:23 by hurabe            #+#    #+#              #
#    Updated: 2024/09/30 20:29:57 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -O3 -MMD -MP
SRCS	=	src/main.c \
			src/mathematics_part.c \
			src/open_and_close.c \
			src/handler.c \
			src/data_set.c
OBJS	=	$(SRCS:.c=.o)
FRAC_INC = fractol.h
MINILIBX_DIR := ./minilibx_linux
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -I$(MINILIBX_DIR)
LDFLAGS := -L$(MINILIBX_DIR)
LIBS	=	-lm -lmlx
LIBFT	= ./libft/libft.a

.PHONY: all
all: $(NAME)

-include $(OBJS:.o=.d)

$(NAME): $(OBJS) $(MINILIBX) $(FRAC_INC)
	make -C ./libft
	make -C minilibx_linux
	$(CC) $(OBJS) $(LIBFT) $(LDFLAGS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MINILIBX):
	$(MAKE) -j4 -C $(MINILIBX_DIR)

bonus: all

clean:
	make clean -C ./libft
	make clean -C ./minilibx_linux  # fcleanからcleanに変更
	rm -f $(OBJS)
	rm -f src/*.d

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean  # fcleanからcleanに変更

.PHONY: re clean fclean bonus
re: fclean all