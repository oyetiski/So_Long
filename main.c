/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:32 by olyetisk          #+#    #+#             */
/*   Updated: 2024/04/01 14:15:12 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	solong;

	(void) ac;
	solong.mlx = mlx_init();
	take_image_xpm(&solong);
	name_ber(av[1]);
	solong.map_path = av[1];
	solong.map = getmap(solong.map_path);
	solong.maps = getmap(solong.map_path);
	ft_counter(&solong, -1, -1);
	checkmap_chars(solong.map);
	solong.mapx = (int)ft_strlen(solong.map[0]) - 1;
	solong.mapy = map_len(solong.map_path);
	wall(&solong);
	if (!(floodfill(&solong) && floodfill1(&solong)))
		error1("Floodfill Error");
	solong.mlx_win = mlx_new_window
		(solong.mlx,
			(ft_strlen(solong.map[0]) - 1) * 64, map_len(av[1]) * 64, "solong");
	paste_to_image(&solong);
	mlx_hook(solong.mlx_win, 02, 0L, get_key, &solong);
	mlx_loop(solong.mlx);
}
