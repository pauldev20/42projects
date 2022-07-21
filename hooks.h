/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:52:45 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/21 15:00:17 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <stdlib.h>
# include "display.h"

int destroy(void *vars);
int	key_hook(int keycode, t_vars *vars);
int	mouse_down(int button, int x, int y, t_vars *vars);
int	mouse_up(int button, int x, int y, t_vars *vars);

#endif