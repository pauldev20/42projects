/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:55:08 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/27 18:00:41 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	create_color(unsigned char r, int g, int b, unsigned char t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static char	*ft_decimal_places_join(char *in, double val)
{
	char	*str;
	char	*out;
	int		after;

	if (!in)
		return (NULL);
	after = (int)((val - (int)val) * pow(10, 6));
	if (after < 0.0)
		after = -(after);
	str = ft_itoa(after);
	if (!str)
		return (NULL);
	out = ft_strjoin(in, str);
	free(str);
	if (!out)
		return (NULL);
	return (out);
}

char	*ft_dtoa(double val)
{
	char	*str1;
	char	*str2;

	str1 = ft_itoa((int)val);
	if (!str1)
		return (NULL);
	if (val < 0.0 && !((int)val < 0))
	{
		str2 = ft_strjoin("-", str1);
		free(str1);
		str1 = str2;
	}
	str2 = ft_strjoin(str1, ".");
	free(str1);
	if (!str2)
		return (NULL);
	str1 = str2;
	str2 = ft_decimal_places_join(str1, val);
	free(str1);
	if (!str2)
		return (NULL);
	return (str2);
}

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
		num2 /= 10;
	return ((num1 + num2) * sign);
}

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	*((unsigned int *)(vars->img.addr + ((WIN_HEIGHT - y - 1)
					* WIN_WIDTH + x - 1))) = color;
}
