/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:56:41 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/21 17:34:17 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "minilibx/mlx.h"
# include "mlx_helpers.h"
# include "fractals.h"

void	print_controls(t_vars *vars);
void	print_values(t_vars *vars);
void	print_pixels(t_vars *vars);

#endif