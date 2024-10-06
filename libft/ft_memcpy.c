/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:03:50 by dgimenez          #+#    #+#             */
/*   Updated: 2024/10/06 20:03:52 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*
int main(void)
{
    char src[11] = "Hello 42!";
    char dest1[11];
    char dest2[11];

    // Aplica ft_memcpy e memcpy
    ft_memcpy(dest1, src, sizeof(src));
    memcpy(dest2, src, sizeof(src));

    // Imprime os valores dos buffers
    printf("Resultado de ft_memcpy: %s\n", dest1);
    printf("Resultado de memcpy: %s\n", dest2);

    return (0);
}*/
