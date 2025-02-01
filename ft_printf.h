/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:14 by avannson          #+#    #+#             */
/*   Updated: 2025/01/12 14:57:20 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base);
int	print_big_digit(long n, int base);
int	print_hex(unsigned long long n);
int	print_pointer(unsigned long long ptr);
int	handle_variable(char specifier, va_list args);

#endif