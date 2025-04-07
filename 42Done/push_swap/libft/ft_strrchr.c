/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:58:41 by diogo             #+#    #+#             */
/*   Updated: 2024/10/01 01:48:32 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*last = NULL;
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			last = s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return ((char *)last);
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
