/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:46:36 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/07 16:43:58 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(char *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		*(ptr + i++) = (unsigned char)value;
	return (ptr);
}
