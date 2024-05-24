/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:09:35 by olyetisk          #+#    #+#             */
/*   Updated: 2023/12/23 16:09:36 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_int(int n, int *count);
void	ft_char(char d, int *count);
void	ft_str(char *str, int *count);
void	ft_unsigned(unsigned int c, int *count);
void	ft_ptr(unsigned long ptr, int *count);
void	ft_hex(unsigned long value, char c, int *count);
#endif