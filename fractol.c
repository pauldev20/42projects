/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:29 by pgeeser           #+#    #+#             */
/*   Updated: 2022/05/13 17:36:22 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

#define ITERATIONS 200

int	create_color(unsigned char r, int g, int b, unsigned char t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	calc_mandel(double x, double y)
{
	//Z = Zn-1^2 + C
	int			i;
	t_komplex	Z;
	double		tmp;

	i = 0;
	Z.real = x;
	Z.img = y;
	while (i++ < ITERATIONS && Z.real + Z.img <= 2) //sqrt(pow(Z.real, 2) + pow(Z.img, 2))
	{
		tmp = Z.real;
		Z.real = (Z.real + Z.img) * (Z.real - Z.img) + x; //(pow(Z.real, 2) - pow(Z.img, 2))
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
	int		mandel;
	
	if (vars->img.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
		&vars->img.endian);
	xmap = (3.0 / vars->zoom) / WIN_WIDTH;
	ymap = (2.0 / vars->zoom) / WIN_HEIGHT;
	y = 0;
	while (y++ < WIN_HEIGHT)
	{
		x = 0;
		while (x++ < WIN_WIDTH)
		{
			mandel = calc_mandel(xmap * x - 1, ymap * y - 1); //-(((3.0 / vars->zoom) / 3) * 2) + xmap * (x - 1)
			if (mandel == ITERATIONS)
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = create_color(0, 0, 0, 0);
			else
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = create_color(0, 255, 255, 0);
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

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	printf("Moved mouse to %d | %d\n", x, y);
	if (button == 5 && vars->zoom < 4)
	{
		vars->zoom += 0.25;
		print_pixels(vars);
	}
	else if (button == 4 && vars->zoom > 0.5)
	{
		vars->zoom -= 0.25;
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
	vars.zoom = 1;
	print_pixels(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, destroy, &vars);
	mlx_hook(vars.win, ON_EXPOSE, 0, expose, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
