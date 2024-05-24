/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:39:18 by olyetisk          #+#    #+#             */
/*   Updated: 2023/12/25 14:38:51 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_str(char *str, int *num)
{
	if (!str)
	{
		*num += (write(1, "(null)", 6));
		return ;
	}
	*num += write (1, str, ft_strlen(str));
}
