/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 11:04:47 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/08 16:32:16 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char	*c, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		new_itoa(int n);
void	to_hex(unsigned int num, int format);
int		test(unsigned int n);
int		count_hex(unsigned int n);
int		count_unsigned_int(const char *s, va_list args, int count);
int		pointer(va_list args, int count);
void	pointer_to_hex(unsigned long num, int format);
int		count_hex_long(unsigned long n);
int		count_digits(int n);
int		convert_int(va_list args);

#endif