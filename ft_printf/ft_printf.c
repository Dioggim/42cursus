/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:39:00 by dgimenez          #+#    #+#             */
/*   Updated: 2024/10/23 17:57:06 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

// Função para imprimir caracteres
static int	ft_print_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

// Função para imprimir strings
static int	ft_print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

// Função para imprimir ponteiros
static int	ft_print_ptr(va_list args)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	ft_putstr_fd("0x", 1);
	return (2 + ft_putnbr_base(ptr, "0123456789abcdef"));
}

// Função para imprimir números inteiros
static int	ft_print_nbr(va_list args, char format)
{
	int				n;
	unsigned int	un;

	if (format == 'd' || format == 'i')
	{
		n = va_arg(args, int);
		ft_putnbr_fd(n, 1);
		return (ft_numlen(n));
	}
	else if (format == 'u')
	{
		un = va_arg(args, unsigned int);
		ft_putnbr_fd(un, 1);
		return (ft_numlen_unsigned(un));
	}
	return (0);
}

// Função para imprimir números hexadecimais
static int	ft_print_hex(va_list args, char format)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (format == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
	return (0);
}

// Processa cada especificador de formato
static int	ft_process_format(va_list args, char format)
{
	if (format == 'c')
		return (ft_print_char(args));
	else if (format == 's')
		return (ft_print_str(args));
	else if (format == 'p')
		return (ft_print_ptr(args));
	else if (format == 'd' || format == 'i' || format == 'u')
		return (ft_print_nbr(args, format));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(args, format));
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

// Implementação principal do ft_printf
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			char_count += ft_process_format(args, format[i]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			char_count++;
		}
		i++;
	}
	va_end(args);
	return (char_count);
}
