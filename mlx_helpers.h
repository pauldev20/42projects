/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:44:09 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/25 12:56:59 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HELPERS_H
# define MLX_HELPERS_H

# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

# define WIN_WIDTH 1422
# define WIN_HEIGHT 800
# define ITERATIONS 50

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	double	zoom;
	double	lastmx;
	double	lastmy;
	double	diffx;
	double	diffy;
	int		mandelbrot;
	double	julia_x;
	double	julia_y;
	int		iterations;
	int		frac_color;
}				t_vars;

char	*ft_dtoa(double val);
int		create_color(unsigned char r, int g, int b, unsigned char t);

#endif
