/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:29 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/20 15:29:48 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	create_color(unsigned char r, int g, int b, unsigned char t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double map(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

char *ft_dtoa(double val)
{
	char	*str1;
	char	*str2;
	char	*out;
	int		after;

	str1 = ft_itoa((int)val);
	if (!str1)
		return (NULL);
	str2 = ft_strjoin(str1, ".");
	free(str1);
	str1 = str2;
	after = (int)((val - (int)val) * pow(10, 6));
	if (after < 0.0) {
		after = -(after);
		if ((int)val >= 0) {
			str2 = ft_strjoin("-", str1);
			free(str1);
			str1 = str2;
		}
	}
	str2 = ft_itoa(after);
	if (!str2) {
		free(str1);
		return (NULL);
	}
	out = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	if (!out)
		return (NULL);
	return (out);
}

void	print_controls(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 7, 15, create_color(255, 255, 255, 0), "********** CONTROLS **********");
	mlx_string_put(vars->mlx, vars->win, 7, 25, create_color(255, 255, 255, 0), "* ZOOM         -> Mouse Wheel*");
	mlx_string_put(vars->mlx, vars->win, 7, 35, create_color(255, 255, 255, 0), "* ITERATIONS   -> +/-        *");
	mlx_string_put(vars->mlx, vars->win, 7, 45, create_color(255, 255, 255, 0), "* CHANGE FRACT.-> f          *");
	mlx_string_put(vars->mlx, vars->win, 7, 55, create_color(255, 255, 255, 0), "* COLOR        -> :/\"        *");
	if (!vars->mandelbrot) {
		mlx_string_put(vars->mlx, vars->win, 7, 65, create_color(255, 255, 255, 0), "* X            -> {/}        *");
		mlx_string_put(vars->mlx, vars->win, 7, 75, create_color(255, 255, 255, 0), "* Y            -> 9/0        *");
		mlx_string_put(vars->mlx, vars->win, 7, 85, create_color(255, 255, 255, 0), "******************************");
	} 
	else
	{
		mlx_string_put(vars->mlx, vars->win, 7, 65, create_color(255, 255, 255, 0), "******************************");
	}
}

void	print_values(t_vars *vars)
{
	char	*str;

	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 15, create_color(255, 255, 255, 0), "****** VALUES ******");
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 25, create_color(255, 255, 255, 0), "* X:               *");
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 35, create_color(255, 255, 255, 0), "* Y:               *");
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 45, create_color(255, 255, 255, 0), "* ITER.:           *");
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - 20 * 7.3, 55, create_color(255, 255, 255, 0), "********************");
	if (!vars->mandelbrot) {
		str = ft_dtoa(vars->julia_x);
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - (20 - 8) * 7.3, 25, create_color(255, 255, 255, 0), str);
		free(str);
		str = ft_dtoa(vars->julia_y);
		mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - (20 - 8) * 7.3, 35, create_color(255, 255, 255, 0), str);
		free(str);
	}
	str = ft_itoa(vars->iterations);
	mlx_string_put(vars->mlx, vars->win, WIN_WIDTH - (20 - 8) * 7.3, 45, create_color(255, 255, 255, 0), str);
	free(str);
}

void	print_pixels(t_vars *vars)
{ 
	int		x;
	int		y;
	int		frac;
	
	if (vars->img.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
		&vars->img.endian);
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
			if(y > (WIN_HEIGHT - (55 + 7)) && x > WIN_WIDTH - ((20 * 7.3) + 7))
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = 0;
			else if(vars->mandelbrot && y > (WIN_HEIGHT - (65 + 7)) && x < (30 * 7.3) + 7)
				*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1) * WIN_WIDTH + x - 1))) = 0;
			else if(!vars->mandelbrot && y > (WIN_HEIGHT - (85 + 7)) && x < (30 * 7.3) + 7)
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
	if (keycode == 24) {
		vars->iterations *= 1.5;
		print_pixels(vars);
	}
	if (keycode == 27 && vars->iterations > 10) {
		vars->iterations /= 1.5;
		print_pixels(vars);
	}
	if (keycode == 30 && !vars->mandelbrot) {
		vars->julia_x += 0.1;
		print_pixels(vars);
	}
	if (keycode == 33 && !vars->mandelbrot) {
		vars->julia_x -= 0.1;
		print_pixels(vars);
	}
	if (keycode == 25 && !vars->mandelbrot) {
		vars->julia_y += 0.1;
		print_pixels(vars);
	}
	if (keycode == 29 && !vars->mandelbrot) {
		vars->julia_y -= 0.1;
		print_pixels(vars);
	}
	if (keycode == 3) {
		vars->mandelbrot = !vars->mandelbrot;
		print_pixels(vars);
	}
	if (keycode == 41) {
		vars->frac_color *= 2;
		printf("%d\n", vars->frac_color);
		print_pixels(vars);
	}
	if (keycode == 39 && vars->frac_color > 1) {
		vars->frac_color /= 2;
		printf("%d\n", vars->frac_color);
		print_pixels(vars);
	}
	return (0);
}

int	mouse_down(int button, int x, int y, t_vars *vars)
{
	(void)vars;
	(void)button;
	printf("Mouse started moving: %d -> %d | %d\n", button, x, y);
	if (button == 1)
	{
		vars->lastmx = (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH) * (16.0 / (9.0 * vars->zoom));
		vars->lastmy = -((y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom));
	}
	if (button == 5)
	{
		vars->zoom *= 1.5;
		vars->diffx = vars->diffx + (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH) * (16.0 / (9.0 * vars->zoom));
		vars->diffy = vars->diffy + -((y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom));
		print_pixels(vars);
	}
	else if (button == 4 && vars->zoom > 1)
	{
		vars->zoom /= 1.5;
		// vars->diffx = vars->diffx - (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH) * (16.0 / (9.0 * vars->zoom));
		// vars->diffy = vars->diffy - -((y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom));
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
		// vars->diffx += (((vars->lastmx - x) / vars->zoom) / (double)WIN_WIDTH) * 2.8;
		// vars->diffy += -((((vars->lastmy - y) / vars->zoom) / (double)WIN_HEIGHT) * 2.8);
		vars->diffx += (vars->lastmx - (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH) * (16.0 / (9.0 * vars->zoom)));
		vars->diffy += (vars->lastmy - (-((y - WIN_HEIGHT / 2.0) * (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom))));
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

int	main(int argc, char *argv[])
{
	t_vars vars;

	vars.img.img = NULL;
	vars.diffx = 0;
	vars.diffy = 0;
	vars.zoom = 1;
	vars.mandelbrot = 0;
	vars.julia_x = 0;
	vars.julia_y = 0;
	vars.iterations = 50;
	vars.frac_color = 1;
	if (!handle_cmd_arguments(argc, argv, &vars))
		return (1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	print_pixels(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, destroy, &vars);
	mlx_hook(vars.win, ON_EXPOSE, 0, expose, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 5, 0, mouse_up, &vars);
	mlx_hook(vars.win, 4, 0, mouse_down, &vars);
	mlx_loop(vars.mlx);
}
