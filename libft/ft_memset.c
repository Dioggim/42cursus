/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:52:07 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/26 12:29:48 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int newvalue, size_t rep)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)buffer;
	while (i < rep)
	{
		p[i] = (unsigned char)newvalue;
		i++;
	}
	return (buffer);
}
/*
int	main(void)
{
	char	buffer1[10];
	char	buffer2[10];
	size_t		i;

	// Inicializa os buffers com zeros
	memset(buffer1, 0, sizeof(buffer1));
	memset(buffer2, 0, sizeof(buffer2));

	// Aplica ft_memset e memset
	ft_memset(buffer1, 'a', sizeof(buffer1));
	memset(buffer2,'a', sizeof(buffer2));

	// Imprime os valores dos buffers
	printf("Resultado de ft_memset:\n");
	for (i = 0; i < sizeof(buffer1); i++)
	{
		printf("%02x ", (unsigned char)buffer1[i]);
	}
	printf("\n");

	printf("Resultado de memset:\n");
	for (i = 0; i < sizeof(buffer2); i++)
	{
		printf("%02x ", (unsigned char)buffer2[i]);
	}
	printf("\n");

	return (0);
}*/
