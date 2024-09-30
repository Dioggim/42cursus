/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:12:35 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/26 12:29:58 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (d > s && (d < (s + n)))
	{
		i = n - 1;
		while (i < n)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
int main()
{
	char str1[] = "Hello, World!";
	char str2[] = "Hello, World!";

	printf("String original: %s\n", str1);
	memmove(str1 + 7, str1 + 0, 6);
	printf("Resultado após memmove padrão: %s\n", str1);

	printf("String original: %s\n", str2);
	ft_memmove(str2 + 7, str2 + 0, 6);
	printf("Resultado após manual_memmove: %s\n", str2);

	if (strcmp(str1, str2) == 0)
	{
		printf("Os resultados de memmove e manual_memmove são iguais!\n");
	}
	else
	{
		printf("Os resultados de memmove e manual_memmove são diferentes!\n");
	}
	return 0;
}*/
