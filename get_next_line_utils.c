/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:28:57 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/14 16:59:58 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strchr(const char *str, int character)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if ((char)character == 0)
		return ((char *)str);
	return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len + start > s_len)
		len = s_len - start;
	if (start >= s_len)
		len = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (len + 1))
		((unsigned char *)ptr)[i++] = 0;
	ft_memcpy(ptr, s + start, len);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ptr;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (s1_len + s2_len + 1))
		((unsigned char *)ptr)[i++] = 0;
	ptr = ft_memcpy(ptr, s1, s1_len);
	ptr = ft_memcpy(ptr + s1_len, s2, s2_len + 1);
	free(s1);
	return (ptr - s1_len);
}
