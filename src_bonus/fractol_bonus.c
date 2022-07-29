/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:29 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/29 15:07:03 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	create_win(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.img.img = NULL;
	vars.diffx = 0;
	vars.diffy = 0;
	vars.zoom = 1;
	vars.fractal = 0;
	vars.multibrot = 0;
	vars.julia_x = 0;
	vars.julia_y = 0;
	vars.iterations = 50;
	vars.frac_color = 1;
	if (!handle_cmd_arguments(argc, argv, &vars))
	{
		destroy(&vars);
		return (1);
	}
	create_win(&vars);
	print_pixels(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, destroy, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 5, 0, mouse_up, &vars);
	mlx_hook(vars.win, 4, 0, mouse_down, &vars);
	mlx_loop(vars.mlx);
	destroy(&vars);
}
