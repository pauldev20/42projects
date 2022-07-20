/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:30:45 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/20 11:53:27 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <stdio.h>

t_komplex get_point(double x, double y, t_vars *vars)
{
	t_komplex	Z;
	
	Z.real = (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH) * (16.0 / (9.0 * vars->zoom)) + vars->diffx;
	Z.img = (y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom) + vars->diffy;
	return (Z);
}

int	calc_julia(double x, double y, t_vars *vars)
{
	int			i;
	t_komplex	Z;
	double		tmp_real;

	i = 0;
	Z = get_point(x, y, vars);
	while (i++ < vars->iterations && pow(Z.real, 2) + pow(Z.img, 2) < 4.0) // sqrt(pow(Z.real, 2) + pow(Z.img, 2)) < 2.0 || A.real + A.img < 4.0
	{
		tmp_real = Z.real;
		Z.real = tmp_real * tmp_real - (Z.img * Z.img) + vars->julia_x;
		Z.img = tmp_real * Z.img + tmp_real * Z.img + vars->julia_y;
	}
	return (i - 1);
}

// while (i++ < iterations && Z.real * Z.real + Z.img * Z.img < 4) //sqrt(pow(Z.real, 2) + pow(Z.img, 2))
// 	{
// 		tmp = Z.real;
// 		Z.real = (Z.real + Z.img) * (Z.real - Z.img) + x;
// 		Z.img = 2 * Z.img * tmp + y;
// 	}
int	calc_mandel(double x, double y, t_vars *vars)
{
	int			i;
	t_komplex	Z;
	t_komplex	C;
	double		tmp_real;

	i = 0;
	C = get_point(x, y, vars);
	Z.real = 0;
	Z.img = 0;
	while (i++ < vars->iterations && Z.real * Z.real + Z.img * Z.img < 4.0) //sqrt(pow(Z.real, 2) + pow(Z.img, 2))
	{
		tmp_real = Z.real;
		Z.real = tmp_real * tmp_real - (Z.img * Z.img) + C.real;
		Z.img = tmp_real * Z.img + tmp_real * Z.img + C.img;
	}
	return (i - 1);
}
