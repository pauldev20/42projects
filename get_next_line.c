/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:28:50 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/13 15:02:53 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*out;
	char		*buf;
	int			read_rtn;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (*buf != '\n')
	{
		read_rtn = read(fd, buf, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_rtn] = '\0';
		out = strjoin(out, buf);
		if (!out)
			return (NULL);
	}
	free(buf);
	return (out);
}
