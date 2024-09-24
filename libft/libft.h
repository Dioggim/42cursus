/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:11:54 by diogo             #+#    #+#             */
/*   Updated: 2024/09/24 16:06:10 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>  // Inclui o cabeçalho necessário para 'size_t'

//int	ft_isalpha(int c);
//int	ft_isdigit(int c);
//int	ft_isalnum(int c);
//int	ft_isascii(int c);
//int	ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
//int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
//char *ft_strnstr(const char *haystack, const char *needle, size_t len);
//int ft_atoi(const char *str);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
//void *ft_memchr(const void *s, int c, size_t n);
//int ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
