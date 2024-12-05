/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:16 by dgimenez          #+#    #+#             */
/*   Updated: 2024/12/05 16:35:33 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buffer)
{
	char	*line;
	char	*remaining;
	char	*newline_pos;
	size_t	len;

	newline_pos = gnl_strchr(*buffer, '\n');
	if (!newline_pos)
	{
		line = gnl_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	len = newline_pos - *buffer + 1;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
		line[len] = (*buffer)[len];
	remaining = gnl_strdup(newline_pos + 1);
	free(*buffer);
	*buffer = remaining;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		temp[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!gnl_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp[bytes_read] = '\0';
		buffer = gnl_strjoin(buffer, temp);
	}
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (extract_line(&buffer));
}
