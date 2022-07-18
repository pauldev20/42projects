/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:53:10 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/18 16:58:28 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

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