/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:02:31 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/25 14:52:34 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

static double	ft_atod(char *str)
{
	int		sign;
	int		num1;
	int		len;
	double	num2;

	sign = 1;
	if (str[0] == '-')
		sign = -1;
	num1 = ft_atoi(str + (sign == -1));
	while (*str && *str != '.')
		str++;
	str++;
	num2 = ft_atoi(str);
	len = ft_strlen(str);
	while (len-- > 0)
		num2 /= 10;
	return ((num1 + num2) * sign);
}

int	handle_cmd_arguments(int argc, char **argv, t_vars *vars)
{
	(void)vars;
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
