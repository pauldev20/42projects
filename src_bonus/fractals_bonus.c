/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:30:45 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 09:38:41 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// FUNCTION TO GET COMPLEX VALUE FOR COROSPONING X AND Y VALUES OF WINDOW
static t_complex	get_point(double x, double y, t_vars *vars)
{
	t_complex	z;

	z.real = (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH)
		* (16.0 / (9.0 * vars->zoom)) + vars->diffx;
	z.img = (y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT)
		* (1.0 / vars->zoom) + vars->diffy;
	return (z);
}

// FUNCTION TO CALCUALTE MANDELBROT SET
static int	calc_mandel(double x, double y, t_vars *vars)
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

// FUNCTION TO CALCUALTE JULIA SET
static int	calc_julia(double x, double y, t_vars *vars)
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

// FUNCTION TO CALCUALTE MULTIBROT SET
static int	calc_multibrot(double x, double y, t_vars *vars)
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

// FUNCTION TO CALCULATE ONE OF THE FRACTALS
int	calc_fractal(double x, double y, t_vars *vars)
{
	if (!vars->fractal)
		return (calc_mandel(x, y, vars));
	else if (vars->fractal == 1)
		return (calc_julia(x, y, vars));
	return (calc_multibrot(x, y, vars));
}
