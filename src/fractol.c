/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:29 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 09:55:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// THE MAIN FUCNTION
int	main(int argc, char *argv[])
{
	t_vars	vars;

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
		destroy(&vars, 1);
	create_win(&vars);
	print_pixels(&vars);
	mlx_hook(vars.win, 17, 0, destroy_callback, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 5, 0, mouse_up, &vars);
	mlx_hook(vars.win, 4, 0, mouse_down, &vars);
	mlx_loop(vars.mlx);
	destroy(&vars, 0);
}
