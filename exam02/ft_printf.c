#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	digit_x_len(unsigned int digit)
{
	int	count;

	count = 1;
	while (digit / 16)
	{
		digit /= 16;
		count++;
	}
	return (count);
}

int	digit_len(int digit)
{
	int	count;

	count = 1;
	if (digit < 0)
	{
		count++;
		digit *= -1;
	}
	while (digit / 10)
	{
		digit /= 10;
		count++;
	}
	return (count);
}

int	ft_printf_s(va_list *arg, int width, int prec)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	if (!(str = va_arg(*arg, char *)))
		str = "(null)";
	count = 0;
	if (prec != -1)
	{
		if (prec > ft_strlen(str))
		{
			while (width-- > ft_strlen(str))
				count += write(1, " ", 1);
			count += write(1, str, ft_strlen(str));
			return (count);
		}
		while (width-- > prec)
			count += write(1, " ", 1);
		while (prec-- > 0)
		{
			count += write(1, &str[i], 1);
			i++;
		}
		return (count);
	}
	while (width-- > ft_strlen(str))
		count += write(1, " ", 1);
	count += write(1, str, ft_strlen(str));
	return (count);
}

int	ft_printf_hex(unsigned int digit)
{
	int	count;
	int	dig;

	count = 0;
	if (digit > 15)
		count += ft_printf_hex(digit / 16);
	dig = digit % 16 + 48;
	if (dig >= '0' && dig <= '9')
		count += ft_putchar(dig);
	else
		count += ft_putchar(dig + 39);
	return (count);
}

int	ft_printf_x(va_list *arg, int width, int prec)
{
	unsigned int	number;
	int				count;

	count = 0;
	number = va_arg(*arg, unsigned int);
	if (digit_x_len(number) >= prec)
	{
		while (width-- > digit_x_len(number))
			count += write(1, " ", 1);
		count += ft_printf_hex(number);
		return (count);
	}
	while (width-- > prec)
		count += write(1, " ", 1);
	while (digit_x_len(number) < prec--)
		count += write(1, "0", 1);
	count += ft_printf_hex(number);
	return (count);
}

int	ft_putnbr(int n)
{
	unsigned int	nbr;
	int	count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		nbr = -1 * n;
	}
	else
		nbr = n;
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + 48);
	return (count);
}

int	ft_printf_d(va_list *arg, int width, int prec)
{
	int	number;
	int	count;

	count = 0;
	number = va_arg(*arg, int);
	if ((number < 0 && prec < digit_len(number)) || (number >= 0 && prec <= digit_len(number)))
	{
		while (width-- > digit_len(number))
			count += write(1, " ", 1);
		count += ft_putnbr(number);
		return (count);
	}
	if (number < 0)
	{
		while (width-- > (prec + 1))
			count += write(1, " ", 1);
		count += write(1, "-", 1);
		while (prec-- > (digit_len(number) - 1))
			count += write(1, "0", 1);
		count += ft_putnbr(number * -1);
		return (count);
	}
	while (width-- > (prec + 1))
		count += write(1, " ", 1);
	while (prec-- > digit_len(number))
		count += write(1, "0", 1);
	count += ft_putnbr(number);
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		count;
	int		width;
	int		prec;
	int		i;

	count = 0;
	width = 0;
	prec = -1;
	i = 0;
	va_start(arg, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] != '.')
				while (string[i] >= '0' && string[i] <= '9')
				{
					width = width * 10 + string[i] - 48;
					i++;
				}
			if (string[i] == '.')
			{
				i++;
				prec = 0;
				if (string[i] >= '0' && string[i] <= '9')
					while (string[i] >= '0' && string[i] <= '9')
					{
						prec = prec * 10 + string[i] - 48;
						i++;
					}
			}
			if (string[i] == 's')
				count += ft_printf_s(&arg, width, prec);
			else if (string[i] == 'd')
				count += ft_printf_d(&arg, width, prec);
			else if (string[i] == 'x')
				count += ft_printf_x(&arg, width, prec);
			else
				break ;
			i++;
		}
		else if (string[i] != '\0')
		{
			count += write(1, &string[i], 1);
			i++;
		}
		else
			break ;
	}
	va_end(arg);
	return (count);
}

int	main()
{
	int i;
	int p;

	ft_printf("hello");
	printf("\nhello\n\n");

	ft_printf("%10.2s", "toto");
	printf("\n%10.2s\n\n", "toto");

	ft_printf("Magic %s is %5d", "number", 42);
	printf("\nMagic %s is %5d\n\n", "number", 42);

	i = ft_printf("Hexadecimal for %d is %x", 42, 42);
	p = printf("\nHexadecimal for %d is %x\n\n", 42, 42);

	ft_printf("%d", i);
	printf("\n%d\n\n", p);
	return (0);
}
