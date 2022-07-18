/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:43:39 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/18 16:43:43 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H

# include <math.h>
# include "mlx_helpers.h"
# include "komplex.h"

int	calc_julia(double x, double y, int iterations, double x_add, double y_add);

#endif