/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:05:00 by dgimenez          #+#    #+#             */
/*   Updated: 2024/10/06 20:05:02 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_free_all(char **result, size_t j)
{
	while (j > 0)
	{
		free(result[j - 1]);
		j--;
	}
	free(result);
}

static int	ft_fill_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			result[j] = ft_substr(s, start, i - start);
			if (!result[j++])
				return (ft_free_all(result, j - 1), 0);
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
	result = (char **)ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_fill_words(result, s, c))
		return (NULL);
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
