/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:58:41 by diogo             #+#    #+#             */
/*   Updated: 2024/09/26 12:27:25 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main (void)
{
	const char	str[] = "ca1tchu1alip";
	int	i = 'a';
	printf("valor encontrado:%s\n",ft_strrchr(str,i));
	i = '\0';
	printf("valor encontrado:%s\n",ft_strrchr(str,i));
}*/
