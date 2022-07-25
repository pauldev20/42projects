/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:57:07 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/25 14:56:54 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	print_controls(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 7, 15, create_color(255, 255, 255, 0),
		"********** CONTROLS **********");
	mlx_string_put(vars->mlx, vars->win, 7, 25, create_color(255, 255, 255, 0),
		"* ZOOM         -> Mouse Wheel*");
	mlx_string_put(vars->mlx, vars->win, 7, 35, create_color(255, 255, 255, 0),
		"* ITERATIONS   -> +/-        *");
	mlx_string_put(vars->mlx, vars->win, 7, 45, create_color(255, 255, 255, 0),
		"* CHANGE FRACT.-> f          *");
	mlx_string_put(vars->mlx, vars->win, 7, 55, create_color(255, 255, 255, 0),
		"* COLOR        -> :/\"        *");
	if (!vars->mandelbrot)
	{
		mlx_string_put(vars->mlx, vars->win, 7, 65,
			create_color(255, 255, 255, 0), "* X            -> {/}        *");
		mlx_string_put(vars->mlx, vars->win, 7, 75,
			create_color(255, 255, 255, 0), "* Y            -> 9/0        *");
		mlx_string_put(vars->mlx, vars->win, 7, 85,
			create_color(255, 255, 255, 0), "******************************");
	}
	else
	{
		mlx_string_put(vars->mlx, vars->win, 7, 65,
			create_color(255, 255, 255, 0), "******************************");
	}
}

void	print_values(t_vars *vars)
{
	char	*str;

	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 15, create_color(255, 255, 255, 0), "****** VALUES ******");
	if (!vars->mandelbrot)
	{
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 25, create_color(255, 255, 255, 0), "* X:               *");
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 35, create_color(255, 255, 255, 0), "* Y:               *");
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 45, create_color(255, 255, 255, 0), "* ITER.:           *");
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 55, create_color(255, 255, 255, 0), "********************");
		str = ft_dtoa(vars->julia_x);
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - (20 - 8) * 7.3, 25, create_color(255, 255, 255, 0), str);
		free(str);
		str = ft_dtoa(vars->julia_y);
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - (20 - 8) * 7.3, 35, create_color(255, 255, 255, 0), str);
		free(str);
		str = ft_itoa(vars->iterations);
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - (20 - 8) * 7.3, 45, create_color(255, 255, 255, 0), str);
		free(str);
	}
	else
	{
		str = ft_itoa(vars->iterations);
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - (20 - 8) * 7.3, 25, create_color(255, 255, 255, 0), str);
		free(str);
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 25, create_color(255, 255, 255, 0), "* ITER.:           *");
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 35, create_color(255, 255, 255, 0), "********************");
	}
}

void	print_pixels(t_vars *vars)
{
	int		x;
	int		y;
	int		frac;

	if (vars->img.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	y = 0;
	while (y++ < WIN_HEIGHT)
	{
		x = 0;
		while (x++ < WIN_WIDTH)
		{
			if (vars->mandelbrot)
				frac = calc_mandel(x, y, vars);
			else
				frac = calc_julia(x, y, vars);
			if (vars->mandelbrot && ((y > (WIN_HEIGHT - (35 + 7)) && x > WIN_WIDTH - (20 * 7.3 + 7)) || (y > (WIN_HEIGHT - (65 + 7)) && x < (30 * 7.3) + 7)))
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = 0;
			else if (!vars->mandelbrot && ((y > (WIN_HEIGHT - (35 + 7)) && x > WIN_WIDTH - ((20 * 7.3) + 7)) || (y > (WIN_HEIGHT - (85 + 7)) && x < (30 * 7.3) + 7)))
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = 0;
			else if (frac == vars->iterations) //frac == 50 + (int)(vars->zoom / 10)
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = 0;
			else
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = create_color(25, 255 / vars->frac_color, 100 / vars->frac_color, 0) * frac / vars->frac_color;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	print_values(vars);
	print_controls(vars);
}
