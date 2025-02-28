/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:08:26 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/26 12:30:32 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	buffer1[10];
	char	buffer2[10];
	size_t	i;

	// Preenche os buffers com dados não nulos
	memset(buffer1, 'a', sizeof(buffer1));
	memset(buffer2, 'a', sizeof(buffer2));

	// Aplica ft_bzero e bzero
	ft_bzero(buffer1, sizeof(buffer1));
	bzero(buffer2, sizeof(buffer2));

	// Imprime os valores dos buffers
	printf("Resultado de ft_bzero:\n");
	for (i = 0; i < sizeof(buffer1); i++)
	{
		printf("%02x ", (unsigned char)buffer1[i]);
	}
	printf("\n");

	printf("Resultado de bzero:\n");
	for (i = 0; i < sizeof(buffer2); i++)
	{
		printf("%02x ", (unsigned char)buffer2[i]);
	}
	printf("\n");

	return (0);
}*/
