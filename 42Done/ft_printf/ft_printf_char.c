/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:22:56 by dgimenez          #+#    #+#             */
/*   Updated: 2024/11/30 00:40:03 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int	handle_char(va_list args)
{
	char	c;
	int		count;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	count = 1;
	return (count);
}

int	handle_string(va_list args)
{
	char	*str;
	int		count;

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

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}
