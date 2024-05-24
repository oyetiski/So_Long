/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:59:35 by olyetisk          #+#    #+#             */
/*   Updated: 2023/12/25 15:03:24 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formatter(va_list s, char c, int *num)
{
	if (c == 'd' || c == 'i')
		ft_int(va_arg(s, int), num);
	else if (c == 'c')
		ft_char(va_arg(s, int), num);
	else if (c == 's')
		ft_str(va_arg(s, char *), num);
	else if (c == 'u')
		ft_unsigned(va_arg(s, unsigned int), num);
	else if (c == 'p')
		ft_ptr(va_arg(s, unsigned long), num);
	else if (c == 'X' || c == 'x')
		ft_hex(va_arg(s, unsigned int), c, num);
	else if (c == '%')
		ft_char('%', num);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		num;
	va_list	lst;

	va_start(lst, s);
	num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			formatter(lst, s[++i], &num);
		else
			ft_char(s[i], &num);
		i++;
	}
	va_end(lst);
	return (num);
}
