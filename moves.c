/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:45 by olyetisk          #+#    #+#             */
/*   Updated: 2024/03/29 14:50:12 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_mlx *solong)
{
	if ((solong->map[solong->playery / 64][solong->playerx / 64 + 1] == 'E')
		&& (solong->axe_count == 0))
		move_write2("Ragnar Is Waiting For You");
	if ((solong->map[solong->playery / 64][(solong->playerx / 64) + 1] != '1')
			&& (solong->map[solong->playery / 64]
			[(solong->playerx / 64) + 1] != 'E'))
	{
		if (solong->map[solong->playery / 64]
			[(solong->playerx / 64) + 1] == 'C')
		{
			solong->axe_count -= 1;
			move_write("You Found The Axe.\n");
		}
		mlx_clear_window(solong->mlx, solong->mlx_win);
		solong->map[solong->playery / 64][solong->playerx / 64] = '0';
		solong->map[solong->playery / 64][(solong->playerx / 64) + 1] = 'P';
		solong->playerx += 64;
		paste_to_image(solong);
		solong->move += 1;
		move_write("Move = ");
		ft_putnbr(solong->move);
		write(1, "\n", 1);
	}
}

void	up(t_mlx *solong)
{
	if ((solong->map[(solong->playery / 64) - 1][solong->playerx / 64] == 'E')
		&& (solong->axe_count == 0))
		move_write2("Ragnar Is Waiting For You");
	if ((solong->map[(solong->playery / 64 - 1)][solong->playerx / 64] != '1')
		&& (solong->map[(solong->playery / 64 - 1)]
		[solong->playerx / 64] != 'E'))
	{
		if (solong->map[(solong->playery / 64) - 1]
			[solong->playerx / 64] == 'C')
		{
			solong->axe_count -= 1;
			move_write("You Found The Axe.\n");
		}
		mlx_clear_window(solong->mlx, solong->mlx_win);
		solong->map[solong->playery / 64][solong->playerx / 64] = '0';
		solong->map[(solong->playery / 64) - 1][solong->playerx / 64] = 'P';
		solong->playery -= 64;
		paste_to_image(solong);
		solong->move += 1;
		move_write("Move = ");
		ft_putnbr(solong->move);
		write(1, "\n", 1);
	}
}

void	down(t_mlx *solong)
{
	if ((solong->map[(solong->playery / 64) + 1][solong->playerx / 64] == 'E')
		&& (solong->axe_count == 0))
		move_write2("Ragnar Is Waiting For You");
	if ((solong->map[(solong->playery / 64 + 1)][solong->playerx / 64] != '1')
		&& (solong->map[(solong->playery / 64 + 1)]
		[solong->playerx / 64] != 'E'))
	{
		if (solong->map[(solong->playery / 64) + 1]
			[solong->playerx / 64] == 'C')
		{
			solong->axe_count -= 1;
			move_write("You Found The Axe.\n");
		}
		mlx_clear_window(solong->mlx, solong->mlx_win);
		solong->map[solong->playery / 64][solong->playerx / 64] = '0';
		solong->map[(solong->playery / 64) + 1][solong->playerx / 64] = 'P';
		solong->playery += 64;
		paste_to_image(solong);
		solong->move += 1;
		move_write ("Move = ");
		ft_putnbr (solong->move);
		write(1, "\n", 1);
	}
}

void	left(t_mlx *solong)
{
	if ((solong->map[solong->playery / 64][solong->playerx / 64 - 1] == 'E')
		&& (solong->axe_count == 0))
		move_write2("Ragnar Is Waiting For You");
	if ((solong->map[solong->playery / 64][(solong->playerx / 64) - 1] != '1')
		&& (solong->map[solong->playery / 64]
		[(solong->playerx / 64) - 1] != 'E'))
	{
		if (solong->map[solong->playery / 64]
			[(solong->playerx / 64) - 1] == 'C')
		{
			solong->axe_count -= 1;
			move_write("You Found The Axe.\n");
		}
		mlx_clear_window(solong->mlx, solong->mlx_win);
		solong->map[solong->playery / 64][solong->playerx / 64] = '0';
		solong->map[solong->playery / 64][(solong->playerx / 64) - 1] = 'P';
		solong->playerx -= 64;
		paste_to_image(solong);
		solong->move += 1;
		move_write ("Move = ");
		ft_putnbr (solong->move);
		write(1, "\n", 1);
	}
}

int	get_key(int keycode, t_mlx *solong)
{
	if (keycode == 53)
		exit (1);
	if (keycode == 2 || keycode == 124)
		right (solong);
	else if (keycode == 13 || keycode == 126)
		up (solong);
	else if (keycode == 1 || keycode == 125)
		down (solong);
	else if (keycode == 0 || keycode == 123)
		left (solong);
	return (0);
}
