/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:53:59 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/18 15:58:24 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

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
