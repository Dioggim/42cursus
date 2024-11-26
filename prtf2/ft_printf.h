#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int     ft_printf(const char *format, ...);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int n);
void    ft_puthex(unsigned long num, char format);
void    ft_putunsigned(unsigned int n);

/* Protótipos das funções de manipulação de formatação */
int     handle_char(va_list args);
int     handle_string(va_list args);
int     handle_pointer(va_list args);
int     handle_int(va_list args);
int     handle_unsigned(va_list args);
int     handle_hex(va_list args, char format);
int     handle_format(const char **format, va_list args);

#endif
