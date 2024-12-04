/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:34:00 by dgimenez          #+#    #+#             */
/*   Updated: 2024/12/04 23:47:27 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // Para malloc e free
# include <unistd.h> // Para read

// Tamanho do buffer de leitura
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Prototipagem da função principal
char	*get_next_line(int fd);

// Funções auxiliares
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(const char *s);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);

#endif
