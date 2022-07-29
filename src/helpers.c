/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:52:03 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/29 14:52:19 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *str)
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
		num2 /= 10.0;
	return ((num1 + num2) * sign);
}
