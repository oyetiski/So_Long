/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:43 by olyetisk          #+#    #+#             */
/*   Updated: 2024/03/29 14:27:19 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(char *av)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error1 ("Can not open map\n");
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
		{
			break ;
		}
		free(s);
		i++;
	}
	close (fd);
	return (i);
}

char	**getmap(char *av)
{
	char	**s;
	int		i;
	int		fd;
	int		len;

	len = map_len(av);
	i = 0;
	s = malloc(sizeof(char *) * (len + 1));
	if (!s)
	{
		exit (EXIT_FAILURE);
	}
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		free (s);
		error1 ("Can not open map\n");
	}
	while (len > i)
	{
		s[i++] = get_next_line (fd);
	}
	s[i] = NULL;
	close (fd);
	return (s);
}

void	take_image_xpm(t_mlx *map)
{
	int	a;
	int	b;

	map->bjorn = mlx_xpm_file_to_image(map->mlx, "textures/bjorn.xpm", &a, &b);
	map->grass = mlx_xpm_file_to_image(map->mlx, "textures/grass.xpm", &a, &b);
	map->axe = mlx_xpm_file_to_image(map->mlx, "textures/axe.xpm", &a, &b);
	map->sand = mlx_xpm_file_to_image(map->mlx, "textures/sand.xpm", &a, &b);
	map->ship = mlx_xpm_file_to_image(map->mlx, "textures/ship.xpm", &a, &b);
	if (!map->bjorn || !map->grass || !map->sand || !map->axe || !map->ship)
		error1("Textures Could Not Found");
}

void	imagetowin(t_mlx *solong, int x, int y)
{
	if (solong->map[y][x] == '0')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->sand,
			x * 64, y * 64);
	else if (solong->map[y][x] == '1')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->grass,
			x * 64, y * 64);
	else if (solong->map[y][x] == 'P')
	{
		solong->playerx = x * 64;
		solong->playery = y * 64;
		mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->bjorn,
			x * 64, y * 64);
	}
	else if (solong->map[y][x] == 'C')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->axe,
			x * 64, y * 64);
	else if (solong->map[y][x] == 'E')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->ship,
			x * 64, y * 64);
}

void	paste_to_image(t_mlx *solong)
{
	int	x;
	int	y;

	y = -1;
	while (solong->map[++y])
	{
		x = -1;
		while (solong->map[y][++x])
		{
			if (solong->map[y][x] == '0')
				imagetowin(solong, x, y);
			else if (solong->map[y][x] == '1')
				imagetowin(solong, x, y);
			else if (solong->map[y][x] == 'C')
				imagetowin(solong, x, y);
			else if (solong->map[y][x] == 'E')
				imagetowin(solong, x, y);
			else if (solong->map[y][x] == 'P')
				imagetowin(solong, x, y);
		}
	}
}
