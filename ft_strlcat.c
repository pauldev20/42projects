/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:23:01 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/07 16:52:55 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	count;

	dest_length = ft_strlen(dst);
	if (dest_length > dstsize)
		dest_length = dstsize;
	src_length = ft_strlen(src);
	count = 0;
	if (dstsize > 0 && dest_length < (dstsize - 1))
	{
		while (src[count] && (count++ + dest_length) < (dstsize - 1))
			dst[count - 1 + dest_length] = src[count - 1];
	}
	return (dest_length + src_length);
}
