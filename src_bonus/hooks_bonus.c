/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:52:31 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/28 00:44:19 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	destroy(void *vars)
{
	if (((t_vars *)vars)->img.img)
		mlx_destroy_image(((t_vars *)vars)->mlx, ((t_vars *)vars)->img.img);
	if (((t_vars *)vars)->win && ((t_vars *)vars)->img.img)
		mlx_destroy_window(((t_vars *)vars)->mlx, ((t_vars *)vars)->win);
	system("leaks fractol"); //remove!!!
	exit(EXIT_SUCCESS);
	return (0);
}

void	julia_hooks(int keycode, t_vars *vars)
{
	if (keycode == 30 && !vars->mandelbrot)
		vars->julia_x += 0.1;
	if (keycode == 30 && !vars->mandelbrot)
		print_pixels(vars);
	if (keycode == 33 && !vars->mandelbrot)
		vars->julia_x -= 0.1;
	if (keycode == 33 && !vars->mandelbrot)
		print_pixels(vars);
	if (keycode == 25 && !vars->mandelbrot)
		vars->julia_y += 0.1;
	if (keycode == 25 && !vars->mandelbrot)
		print_pixels(vars);
	if (keycode == 29 && !vars->mandelbrot)
		vars->julia_y -= 0.1;
	if (keycode == 29 && !vars->mandelbrot)
		print_pixels(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		destroy(vars);
	if (keycode == 24)
		vars->iterations *= 1.5;
	if (keycode == 24)
		print_pixels(vars);
	if (keycode == 27 && vars->iterations > 10)
		vars->iterations /= 1.5;
	if (keycode == 27 && vars->iterations > 10)
		print_pixels(vars);
	if (keycode == 3)
		vars->mandelbrot = !vars->mandelbrot;
	if (keycode == 3)
		print_pixels(vars);
	if (keycode == 41)
		vars->frac_color *= 2;
	if (keycode == 41)
		print_pixels(vars);
	if (keycode == 39 && vars->frac_color > 1)
		vars->frac_color /= 2;
	if (keycode == 39 && vars->frac_color > 1)
		print_pixels(vars);
	julia_hooks(keycode, vars);
	return (0);
}

int	mouse_down(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		vars->lastmx = (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH)
			* (16.0 / (9.0 * vars->zoom));
		vars->lastmy = -((y - WIN_HEIGHT / 2.0)
				* (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom));
	}
	if (button == 5)
	{
		vars->zoom *= 1.5;
		vars->diffx = vars->diffx + (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH)
			* (16.0 / (9.0 * vars->zoom));
		vars->diffy = vars->diffy + -((y - WIN_HEIGHT / 2.0)
				* (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom));
		print_pixels(vars);
	}
	else if (button == 4 && vars->zoom > 1)
	{
		vars->zoom /= 1.5;
		print_pixels(vars);
	}
	return (0);
}

int	mouse_up(int button, int x, int y, t_vars *vars)
{
	if (button == 1 && (vars->lastmx != x || vars->lastmy != y))
	{
		vars->diffx += (vars->lastmx - (x - WIN_WIDTH / 2.0)
				* (4.0 / WIN_WIDTH) * (16.0 / (9.0 * vars->zoom)));
		vars->diffy += (vars->lastmy - (-((y - WIN_HEIGHT / 2.0)
						* (4.0 / WIN_HEIGHT) * (1.0 / vars->zoom))));
		vars->lastmx = x;
		vars->lastmy = y;
		print_pixels(vars);
	}
	return (0);
}
