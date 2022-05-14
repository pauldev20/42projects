/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:31:15 by pgeeser           #+#    #+#             */
/*   Updated: 2022/05/14 10:16:51 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include "./minilibx/mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define ON_DESTROY 17
# define ON_EXPOSE 12

typedef struct	s_komplex {
	double	real;
	double	img;
}				t_komplex;

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	double	zoom;
	int		lastmx;
	int		lastmy;
	double	diffx;
	double	diffy;
}				t_vars;

#endif