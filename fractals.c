/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:30:45 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/19 13:45:49 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	calc_julia(double x, double y, int iterations, double x_add, double y_add)
{
	int			i;
	t_komplex	Z;
	t_komplex	A;
	double		tmp_real;
	double		tmp_img;

	i = 0;
	Z.real = x;
	Z.img = y;
	A.real = 0;
	A.img = 0;
	while (i++ < iterations && pow(Z.real, 2) + pow(Z.img, 2) < 4.0) // sqrt(pow(Z.real, 2) + pow(Z.img, 2)) < 2.0 || A.real + A.img < 4.0
	{
		tmp_real = Z.real;
		tmp_img = Z.img;
		A.real = tmp_real * tmp_real - (tmp_img * tmp_img);
		A.img = tmp_real * tmp_img + tmp_real * tmp_img;
		Z.real = A.real + x_add;
		Z.img = A.img + y_add;
	}
	return (i - 1);
}

// while (i++ < iterations && Z.real * Z.real + Z.img * Z.img < 4) //sqrt(pow(Z.real, 2) + pow(Z.img, 2))
// 	{
// 		tmp = Z.real;
// 		Z.real = (Z.real + Z.img) * (Z.real - Z.img) + x;
// 		Z.img = 2 * Z.img * tmp + y;
// 	}
int	calc_mandel(double x, double y, int iterations)
{
	int			i;
	t_komplex	Z;
	t_komplex	A;
	double		tmp;

	i = 0;
	Z.real = 0;
	Z.img = 0;
	A.real = 0;
	A.img = 0;
	while (i++ < iterations && A.real + A.img < 4.0) //sqrt(pow(Z.real, 2) + pow(Z.img, 2))
	{
		tmp = Z.real;
		Z.real = A.real - A.img + x;
		Z.img = 2 * Z.img * tmp + y;
		A.real = Z.real * Z.real;
		A.img = Z.img * Z.img;
	}
	return (i - 1);
}
