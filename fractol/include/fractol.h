/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:40:20 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/08 17:50:22 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// include
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <math.h>

// define
# define MAX_COUNT 200
# define WIDTH 800
# define HEIGHT 800
# define MOVE_STEP 0.05
# define TRUE 1
# define FALSE 0

// ft_printf_hex
# define HEX_UPPER	"0123456789ABCDEF"
# define HEX_LOWER	"0123456789abcdef"

// struct
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_juliaset
{
	double	num_a;
	double	num_b;
}			t_juliaset;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		*command1;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_data		img;
	t_juliaset	set;
}			    t_vars;

typedef struct s_cal_vars
{
	double	x;
	double	y;
	double	xn;
	double	yn;
	double	value;
	double	a;
	double	b;
	int		i;
	int		j;
	int		count;	
}				t_cal_vars;

enum 
{
	ON_KEYLEFT = 123,
	ON_KEYRIGHT = 124,
	ON_KEYUP = 126,
	ON_KEYDOWN = 125,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_DESTROY = 17,
	ON_ESC = 53
};

// ft_printf
int     ft_printf(const	char *format, ...);
int     ft_printf_format(const char format, va_list args);
int     ft_printf_char(char c);
int     ft_printf_str(char *str);
int     ft_printf_pointer(void *ptr);
int     ft_printf_pointer_hex(uintptr_t n);
int     ft_printf_nbr(int n); 
int     ft_printf_nbr_unsigned(unsigned int n);
int     ft_printf_hex(unsigned int n, const char format);
int     ft_putstr_count(char *c);

// libft
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

// main
int     render_next_frame(void *params);
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

// open_and_close
int     check_argv(char *argv);
void    display_error(void);
t_vars	initialization(char *str);
void	close_window(t_vars *env);

// handler
int		key_handler(int keycode, t_vars *env);
int		mouse_handler(int mousecode, int x, int y, t_vars *env);

// data_set
void			julia_set(t_vars *vars);
unsigned int	color(char *command, int count);

#endif