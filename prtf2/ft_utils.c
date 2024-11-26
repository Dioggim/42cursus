#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putunsigned(unsigned int n)
{
	if (n >= 10)
		ft_putunsigned(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_puthex(unsigned long num, char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthex(num / 16, format);
	ft_putchar(base[num % 16]);
}