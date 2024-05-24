/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:38:55 by olyetisk          #+#    #+#             */
/*   Updated: 2023/12/25 12:48:00 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_translation(unsigned int value, char a, int *num)
{
	if (a == 'X')
	{
		if (value > 9)
			ft_char(value + 55, num);
		else
			ft_char(value + 48, num);
	}
	else
	{
		if (value > 9)
			ft_char(value + 87, num);
		else
			ft_char(value + 48, num);
	}
}

void	ft_hex(unsigned long value, char a, int *num)
{
	if (a != 'p')
		value = (unsigned int) value;
	if (value >= 16)
	{
		ft_hex(value / 16, a, num);
		ft_hex(value % 16, a, num);
	}
	else
		ft_translation(value, a, num);
}
