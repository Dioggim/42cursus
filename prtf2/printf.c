/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:50:50 by dgimenez          #+#    #+#             */
/*   Updated: 2024/11/26 11:50:53 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_char(va_list args)
{
	char c;
	int count;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	count = 1;
	return (count);
}

static int	handle_string(va_list args)
{
	char *str;
	int count;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		count = 6;
	}
	else
	{
		ft_putstr(str);
		count = strlen(str);
	}
	return (count);
}

static int	handle_pointer(va_list args)
{
	unsigned long ptr;
	int count;

	ptr = (unsigned long)va_arg(args, void *);
	ft_putstr("0x");
	ft_puthex(ptr, 'x');
	count = 2 + sizeof(ptr) * 2;
	return (count);
}

static int	handle_int(va_list args)
{
	int num;
	int count;

	num = va_arg(args, int);
	ft_putnbr(num);
	count = snprintf(NULL, 0, "%d", num);
	return (count);
}

static int	handle_unsigned(va_list args)
{
	unsigned int num;
	int count;

	num = va_arg(args, unsigned int);
	ft_putunsigned(num);
	count = snprintf(NULL, 0, "%u", num);
	return (count);
}

static int	handle_hex(va_list args, char format)
{
	unsigned int num;
	int count;

	num = va_arg(args, unsigned int);
	ft_puthex(num, format);
	count = snprintf(NULL, 0, "%x", num);
	return (count);
}

static int	handle_format(const char **format, va_list args)
{
	int count;

	count = 0;
	if (**format == 'c')
		count = handle_char(args);
	else if (**format == 's')
		count = handle_string(args);
	else if (**format == 'p')
		count = handle_pointer(args);
	else if (**format == 'd' || **format == 'i')
		count = handle_int(args);
	else if (**format == 'u')
		count = handle_unsigned(args);
	else if (**format == 'x' || **format == 'X')
		count = handle_hex(args, **format);
	else if (**format == '%')
	{
		ft_putchar('%');
		count = 1;
	}
	(*format)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format(&format, args);
		}
		else
		{
			ft_putchar(*format);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
