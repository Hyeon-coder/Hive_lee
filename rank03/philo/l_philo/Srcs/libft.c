/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:21:29 by tripham           #+#    #+#             */
/*   Updated: 2025/05/05 19:21:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			total;

	total = count * size;
	if (count && size && total / count != size)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (NULL);
	while (i < total)
	{
		ptr[i++] = 0;
	}
	return (ptr);
}

long	ft_atol(const char *s)
{
	int		i = 0;
	int		sign = 1;
	long	r = 0;

	if (!s)
		return (-1);
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	if (!ft_isdigit(s[i]))
		return (-1);
	while (ft_isdigit(s[i]))
	{
		if ((sign == 1 && r > (LONG_MAX - (s[i] - '0')) / 10)
			|| (sign == -1 && r > (-(LONG_MIN + (s[i] - '0'))) / 10))
			return (-1);
		r = r * 10 + (s[i++] - '0');
	}
	if (s[i] != '\0')
		return (-1);
	return (r * sign);
}
