/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:33:38 by dgimenez          #+#    #+#             */
/*   Updated: 2024/12/04 23:55:19 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	size_t len = gnl_strlen(s);
	char *dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t len1 = gnl_strlen(s1);
	size_t len2 = gnl_strlen(s2);
	char *joined = malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	for (size_t i = 0; i < len1; i++)
		joined[i] = s1[i];
	for (size_t i = 0; i < len2; i++)
		joined[len1 + i] = s2[i];
	joined[len1 + len2] = '\0';
	free(s1);
	return (joined);
}