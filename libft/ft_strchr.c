/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:08:39 by diogo             #+#    #+#             */
/*   Updated: 2024/09/24 14:30:58 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main (void)
{
	const char	str[] = "catchulip1a";
	int	i = 't';
	printf("valor encontrado:%s\n",ft_strchr(str,i));
	i = '1';
	printf("valor encontrado:%s\n",ft_strchr(str,i));
}*/