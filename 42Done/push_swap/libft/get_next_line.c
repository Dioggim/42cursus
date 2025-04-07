/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:16 by dgimenez          #+#    #+#             */
/*   Updated: 2024/12/11 16:53:05 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	char	*remaining;

	if (!buffer || !*buffer)
		return (NULL);
	newline_pos = gnl_strchr(*buffer, '\n');
	if (!newline_pos)
		return (extract_remaining_line(buffer));
	line = allocate_line(buffer, newline_pos);
	if (!line)
		return (NULL);
	remaining = gnl_strdup(newline_pos + 1);
	free(*buffer);
	if (!remaining)
		return (free_and_nullify(buffer));
	*buffer = remaining;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp), free_and_nullify(&buffer));
		temp[bytes_read] = '\0';
		buffer = gnl_strjoin(buffer, temp);
		if (!buffer)
			return (free(temp), NULL);
	}
	free(temp);
	if (bytes_read == 0 && (!buffer || *buffer == '\0'))
		return (free_and_nullify(&buffer));
	return (extract_line(&buffer));
}

char	*free_and_nullify(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*extract_remaining_line(char **buffer)
{
	char	*line;

	if (!*buffer || **buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
		return (gnl_strdup(""));
	}
	line = gnl_strdup(*buffer);
	free(*buffer);
	*buffer = NULL;
	return (line);
}

char	*allocate_line(char **buffer, char *newline_pos)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = newline_pos - *buffer + 1;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[len] = '\0';
	i = 0;
	while (i < len)
	{
		line[i] = (*buffer)[i];
		i++;
	}
	return (line);
}
