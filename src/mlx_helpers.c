/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:55:08 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/29 14:00:30 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(unsigned char r, int g, int b, unsigned char t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1)
					* WIN_WIDTH + x - 1))) = color;
}

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
