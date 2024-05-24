/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:14:37 by olyetisk          #+#    #+#             */
/*   Updated: 2024/01/05 15:06:05 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(int fd, char *tank)
{
	char	*buf;
	int		return_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	return_read = 1;
	while ((!ft_strchr(tank, '\n')) && return_read != 0)
	{
		return_read = read(fd, buf, BUFFER_SIZE);
		if (return_read == -1)
		{
			free(buf);
			free(tank);
			return (NULL);
		}
		buf[return_read] = '\0';
		tank = ft_strjoin(tank, buf);
	}
	free(buf);
	return (tank);
}

char	*get_next_line(int fd)
{
	static char	*tank[10240];
	char		*wanted;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tank[fd] = ft_get_line(fd, tank[fd]);
	if (!tank[fd])
		return (NULL);
	wanted = ft_first(tank[fd]);
	tank[fd] = ft_last(tank[fd]);
	return (wanted);
}
