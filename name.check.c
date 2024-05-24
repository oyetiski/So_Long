/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:48 by olyetisk          #+#    #+#             */
/*   Updated: 2024/03/29 15:37:01 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	name_ber(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
	{
		error1 ("Name Error");
	}
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		error1 (".Ber Incorrect");
	}
}
