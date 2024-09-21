/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:33:11 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/20 13:33:11 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
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