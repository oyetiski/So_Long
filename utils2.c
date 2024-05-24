/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:48:18 by olyetisk          #+#    #+#             */
/*   Updated: 2024/03/29 14:50:54 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_write(char *str)
{
	write (1, str, ft_strlen(str));
	return ;
}

void	move_write2(char *str)
{
	write (1, str, ft_strlen(str));
	exit (EXIT_FAILURE);
}
