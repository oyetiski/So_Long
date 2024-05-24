/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:49:51 by olyetisk          #+#    #+#             */
/*   Updated: 2024/03/27 15:02:00 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*united;
	size_t	j;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	united = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (united == NULL)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		united[i] = s1[i];
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (united);
}

char	*ft_first(char *tank)
{
	int		i;
	char	*send;

	i = 0;
	if (!tank[i])
		return (NULL);
	while (tank[i] != '\n' && tank[i] != '\0')
		i++;
	send = (char *)malloc(sizeof(char) * (i + 2));
	if (!send)
		return (0);
	i = 0;
	while (tank[i] != '\n' && tank[i] != '\0')
	{
		send[i] = tank[i];
		i++;
	}
	if (tank[i] == '\n')
		send[i++] = '\n';
	send[i] = '\0';
	return (send);
}

char	*ft_last(char *tank)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (tank[i] != '\n' && tank[i] != '\0')
		i++;
	if (!tank[i])
	{
		free(tank);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * ft_strlen(tank) - i + 1);
	if (!rest)
		return (0);
	i++;
	while (tank[i] != '\0')
		rest[j++] = tank[i++];
	rest[j] = '\0';
	free(tank);
	return (rest);
}
