/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:27 by olyetisk          #+#    #+#             */
/*   Updated: 2024/04/01 14:06:19 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill3(int x, int y, t_mlx *solong, char **map)
{
	if (x >= solong->mapx || y >= solong->mapy || y < 0 || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'Y' || map[y][x] == 'E')
		return ;
	map[y][x] = 'Y';
	floodfill3(x + 1, y, solong, map);
	floodfill3(x - 1, y, solong, map);
	floodfill3(x, y + 1, solong, map);
	floodfill3(x, y - 1, solong, map);
}

void	floodfill2(int x, int y, t_mlx *solong, char **map)
{
	if (x >= solong->mapx || y >= solong->mapy || y < 0 || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'Y')
		return ;
	map[y][x] = 'Y';
	floodfill2(x + 1, y, solong, map);
	floodfill2(x - 1, y, solong, map);
	floodfill2(x, y + 1, solong, map);
	floodfill2(x, y - 1, solong, map);
}

int	floodfill(t_mlx *solong)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = getmap(solong->map_path);
	floodfill2(solong->playerx, solong->playery, solong, temp);
	while (i < map_len(solong->map_path))
	{
		j = 0;
		while (j < (int)ft_strlen(temp[0]) - 1)
		{
			if (temp[i][j] == 'P' || temp[i][j] == 'E'
				|| temp[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (temp[i])
		free (temp[i++]);
	free (temp);
	return (1);
}

int	floodfill1(t_mlx *solong)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = getmap(solong->map_path);
	floodfill3(solong->playerx, solong->playery, solong, temp);
	while (i < map_len(solong->map_path))
	{
		j = 0;
		while (j < (int)ft_strlen(temp[0]) - 1)
		{
			if (temp[i][j] == 'P'
				|| temp[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (temp[i])
		free (temp[i++]);
	free (temp);
	return (1);
}

void	ft_putnbr(unsigned int a)
{
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	else
		write(1, &"0123456789"[a], 1);
}
