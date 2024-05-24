/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:40 by olyetisk          #+#    #+#             */
/*   Updated: 2024/04/01 14:09:52 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmap_chars(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == '1' | str[i][j] == '0' || str[i][j] == 'P'
				|| str[i][j] == 'E' || str[i][j] == 'C' || str[i][j] == '\n')
				j++;
			else
				free_map (str, "There are unwanted characters");
		}
		j = 0;
		i++;
	}
}

void	ft_counter(t_mlx *solong, int x, int y)
{
	solong->axe_count = 0;
	solong->player_count = 0;
	solong->exit_count = 0;
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if (solong->map[y][x] == 'C')
				solong->axe_count += 1;
			if (solong->map[y][x] == 'E')
				solong->exit_count += 1;
			if (solong->map[y][x] == 'P')
			{
				solong->player_count += 1;
				solong->playerx = x;
				solong->playery = y;
			}
		}
	}
	if (solong->axe_count == 0 || solong->exit_count != 1
		|| solong->player_count != 1)
		error1("Count error\n");
}

int	wall(t_mlx *solong)
{
	int	x;
	int	y;

	y = -1;
	if (!solong->map[0])
		free_map (solong->map, "Error");
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if ((y == 0 || y == solong->mapy -1)
				&& (solong->map[y][x] != '1'
				&& solong->map[y][x] != '\n'))
				free_map(solong->map, "Wall error");
			else if ((x == 0 || x == solong->mapx - 1)
				&& solong->map[y][x] != '1')
				free_map(solong->map, "Wall Error");
		}
		if (solong->mapx != x - 1)
			free_map(solong->map, "X error");
	}
	return (1);
}
