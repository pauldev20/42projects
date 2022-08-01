/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:02:31 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 09:29:53 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// FUNCTION FOR PRINTING THE HELPTEXT
static void	print_helptext(void)
{
	ft_printf("################ USAGE ################\n");
	ft_printf("#             Mandelbrot              #\n");
	ft_printf("# ./fractol Mandelbrot COLOR          #\n");
	ft_printf("# COLOR: Color multiplication factor  #\n");
	ft_printf("#               Julia                 #\n");
	ft_printf("# ./fractol Julia X Y COLOR           #\n");
	ft_printf("# X: X addition factor for Julia set  #\n");
	ft_printf("# Y: Y addition factor for Julia set  #\n");
	ft_printf("# COLOR: Color multiplication factor  #\n");
	ft_printf("#              Multibrot              #\n");
	ft_printf("# ./fractol Multibrot POW COLOR       #\n");
	ft_printf("# POW: The exponent of the fractal    #\n");
	ft_printf("# COLOR: Color multiplication factor  #\n");
	ft_printf("#######################################\n");
}

// FUNCTION TO HANDLE COMMANDLINE ARGUMENTS
int	handle_cmd_arguments(int argc, char **argv, t_vars *vars)
{
	if (argc == 3 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
	{
		vars->fractal = 0;
		vars->frac_color = ft_atoi(argv[2]);
		return (1);
	}
	else if (argc == 5 && ft_strncmp("Julia", argv[1], 5) == 0)
	{
		vars->fractal = 1;
		vars->julia_x = ft_atod(argv[2]);
		vars->julia_y = ft_atod(argv[3]);
		vars->frac_color = ft_atoi(argv[4]);
		return (1);
	}
	else if (argc == 4 && ft_strncmp("Multibrot", argv[1], 9) == 0)
	{
		vars->fractal = 2;
		vars->multibrot = ft_atoi(argv[2]);
		vars->frac_color = ft_atoi(argv[3]);
		return (1);
	}
	print_helptext();
	return (0);
}
