/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:24:11 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/06/17 12:34:49 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(unsigned int nb, int base)
{
	char	*base_set = "0123456789abcdef";
	int	i = nb % base;
	int	cnt = 0;

	if (nb / base > 0)
		cnt += ft_putnbr(nb / base, base);
	cnt += ft_putchar(base_set[i]);
	return (cnt);
}

int	print_d(int nb)
{
	int	cnt = 0;

	if (nb < 0)
	{
		cnt += ft_putchar('-');
		if (nb == -2147483648)
		{
			cnt += ft_putstr("2147483648");
			return (cnt);
		}
		nb = -nb;
	}
	cnt += ft_putnbr((unsigned int)nb, 10);
	return (cnt);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int	cnt = 0;
	int	i = 0;

	if (str == NULL)
		return (0);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd')
				cnt += print_d(va_arg(ap, int));
			else if (str[i + 1] == 'x')
				cnt += ft_putnbr(va_arg(ap, unsigned int), 16);
			else if (str[i + 1] == 's')
				cnt += ft_putstr(va_arg(ap, char *));
			i++;
		}
		else
			cnt += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (cnt);
}

# include <stdio.h>

int	main(void)
{
	char	*str = NULL;
	printf("printf\nd > %d\nx > %x\ns > %s\nnull > %s\n\n", 123, 123, "hello", str);
	ft_printf("ft_printf\nd > %d\nx > %x\ns > %s\nnull > %s\n\n", 123, 123, "hello", str);
}
