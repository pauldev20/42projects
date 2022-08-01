/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:02:31 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 09:13:57 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// FUNCTION TO HANDLE COMMANDLINE ARGUMENTS
int	handle_cmd_arguments(int argc, char **argv, t_vars *vars)
{
	if (argc == 3 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
	{
		vars->mandelbrot = 1;
		vars->frac_color = ft_atoi(argv[2]);
		return (1);
	}
	else if (argc == 5 && ft_strncmp("Julia", argv[1], 5) == 0)
	{
		vars->julia_x = ft_atod(argv[2]);
		vars->julia_y = ft_atod(argv[3]);
		vars->frac_color = ft_atoi(argv[4]);
		return (1);
	}
	ft_printf("################ USAGE ################\n");
	ft_printf("#             Mandelbrot              #\n");
	ft_printf("# ./fractol Mandelbrot COLOR          #\n");
	ft_printf("# COLOR: Color multiplication factor  #\n");
	ft_printf("#               Julia                 #\n");
	ft_printf("# ./fractol Julia X Y COLOR           #\n");
	ft_printf("# X: X addition factor for Julia set  #\n");
	ft_printf("# Y: Y addition factor for Julia set  #\n");
	ft_printf("# COLOR: Color multiplication factor  #\n");
	ft_printf("#######################################\n");
	return (0);
}
