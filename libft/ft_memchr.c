/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:38:57 by diogo             #+#    #+#             */
/*   Updated: 2024/09/25 11:20:31 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*ptr;

	chr = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == chr)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	// Definimos um array de caracteres para ser nosso bloco de memória
	char str[] = "Hello, world!";
	
	// O caractere que queremos procurar (neste caso, 'w')
	char ch = 'w';
	
	// Usamos a função memchr para buscar a primeira ocorrência de 'w' 
	nos primeiros 13 bytes de str
	// O retorno será um ponteiro para a posição onde o 'w' foi 
	encontrado ou NULL se não for encontrado
	char *result = ft_memchr(str, ch, 13);
	
	// Verificamos se o caractere foi encontrado
	if (result != NULL)
		printf("O caractere '%c' 
		foi encontrado na posição: %ld\n",ch, result - str);
	else
		printf("O caractere '%c' não foi encontrado.\n", ch);

	return (0);
}*/
