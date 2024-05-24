/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:28:55 by olyetisk          #+#    #+#             */
/*   Updated: 2024/03/29 14:40:28 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, char *msg)
{
	int	i;

	i = 0;
	while (map[i])
		free (map[i++]);
	free (map);
	move_write2 (msg);
}

int	strlen_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*s;

	s = malloc(strlen_n(str) + 1);
	i = 0;
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	error1(char *str)
{
	write (1, str, ft_strlen(str));
	exit (EXIT_FAILURE);
}
