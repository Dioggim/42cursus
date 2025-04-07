/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:50:50 by dgimenez          #+#    #+#             */
/*   Updated: 2024/11/30 00:42:09 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(const char **format, va_list args)
{
	int	count;

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
	va_list	args;
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
