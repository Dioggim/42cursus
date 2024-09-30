/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:10:49 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/30 22:29:06 by diogo            ###   ########.fr       */
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
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_worddup(char const *s, int start, int end)
{
	char	*word;

	word = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, &s[start], end - start);
	return (word);
}

static int	ft_fill_words(char **result, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (start < i)
		{
			result[j] = ft_worddup(s, start, i);
			if (!result[j])
				return (0);
			j++;
		}
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc((ft_wordcount(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_fill_words(result, s, c))
	{
		while (*result)
			free(*result++);
		free(result);
		return (NULL);
	}
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
