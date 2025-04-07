/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:03:31 by dgimenez          #+#    #+#             */
/*   Updated: 2024/10/03 13:35:16 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, &s1[start], end - start);
	return (trimmed);
}

/*
int	main(void)
{
	char	*s1 = " \t\nHello, World!\t\n ";
	char	*set = " \t\n";
	char	*result;

	result = ft_strtrim(s1, set);
	if (result) {
		printf("String original: '%s'\n", s1);
		printf("String ajustada: '%s'\n", result);
		free(result);
	} else {
		printf("Erro na alocação de memória.\n");
	}

	return 0;
}

** Explicação:
** 1. `is_in_set`: Verifica se um caractere está presente na string `set`.
** 2. `ft_strtrim`: Remove caracteres presentes em `set` do início e
do final de `s1`.
**    - Encontra `start` e `end`, que delimitam a parte útil de `s1`.
**    - Aloca memória suficiente para armazenar a string resultante.
**    - Copia os caracteres úteis e adiciona o caractere nulo.
** 3. `main`: Testa a função `ft_strtrim` com `s1` e `set` e imprime o resultado.
*/
