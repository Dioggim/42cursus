/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:23:31 by dgimenez          #+#    #+#             */
/*   Updated: 2024/11/30 00:41:06 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_pointer(va_list args)
{
	unsigned long	ptr;
	int				count;

	ptr = (unsigned long)va_arg(args, void *);
	ft_putstr("0x");
	ft_puthex(ptr, 'x');
	count = 2 + sizeof(ptr) * 2;
	return (count);
}

int	handle_int(va_list args)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	ft_putnbr(num);
	count = snprintf(NULL, 0, "%d", num);
	return (count);
}
