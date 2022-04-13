/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:17 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/13 13:02:42 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_of_int(long n)
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

void	ft_putnbr_fd(int n, int fd)
{
	int		digits;
	int		i;
	int		v;
	long	num;
	long	nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	digits = digits_of_int(nb);
	while (i < digits)
	{
		num = nb;
		v = digits - 1 - i++;
		while (v--)
			num /= 10;
		ft_putchar_fd((num % 10) + '0', fd);
	}
}
