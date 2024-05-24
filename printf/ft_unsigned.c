/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:38:18 by olyetisk          #+#    #+#             */
/*   Updated: 2023/12/25 12:49:12 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int i, int *str)
{
	if (i > 9)
	{
		ft_unsigned(i / 10, str);
		ft_unsigned(i % 10, str);
	}
	else
		ft_char(i + 48, str);
}
