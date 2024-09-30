/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:10:49 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/28 21:35:23 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c) /* Ignora delimitadores consecutivos */
			i++;
		if (s[i] != '\0')
			count++; /* Conta uma palavra se não for o delimitador */
		while (s[i] != '\0' && s[i] != c) /* Avança até o próximo delimitador ou fim da string */
			i++;
	}
	return (count); /* Retorna o número de palavras */
}

static char	*ft_worddup(char const *s, int start, int end)
{
	char		*word;

	word = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, &s[start], end - start); /* Copia a palavra da string original */
	return (word); /* Retorna a nova palavra */
}

char		**ft_split(char const *s, char c)
{
	char		**result;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc((ft_wordcount(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c) /* Ignora delimitadores */
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c) /* Encontra o fim da palavra */
			i++;
		if (start < i)
		{
			result[j] = ft_worddup(s, start, i);
			if (!result[j])
			{
				while (j > 0) /* Limpa memória alocada em caso de falha */
					free(result[--j]);
				free(result);
				return (NULL);
			}
			j++;
		}
	}
	result[j] = NULL; /* Termina o array de strings com NULL */
	return (result);
}
/*
int		main(void)
{
	char		**result;
	int		i;

	result = ft_split("42  é uma  escola incrível!", ' ');
	if (!result)
		return (1);
	i = 0;
	while (result[i] != NULL)
	{
		printf("Palavra %d: %s\n", i, result[i]);
		free(result[i]); // Libera cada palavra
		i++;
	}
	free(result); // Libera o array de ponteiros
	return (0);
}*/
