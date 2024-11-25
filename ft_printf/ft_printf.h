/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:17:31 by dgimenez          #+#    #+#             */
/*   Updated: 2024/10/14 13:17:34 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list args);
int		ft_print_str(va_list args);
int		ft_print_ptr(va_list args);
int		ft_print_nbr(va_list args, char format);
int		ft_print_hex(va_list args, char format);
int		ft_process_format(va_list args, char format);

#endif