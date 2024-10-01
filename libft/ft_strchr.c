/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:08:39 by diogo             #+#    #+#             */
/*   Updated: 2024/10/01 01:34:16 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
// Comentários:
// 1. O loop 'while (*s)' percorre cada caractere da string até encontrar '\0'.
// 2. O valor 'c' é convertido para 'char' 
// antes da comparação, pois ele é passado como 'int'.
// 3. Caso o valor seja encontrado, o 
//ponteiro para aquela posição na string é retornado.
// 4. Se 'c' for '\0', a função retorna o ponteiro para o final da string.
// 5. Caso o caractere não seja encontrado, a função retorna NULL.

/*
int	main (void)
{
	const char	str[] = "catchulip1a";
	int	i = 't';
	printf("valor encontrado:%s\n",ft_strchr(str,i));
	i = '1';
	printf("valor encontrado:%s\n",ft_strchr(str,i));
}*/