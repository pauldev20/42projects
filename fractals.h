/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:30:54 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/26 16:31:53 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include <math.h>
# include "mlx_helpers.h"

typedef struct s_komplex {
	double	real;
	double	img;
}				t_komplex;

int	calc_julia(double x, double y, t_vars *vars);
int	calc_mandel(double x, double y, t_vars *vars);
int	calc_fractal(double x, double y, t_vars *vars);

#endif