# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 20:40:23 by hurabe            #+#    #+#              #
#    Updated: 2024/10/06 16:18:53 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	fractol
INCLUDE					=	-I fractol/include
CC						=   clang
CFLAGS					=	-Wall -Wextra -Werror -O3 -MMD -MP
RM						=	rm -f
FOLDER					=	fractol
LIBFT_FOLDER			=	fractol/libft
FT_PRINTF_FOLDER		=	fractol/libft/ft_printf
FRACTOL_FOLDER			=	fractol/src

FUNCTIONS				=	$(FRACTOL_FOLDER)/fractol.c $(FRACTOL_FOLDER)/data_set.c $(FRACTOL_FOLDER)/handler.c $(FRACTOL_FOLDER)/open_and_close.c \
							$(FRACTOL_FOLDER)/mathematics_part.c $(LIBFT_FOLDER)/ft_itoa.c $(LIBFT_FOLDER)/ft_putchar_fd.c $(LIBFT_FOLDER)/ft_putstr_fd.c $(LIBFT_FOLDER)/ft_strlen.c \
							$(FT_PRINTF_FOLDER)/ft_printf.c $(FT_PRINTF_FOLDER)/ft_printf_char.c $(FT_PRINTF_FOLDER)/ft_printf_str.c $(FT_PRINTF_FOLDER)/ft_printf_pointer.c $(FT_PRINTF_FOLDER)/ft_printf_nbr.c \
							$(FT_PRINTF_FOLDER)/ft_printf_nbr_unsigned.c $(FT_PRINTF_FOLDER)/ft_printf_hex.c 

OBJ	= $(FUNCTIONS:.c=.o)

MINILIBX_FOLDER 		= ./minilibx-linux
MINILIBX 				= $(MINILIBX_FOLDER)/libmlx.a
INCLUDES 				= -I$(MINILIBX_FOLDER)
LDFLAGS 				= -L$(MINILIBX_FOLDER)
LIBS					= -lm -lmlx


all: $(NAME)

-include $(OBJ:.o=.d)

$(NAME): $(OBJ) $(MINILIBX) $(INCLUDE)
	make -C ./libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT_FOLDER) $(LDFLAGS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MINILIBX):
	$(MAKE) -j4 -C $(MINILIBX_DIR)

bonus: all

clean:
	make clean -C ./libft
	make clean -C ./minilibx-linux  # fcleanからcleanに変更
	$(RM) $(OBJ)
	$(RM) src/*.d

fclean: clean
	$(RM) $(NAME) $(OBJ)
	$(MAKE) -C $(MINILIBX_FOLDER) clean

re: fclean all
# .PHONY: all clean fclean re bonus
.PHONY: re clean fclean bonus