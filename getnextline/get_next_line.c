/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:14:37 by olyetisk          #+#    #+#             */
/*   Updated: 2024/01/05 15:07:01 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get(int fd, char *tank)
{
	char	*buf;
	int		rread;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rread = 1;
	while ((!ft_strchr(tank, '\n')) && rread != 0)
	{
		rread = read(fd, buf, BUFFER_SIZE);
		if (rread == -1)
			return (free(tank), free(buf), NULL);
		buf[rread] = '\0';
		tank = ft_strjoin(tank, buf);
		if (!tank)
			return (free(buf), NULL);
	}
	free(buf);
	return (tank);
}

char	*get_next_line(int fd)
{
	static char	*tank;
	char		*deep;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tank = ft_get(fd, tank);
	if (!tank)
		return (NULL);
	deep = ft_first(tank);
	tank = ft_last(tank);
	return (deep);
}
