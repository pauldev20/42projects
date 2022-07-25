/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:43:48 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/25 14:52:41 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "mlx_helpers.h"

int	handle_cmd_arguments(int argc, char **argv, t_vars *vars);

#endif