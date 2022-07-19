/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:30:54 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/19 16:45:25 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include <math.h>
# include "mlx_helpers.h"

typedef struct	s_komplex {
	double	real;
	double	img;
}				t_komplex;

int	calc_julia(double x, double y, int iterations, double x_add, double y_add);
int	calc_mandel(double x, double y, int iterations);

#endif