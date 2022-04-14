/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:28:50 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/14 17:00:07 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *save)
{
	char	*buf;
	int		read_rtn;
	int		i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!strchr(save, '\n'))
	{
		i = 0;
		while (i < (BUFFER_SIZE + 1))
			((unsigned char *)buf)[i++] = 0;
		read_rtn = read(fd, buf, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(buf);
			return (NULL);
		}
		save = ft_strjoin(save, buf);
		if (read_rtn == 0)
			break ;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*tmp;

	if (save)
	{
		tmp = ft_substr(save, strchr(save, '\n') - save + 1, ft_strlen(save));
		free(save);
		save = tmp;
	}
	save = read_line(fd, save);
	return (ft_substr(save, 0, strchr(save, '\n') - save + 1));
}
