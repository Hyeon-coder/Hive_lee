/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:26:20 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/12 01:58:52 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#define DECIMAL_BASE 10
#define HEXADECIMAL_BASE 16

static size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_put_string(char *str, int *len)
{
	size_t	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	*len += write(STDOUT_FILENO, str, str_len);
}

static void	ft_put_digit(uintmax_t num, int base, int *len, int is_signed)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (is_signed && (intmax_t)num < 0)
	{
		num = -(intmax_t)num;
		*len += write(STDOUT_FILENO, "-", sizeof(char));
	}
	if (num >= (uintmax_t)base)
		ft_put_digit((num / base), base, len, false);
	*len += write(STDOUT_FILENO, &hexa[num % base], sizeof(char));
}

static void	ft_handle_format(const char *format, va_list args, int *len)
{
	if (*format == '%')
		ft_put_string("%", len);
	else if (*format == 's')
		ft_put_string(va_arg(args, char *), len);
	else if (*format == 'd')
		ft_put_digit((intmax_t)va_arg(args, int), DECIMAL_BASE, len, true);
	else if (*format == 'x')
		ft_put_digit(va_arg(args, unsigned int), HEXADECIMAL_BASE, len, false);
}

int	ft_printf(const char *format, ... )
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			ft_handle_format(format, args, &len);
		}
		else
			len += write(STDOUT_FILENO, format, sizeof(char));
		format++;
	}
	va_end(args);
	return (len);
}
