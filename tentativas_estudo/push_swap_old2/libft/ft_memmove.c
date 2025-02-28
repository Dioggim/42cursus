/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:03:59 by dgimenez          #+#    #+#             */
/*   Updated: 2024/10/06 20:04:01 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (s < d && d < s + n)
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
	{
		while (n--)
			*d++ = *s++;
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
