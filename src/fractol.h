/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:31:15 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/29 17:07:05 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "./../minilibx/mlx.h"
# include "./../libft/libft.h"
# include "./../ft_printf/ft_printf_bonus.h"

# define ON_DESTROY 17
# define ON_EXPOSE 12
# define WIN_WIDTH 1422
# define WIN_HEIGHT 800
# define ITERATIONS 50

typedef struct s_complex {
	double	real;
	double	img;
}				t_complex;

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	double	zoom;
	double	lastmx;
	double	lastmy;
	double	diffx;
	double	diffy;
	int		mandelbrot;
	double	julia_x;
	double	julia_y;
	int		iterations;
	int		frac_color;
}				t_vars;

int			destroy(void *vars);
int			key_hook(int keycode, t_vars *vars);
int			mouse_down(int button, int x, int y, t_vars *vars);
int			mouse_up(int button, int x, int y, t_vars *vars);

int			destroy(void *vars);
int			key_hook(int keycode, t_vars *vars);
int			mouse_down(int button, int x, int y, t_vars *vars);
int			mouse_up(int button, int x, int y, t_vars *vars);

int			calc_julia(double x, double y, t_vars *vars);
int			calc_mandel(double x, double y, t_vars *vars);
int			calc_fractal(double x, double y, t_vars *vars);

void		print_pixels(t_vars *vars);

int			handle_cmd_arguments(int argc, char **argv, t_vars *vars);

int			create_color(unsigned char r, int g, int b, unsigned char t);
void		put_pixel(t_vars *vars, int x, int y, int color);

t_complex	cmppow(t_complex z, int pow);
t_complex	cmpadd(t_complex z1, t_complex z2);

double		ft_atod(char *str);

#endif