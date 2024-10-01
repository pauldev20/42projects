/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:52:31 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 09:22:52 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// CALLBACK FUNCTION FOR A KEYPRESS
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		destroy(vars, 0);
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
		vars->iterations *= 1.05;
		vars->zoom *= 1.5;
		print_pixels(vars);
	}
	else if (button == 4 && vars->zoom > 1)
	{
		vars->iterations /= 1.05;
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
