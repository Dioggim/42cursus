/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:24:53 by dgimenez          #+#    #+#             */
/*   Updated: 2024/11/26 12:24:56 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_unsigned(va_list args)
{
	unsigned int num;
	int count;

	num = va_arg(args, unsigned int);
	ft_putunsigned(num);
	count = snprintf(NULL, 0, "%u", num);
	return (count);
}

int handle_hex(va_list args, char format)
{
	unsigned int num;
	int count;

	num = va_arg(args, unsigned int);
	ft_puthex(num, format);
	count = snprintf(NULL, 0, "%x", num);
	return (count);
}
