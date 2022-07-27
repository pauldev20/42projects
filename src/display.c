/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:57:07 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/27 17:53:00 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_pixels(t_vars *vars)
{
	int		x;
	int		y;
	int		frac;

	y = 0;
	while (y++ < WIN_HEIGHT)
	{
		x = 0;
		while (x++ < WIN_WIDTH)
		{
			frac = calc_fractal(x, y, vars);
			if (frac == vars->iterations)
				put_pixel(vars, x, y, 0);
			else
				put_pixel(vars, x, y, create_color(25, 255 / vars->frac_color,
						100 / vars->frac_color, 0) * frac / vars->frac_color);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
