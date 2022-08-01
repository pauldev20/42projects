/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:52:31 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 10:10:22 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// CALLBACK FUNCTION FOR JULIA SET SPECIFIC KEYS
static void	julia_hooks(int keycode, t_vars *vars)
{
	if (keycode == 30 && vars->fractal == 1)
		vars->julia_x += 0.1;
	if (keycode == 30 && vars->fractal == 1)
		print_pixels(vars);
	if (keycode == 33 && vars->fractal == 1)
		vars->julia_x -= 0.1;
	if (keycode == 33 && vars->fractal == 1)
		print_pixels(vars);
	if (keycode == 25 && vars->fractal == 1)
		vars->julia_y += 0.1;
	if (keycode == 25 && vars->fractal == 1)
		print_pixels(vars);
	if (keycode == 29 && vars->fractal == 1)
		vars->julia_y -= 0.1;
	if (keycode == 29 && vars->fractal == 1)
		print_pixels(vars);
}

// CALLBACK FUNCTION FOR MOVEMENT SPECIFIC KEYS
static void	movement(int keycode, t_vars *vars)
{
	if (keycode == 123)
		vars->diffx -= 0.5 / (vars->zoom / 2);
	if (keycode == 123)
		print_pixels(vars);
	if (keycode == 124)
		vars->diffx += 0.5 / (vars->zoom / 2);
	if (keycode == 124)
		print_pixels(vars);
	if (keycode == 126)
		vars->diffy += 0.5 / (vars->zoom / 2);
	if (keycode == 126)
		print_pixels(vars);
	if (keycode == 125)
		vars->diffy -= 0.5 / (vars->zoom / 2);
	if (keycode == 125)
		print_pixels(vars);
	if (keycode == 3 && vars->fractal < 2)
		vars->fractal += 1;
	if (keycode == 3)
		print_pixels(vars);
	if (keycode == 5 && vars->fractal > 0)
		vars->fractal -= 1;
	if (keycode == 5)
		print_pixels(vars);
}

// CALLBACK FUNCTION FOR A KEYPRESS
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		destroy(vars, 0);
	if (keycode == 24)
		vars->iterations *= 1.5;
	if (keycode == 24)
		print_pixels(vars);
	if (keycode == 27 && vars->iterations > 10)
		vars->iterations /= 1.5;
	if (keycode == 27 && vars->iterations > 10)
		print_pixels(vars);
	if (keycode == 41)
		vars->frac_color *= 2;
	if (keycode == 41)
		print_pixels(vars);
	if (keycode == 39 && vars->frac_color > 1)
		vars->frac_color /= 2;
	if (keycode == 39)
		print_pixels(vars);
	julia_hooks(keycode, vars);
	movement(keycode, vars);
	return (0);
}

// CALLBACK FUNCTION FOR MOUSE INTERACTION
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

// CALLBACK FUNCTION FOR END OF MOUSE INTERACTION
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
