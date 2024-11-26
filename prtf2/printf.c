#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*str;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);
				ft_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
				{
					ft_putstr("(null)");
					count += 6;
				}
				else
				{
					ft_putstr(str);
					count += strlen(str);
				}
			}
			else if (*format == 'p')
			{
				unsigned long ptr = (unsigned long)va_arg(args, void *);
				ft_putstr("0x");
				ft_puthex(ptr, 'x');
				count += 2 + sizeof(ptr) * 2;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				ft_putnbr(num);
				count += snprintf(NULL, 0, "%d", num);
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);
				ft_putunsigned(num);
				count += snprintf(NULL, 0, "%u", num);
			}
			else if (*format == 'x' || *format == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				ft_puthex(num, *format);
				count += snprintf(NULL, 0, "%x", num);
			}
			else if (*format == '%')
			{
				ft_putchar('%');
				count++;
			}
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
