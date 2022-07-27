/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:02:31 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/27 17:54:21 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_cmd_arguments(int argc, char **argv, t_vars *vars)
{
	// handle Command output! && colorchange
	if (argc > 1 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
	{
		vars->mandelbrot = 1;
		return (1);
	}
	else if (argc == 4 && ft_strncmp("Julia", argv[1], 5) == 0)
	{
		vars->julia_x = ft_atod(argv[2]);
		vars->julia_y = ft_atod(argv[3]);
		return (1);
	}
	ft_printf("############# USAGE #############\n");
	ft_printf("# ./fractol FRACTAL             #\n");
	ft_printf("# FRACTAL: Mandelbrot or Julia  #\n");
	ft_printf("#################################\n");
	return (0);
}
