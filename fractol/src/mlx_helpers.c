/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:55:08 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 10:06:04 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// FUNCTION TO CREATE COLOR FROM R,G,B,T VALUES
int	create_color(unsigned char r, int g, int b, unsigned char t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// PUT PIXEL TO IMG
void	put_pixel(t_vars *vars, int x, int y, int color)
{
	*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1)
					* WIN_WIDTH + x - 1))) = color;
}

// DESTROY CALLBACK FOR HOOK
int	destroy_callback(void *vars)
{
	destroy(vars, 0);
	return (0);
}

// DESTROY/FREE FUNCTION
void	destroy(void *vars, int exitcode)
{
	if (((t_vars *)vars)->img.img)
		mlx_destroy_image(((t_vars *)vars)->mlx, ((t_vars *)vars)->img.img);
	if (((t_vars *)vars)->win && ((t_vars *)vars)->img.img)
		mlx_destroy_window(((t_vars *)vars)->mlx, ((t_vars *)vars)->win);
	exit(exitcode);
}

// FUNCTION TO CREATE WINDOW AND IMAGE
void	create_win(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
}
