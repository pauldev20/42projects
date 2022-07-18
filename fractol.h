/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:31:15 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/18 16:08:03 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "./minilibx/mlx.h"
# include "komplex.h"
# include "mlx_helpers.h"
# include "arguments.h"
# include "fractol.h"
# include "julia.h"
# include "mandelbrot.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define ON_DESTROY 17
# define ON_EXPOSE 12

#endif