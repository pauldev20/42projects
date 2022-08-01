/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:59:05 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 09:30:39 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// POWER OF COMPLEX NUMBER
t_complex	cmppow(t_complex z, int pow)
{
	t_complex	o;
	double		img;

	o = z;
	while (pow-- > 1)
	{
		img = o.img;
		o.img = o.real * z.img + o.img * z.real;
		o.real = o.real * z.real - img * z.img;
	}
	return (o);
}

// ADDING TWO COMPLEX NUMBERS
t_complex	cmpadd(t_complex z1, t_complex z2)
{
	z1.img += z2.img;
	z1.real += z2.real;
	return (z1);
}
