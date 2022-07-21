/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:55:08 by pgeeser           #+#    #+#             */
/*   Updated: 2022/07/21 09:55:32 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_helpers.h"

int	create_color(unsigned char r, int g, int b, unsigned char t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char *ft_dtoa(double val)
{
	char	*str1;
	char	*str2;
	char	*out;
	int		after;

	str1 = ft_itoa((int)val);
	if (!str1)
		return (NULL);
	str2 = ft_strjoin(str1, ".");
	free(str1);
	str1 = str2;
	after = (int)((val - (int)val) * pow(10, 6));
	if (after < 0.0) {
		after = -(after);
		if ((int)val >= 0) {
			str2 = ft_strjoin("-", str1);
			free(str1);
			str1 = str2;
		}
	}
	str2 = ft_itoa(after);
	if (!str2) {
		free(str1);
		return (NULL);
	}
	out = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	if (!out)
		return (NULL);
	return (out);
}
