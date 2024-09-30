/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:48 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/26 12:30:21 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int n)
{
	if ((n >= 0 && n <= 31) || (n == 127))
		return (0);
	return (1);
}
/*
int	main(void)
{
	printf("is it printable?: %d\n",ft_isprint('\t'));
}*/
