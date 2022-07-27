/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:30:45 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/27 17:36:17 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_komplex	get_point(double x, double y, t_vars *vars)
{
	t_komplex	z;

	z.real = (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH)
		* (16.0 / (9.0 * vars->zoom)) + vars->diffx;
	z.img = (y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT)
		* (1.0 / vars->zoom) + vars->diffy;
	return (z);
}

int	calc_julia(double x, double y, t_vars *vars)
{
	int			i;
	t_komplex	z;
	double		tmp_real;

	i = 0;
	z = get_point(x, y, vars);
	while (i++ < vars->iterations && pow(z.real, 2) + pow(z.img, 2) < 4.0)
	{
		tmp_real = z.real;
		z.real = tmp_real * tmp_real - (z.img * z.img) + vars->julia_x;
		z.img = tmp_real * z.img + tmp_real * z.img + vars->julia_y;
	}
	return (i - 1);
}

int	calc_mandel(double x, double y, t_vars *vars)
{
	int			i;
	t_komplex	z;
	t_komplex	c;
	double		tmp_real;

	i = 0;
	c = get_point(x, y, vars);
	z.real = 0;
	z.img = 0;
	while (i++ < vars->iterations && z.real * z.real + z.img * z.img < 4.0)
	{
		tmp_real = z.real;
		z.real = tmp_real * tmp_real - (z.img * z.img) + c.real;
		z.img = tmp_real * z.img + tmp_real * z.img + c.img;
	}
	return (i - 1);
}

int	calc_fractal(double x, double y, t_vars *vars)
{
	if (vars->mandelbrot)
		return (calc_mandel(x, y, vars));
	return (calc_julia(x, y, vars));
}
