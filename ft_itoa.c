/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:50:02 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/07 23:28:08 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_digits(long n)
{
	int		digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	long	num;
	int		charsno;
	char	*str;

	num = n;
	charsno = int_digits(n) + (n < 0);
	str = (char *)ft_calloc(sizeof(char), charsno + 1);
	if (!str)
		return (NULL);
	str[0] = '-';
	if (n < 0)
		num *= -1;
	while (charsno-- > (n < 0))
	{
		str[charsno] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
