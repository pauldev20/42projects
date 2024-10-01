/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:59:04 by pgeeser           #+#    #+#             */
/*   Updated: 2022/08/01 09:40:40 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// HELPER FUNCTION OF ft_dtoa
static int	get_5_zeros(double val)
{
	int	i;

	i = 5;
	val -= (int)val;
	while ((int)val == 0 && i--)
		val *= 10;
	return (4 - i);
}

// HELPER FUNCTION OF ft_dtoa
static char	*count_and_add_zeros(char *in, double val)
{
	int		zeros;
	char	*out;
	char	*str;

	zeros = 0;
	out = in;
	zeros = get_5_zeros(val);
	while (zeros-- > 0)
	{
		str = out;
		out = ft_strjoin("0", out);
		if (!out)
		{
			free(str);
			return (NULL);
		}
		free(str);
	}
	return (out);
}

// HELPER FUNCTION OF ft_dtoa
static char	*ft_decimal_places_join(char *in, double val)
{
	char	*str;
	char	*out;
	int		after;

	if (!in)
		return (NULL);
	after = 0;
	after = (int)((val - (int)val) * pow(10, 6));
	if (after < 0.0)
		after = -(after);
	str = ft_itoa(after);
	if (!str)
		return (NULL);
	str = count_and_add_zeros(str, val);
	if (!str)
		return (NULL);
	out = ft_strjoin(in, str);
	free(str);
	if (!out)
		return (NULL);
	return (out);
}

// FUNCTION TO CONVERT DOUBLE TO STRING
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

// FUNCTION TO CONVERT STRING TO DOUBLE
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
