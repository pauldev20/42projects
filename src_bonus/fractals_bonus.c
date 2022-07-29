/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:30:45 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/29 15:06:09 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	get_point(double x, double y, t_vars *vars)
{
	t_complex	z;

	z.real = (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH)
		* (16.0 / (9.0 * vars->zoom)) + vars->diffx;
	z.img = (y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT)
		* (1.0 / vars->zoom) + vars->diffy;
	return (z);
}

// int	calc_julia(double x, double y, t_vars *vars)
// {
// 	int			i;
// 	t_complex	z;
// 	double		tmp_real;

// 	i = 0;
// 	z = get_point(x, y, vars);
// 	while (i++ < vars->iterations && pow(z.real, 2) + pow(z.img, 2) < 4.0)
// 	{
// 		tmp_real = z.real;
// 		z.real = tmp_real * tmp_real - (z.img * z.img) + vars->julia_x;
// 		z.img = tmp_real * z.img + tmp_real * z.img + vars->julia_y;
// 	}
// 	return (i - 1);
// }

// int	calc_mandel(double x, double y, t_vars *vars)
// {
// 	int			i;
// 	t_complex	z;
// 	t_complex	c;
// 	double		tmp_real;

// 	i = 0;
// 	c = get_point(x, y, vars);
// 	z.real = 0;
// 	z.img = 0;
// 	while (i++ < vars->iterations && z.real * z.real + z.img * z.img < 4.0)
// 	{
// 		tmp_real = z.real;
// 		z.real = tmp_real * tmp_real - (z.img * z.img) + c.real;
// 		z.img = tmp_real * z.img + tmp_real * z.img + c.img;
// 	}
// 	return (i - 1);
// }

int	calc_mandel(double x, double y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	c = get_point(x, y, vars);
	z.real = 0;
	z.img = 0;
	while (i++ < vars->iterations && pow(z.real, 2) + pow(z.img, 2) < 4.0)
		z = cmpadd(cmppow(z, 2), c);
	return (i - 1);
}

int	calc_julia(double x, double y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	z = get_point(x, y, vars);
	c.real = vars->julia_x;
	c.img = vars->julia_y;
	while (i++ < vars->iterations && pow(z.real, 2) + pow(z.img, 2) < 4.0)
		z = cmpadd(cmppow(z, 2), c);
	return (i - 1);
}

int	calc_multibrot(double x, double y, t_vars *vars)
{
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	c = get_point(x, y, vars);
	z.real = 0;
	z.img = 0;
	while (i++ < vars->iterations && pow(z.real, 2) + pow(z.img, 2) < 4.0)
		z = cmpadd(cmppow(z, vars->multibrot), c);
	return (i - 1);
}

int	calc_fractal(double x, double y, t_vars *vars)
{
	if (!vars->fractal)
		return (calc_mandel(x, y, vars));
	else if (vars->fractal == 1)
		return (calc_julia(x, y, vars));
	return (calc_multibrot(x, y, vars));
}
