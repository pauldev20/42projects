/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:28:50 by pgeeser           #+#    #+#             */
/*   Updated: 2022/04/15 10:59:29 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *save)
{
	int		read_rtn;
	char	*buf;

	read_rtn = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!strchr(save, '\n') && read_rtn)
	{
		read_rtn = read(fd, buf, BUFFER_SIZE);
		if (read_rtn == -1)
			free(buf);
		if (read_rtn == -1)
			return (NULL);
		buf[read_rtn] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*create_rtn(char *save, char **rtn)
{
	int		save_len;
	int		rtn_len;
	char	*newsave;

	rtn_len = 0;
	while (save[rtn_len] && save[rtn_len] != '\n')
		rtn_len++;
	save_len = 0;
	while (save[rtn_len + save_len])
		save_len++;
	if (save[rtn_len] == '\n')
		rtn_len++;
	(*rtn) = ft_substr(save, 0, rtn_len);
	if (!save[rtn_len] && !**rtn)
	{
		free(*rtn);
		free(save);
		return (NULL);
	}
	newsave = ft_substr(save, rtn_len, save_len);
	free(save);
	return (newsave);
}

char	*get_next_line(int fd)
{
	static char	*save[FD_SETSIZE];
	char		*rtn;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FD_SETSIZE)
		return (NULL);
	save[fd] = read_line(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	save[fd] = create_rtn(save[fd], &rtn);
	if (!save[fd])
		return (NULL);
	return (rtn);
}
