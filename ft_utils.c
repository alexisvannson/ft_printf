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

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (print_str("(null)"));
	while (*str)
	{
		count += print_char((int)*str);
		str++;
	}
	return (count);
}

int	print_digit(long n, int base)
{
	int		count;
	char	*chars;

	count = 0;
	chars = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(chars[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_big_digit(long n, int base)
{
	int		count;
	char	*chars;

	count = 0;
	chars = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_big_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(chars[n]));
	else
	{
		count = print_big_digit(n / base, base);
		return (count + print_big_digit(n % base, base));
	}
}

int	print_hex(unsigned long long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		count += print_hex(n / 16);
		count += print_hex(n % 16);
	}
	else
		count += write(1, &hex[n], 1);
	return (count);
}
