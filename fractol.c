/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:29 by pgeeser           #+#    #+#             */
/*   Updated: 2022/05/14 12:06:16 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

#define ITERATIONS 50

int	create_color(unsigned char r, int g, int b, unsigned char t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double map(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int	calc_mandel(double x, double y)
{
	int			i;
	t_komplex	Z;
	double		tmp;

	i = 0;
	Z.real = 0;
	Z.img = 0;
	while (i++ < ITERATIONS && Z.real * Z.real + Z.img * Z.img < 4) //sqrt(pow(Z.real, 2) + pow(Z.img, 2))
	{
		tmp = Z.real;
		Z.real = (Z.real + Z.img) * (Z.real - Z.img) + x;
		Z.img = 2 * Z.img * tmp + y;
	}
	return (i - 1);
}

void	print_pixels(t_vars *vars)
{
	int		x;
	int		y;
	double	xmap;
	double	ymap;
	double	xoffset;
	double	yoffset;
	int		mandel;
	
	if (vars->img.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
		&vars->img.endian);
	xmap = ((3.0 / vars->zoom) / WIN_WIDTH);
	ymap = ((2.0 / vars->zoom) / WIN_HEIGHT);
	xoffset = -(((3.0 / vars->zoom) / 3.0) * 2.0) + vars->diffx;
	yoffset = -((2.0 / vars->zoom) / 2.0) + vars->diffy;
	y = 0;
	while (y++ < WIN_HEIGHT)
	{
		x = 0;
		while (x++ < WIN_WIDTH)
		{
			mandel = calc_mandel(xoffset + (x - 1) * xmap, yoffset + (y - 1) * ymap);
			if (mandel == ITERATIONS)
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = 0;
			else
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = create_color(25, 255, 100, 0) * mandel;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int destroy(void *vars)
{
	printf("Closing - %p\n", ((t_vars *)vars)->win);
	mlx_destroy_window(((t_vars *)vars)->mlx, ((t_vars *)vars)->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int expose(void *vars)
{
	printf("Exposing - %p\n", ((t_vars *)vars)->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Key_hook! %d from %p\n", keycode, ((t_vars *)vars)->win);
	if (keycode == 53)
		destroy(vars);
	return (0);
}

int	mouse_down(int button, int x, int y, t_vars *vars)
{
	(void)vars;
	(void)button;
	printf("Mouse started moving: %d -> %d | %d\n", button, x, y);
	if (button == 1)
	{
		vars->lastmx = x;
		vars->lastmy = y;
	}
	if (button == 5)
	{
		vars->zoom += 1;
		print_pixels(vars);
	}
	else if (button == 4 && vars->zoom > 1)
	{
		vars->zoom -= 1;
		print_pixels(vars);
	}
	return (0);
}

int	mouse_up(int button, int x, int y, t_vars *vars)
{
	(void)vars;
	(void)button;
	printf("Mouse was moved: %d -> %d | %d\n", button, x, y);
	if (button == 1 && (vars->lastmx != x || vars->lastmy != y))
	{
		vars->diffx += ((vars->lastmx - x) / (double)WIN_WIDTH) * 2.5;
		vars->diffy += -(((vars->lastmy - y) / (double)WIN_HEIGHT) * 2.5);
		vars->lastmx = x;
		vars->lastmy = y;
		printf("Diff: %f | %f\n", vars->diffx, vars->diffy);
		print_pixels(vars);
	}
	return (0);
}

int	loop_hook(t_vars *vars)
{
	(void)vars;
	return (0);
}

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars.img.img = NULL;
	vars.diffx = 0;
	vars.diffy = 0;
	vars.zoom = 1;
	print_pixels(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, destroy, &vars);
	mlx_hook(vars.win, ON_EXPOSE, 0, expose, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 5, 0, mouse_up, &vars);
	mlx_hook(vars.win, 4, 0, mouse_down, &vars);
	mlx_loop(vars.mlx);
}
