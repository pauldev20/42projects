/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:28:57 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/13 15:06:15 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		((unsigned char *)ptr)[i++] = (unsigned char)value;
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset((char *)s, 0, n);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(size * num);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * num);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

char	*strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ptr;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s1, s1_len);
	ptr = ft_memcpy(ptr + s1_len, s2, s2_len + 1);
	free(s1);
	return (ptr - s1_len);
}
