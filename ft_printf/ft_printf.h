/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:16:12 by gogalsty          #+#    #+#             */
/*   Updated: 2026/03/25 17:07:35 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

size_t		ft_putchar(char c);
size_t		ft_putstr(char *str);
size_t		ft_putnbr_base(unsigned long num, char *base);
size_t		ft_puthex(unsigned int n, int uppercase);
size_t		ft_putptr(void *ptr);
size_t		ft_handle_format(char c, va_list args);
size_t		ft_putint(int n);
size_t		ft_putunsigned(unsigned int n);
int			ft_printf(const char *format, ...);

#endif