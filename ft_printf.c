/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:14 by avannson          #+#    #+#             */
/*   Updated: 2025/01/12 14:57:20 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
		count += print_hex(ptr);
	return (count);
}

int	handle_variable(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(args, int), 10);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(args, unsigned int), 16);
	else if (specifier == 'X')
		count += print_big_digit((long)va_arg(args, unsigned int), 16);
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	else if (specifier == 'u')
		count += print_digit((long)va_arg(args, unsigned int), 10);
	else if (specifier == 'p')
		count += print_pointer((unsigned long long)va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += handle_variable(*str, args);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
